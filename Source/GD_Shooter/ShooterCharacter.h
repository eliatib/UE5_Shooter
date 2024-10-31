// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class UInputAction;

UCLASS()
class GD_SHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Shoot Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* ShootAction;	

public:
	// Sets default values for this character's properties
	AShooterCharacter();

	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;
	
	/** Called for movement input */
	void Shoot();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	
	/** Called for movement input */
	void Move(const FInputActionValue& Value);


	
	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void SwitchCameraPoint();

private:
	UPROPERTY(EditAnywhere,Category="Elements")
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere,Category="Elements")
	class UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly,Category="Elements")
	TSubclassOf<class AGun> GunClass;

	UPROPERTY(EditDefaultsOnly,Category="Elements")
	AGun* Gun;

	UPROPERTY(EditAnywhere)
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere)
	float CHealth = 0.f;

public:
	UFUNCTION(BlueprintCallable)
	float GetHealth() const;


private:
	bool isTPS = true;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
