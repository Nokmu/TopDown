// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CharacterAnim.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
     // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;

    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f);
    GetCharacterMovement()->bConstrainToPlane = true;
    GetCharacterMovement()->bSnapToPlaneAtStart = true;


    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->SetUsingAbsoluteRotation(true);
    CameraBoom->TargetArmLength = 800.0f;
    CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
    CameraBoom->bDoCollisionTest = false;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
    Super::BeginPlay();

    CharacterAnim = Cast<UCharacterAnim>(GetMesh()->GetAnimInstance());
    CharacterAnim->OnMontageEnded.AddDynamic(this, &AMyPlayer::OnAttackMontageEnded);
    CharacterAnim->OnAttackHit.AddUObject(this, &AMyPlayer::OnAttackHit); //추가
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyPlayer::Attack()
{
    if (bIsAttacking)
        return;

    CharacterAnim->PlayAttackMontage();

    bIsAttacking = true;
}

void AMyPlayer::OnAttackHit()
{
    UE_LOG(LogTemp, Log, TEXT("Hit"));
    //캡슐 컬라이더 만들어서 사정거리 안에 있는지 체크 하고 데미지 주기
}
                                                  
void AMyPlayer::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
    bIsAttacking = false;

}
