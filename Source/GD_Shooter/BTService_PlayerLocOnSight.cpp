// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocOnSight.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTService_PlayerLocOnSight::UBTService_PlayerLocOnSight()
{
	NodeName = "Update Player Loc On Sight";
}

void UBTService_PlayerLocOnSight::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(),0);

	if(Player == nullptr) return;

	if(OwnerComp.GetAIOwner() == nullptr) return;
	
	if(OwnerComp.GetAIOwner()->LineOfSightTo(Player))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(),Player);
	
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
}
