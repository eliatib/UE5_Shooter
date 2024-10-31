// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class GD_SHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();
	void Shoot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere,Category=component)
	class USceneComponent* Scenecomp;
	
	UPROPERTY(EditAnywhere,Category=component)
	class USkeletalMeshComponent* GunMesh;
	
	UPROPERTY(EditAnywhere,Category=FX)
	class UParticleSystem* FireFlash;

	UPROPERTY(EditAnywhere, Category=FX)
	UParticleSystem* Impact;

	UPROPERTY(EditAnywhere,Category=FX)
	class USoundBase* FireSound;

	UPROPERTY(EditAnywhere,Category=FX)
	class USoundBase* HitSound;
	
	UPROPERTY(EditAnywhere, Category="Collision")
	TEnumAsByte<ECollisionChannel> TraceChannelProperty = ECC_Pawn;
	
	UPROPERTY(EditAnywhere)
	float MaxRange = 1000.f;

	UPROPERTY(EditAnywhere)
	float Damage = 10.f;

	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);

	AController* GetOwnerController() const;
};
