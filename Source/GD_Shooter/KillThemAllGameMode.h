// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterGameModeBase.h"
#include "KillThemAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class GD_SHOOTER_API AKillThemAllGameMode : public AShooterGameModeBase
{
	GENERATED_BODY()
public:
	virtual void PawnKilled(APawn* PawnKilled) override;
private:
	void EndGame(bool bPlayerWin);
};
