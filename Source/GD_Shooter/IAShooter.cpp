// Fill out your copyright notice in the Description page of Project Settings.


#include "IAShooter.h"

#include "ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

bool AIAShooter::isDead() const
{
	AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
	if(ControlledCharacter != nullptr)
	{
		return ControlledCharacter->IsDead();
	}

	return true;
}

void AIAShooter::BeginPlay()
{
	Super::BeginPlay();
	if(IAShooterBT != nullptr)
	{
		APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(),0);	
		RunBehaviorTree(IAShooterBT);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLoc"),GetPawn()->GetActorLocation());
		
	}
}

void AIAShooter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	


}
