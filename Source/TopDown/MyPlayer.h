// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

UCLASS()
class TOPDOWN_API AMyPlayer : public ACharacter
{
    GENERATED_BODY()
private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent* CameraBoom;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    class UCameraComponent* FollowCamera;

public:
    // Sets default values for this character's properties
    AMyPlayer();
public:
    UPROPERTY(VisibleAnywhere)
    bool bIsAttacking = false;
    UPROPERTY()
    class UCharacterAnim* CharacterAnim;

public:
    void Attack();
    void OnAttackHit(); // 추가

    UFUNCTION()
    void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
