// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "IAShooter.generated.h"

/**
 * 
 */
UCLASS()
class GD_SHOOTER_API AIAShooter : public AAIController
{
	GENERATED_BODY()
public:
	bool isDead() const;
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, Category=IA)
	UBehaviorTree* IAShooterBT;
};
