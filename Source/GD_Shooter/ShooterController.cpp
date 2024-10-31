// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterController.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void AShooterController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
	if(HUD != nullptr)
	{
		HUD->RemoveFromParent();
	}
	if(bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this,WinUI,"Lose Widget");
		if(WinScreen != nullptr)
		{
			WinScreen->AddToViewport();
		}	
	}
	else
	{
		UUserWidget* LoseScreen = CreateWidget(this,LoseUI,"Lose Widget");
		if(LoseScreen != nullptr)
		{
			LoseScreen->AddToViewport();
		}
	}
	GetWorldTimerManager().SetTimer(RestartTimer,this,&APlayerController::RestartLevel,RestartDelay);

}

void AShooterController::BeginPlay()
{
	Super::BeginPlay();
	HUD = CreateWidget(this,HUDClass,"HUD Widget");
	if(HUD != nullptr)
	{
		HUD->AddToViewport();
	}	
}


