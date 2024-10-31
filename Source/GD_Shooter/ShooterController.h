// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterController.generated.h"

/**
 * 
 */
UCLASS()
class GD_SHOOTER_API AShooterController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void GameHasEnded(AActor* EndGameFocus, bool bIsWinner) override;
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere)
	float RestartDelay = 5.f;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LoseUI;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> WinUI;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;

	UPROPERTY()
	UUserWidget* HUD;
	FTimerHandle RestartTimer;
};
