// Fill out your copyright notice in the Description page of Project Settings.


#include "KillThemAllGameMode.h"

#include "EngineUtils.h"
#include "IAShooter.h"

void AKillThemAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if(PlayerController != nullptr)
	{
		EndGame(false);
	}
	
	for(AIAShooter* IAController : TActorRange<AIAShooter>(GetWorld()))
	{
		if(!IAController->isDead())
		{
			return;
		}
	}
	EndGame(true);

}

void AKillThemAllGameMode::EndGame(bool bPlayerWin)
{
	for(AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bPlayerWin;
		Controller->GameHasEnded(Controller->GetPawn(),bIsWinner);
	}
}
