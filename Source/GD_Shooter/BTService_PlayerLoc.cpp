// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLoc.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTService_PlayerLoc::UBTService_PlayerLoc()
{
	NodeName = "Update PlayerLoc";
}

void UBTService_PlayerLoc::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	if(Player == nullptr) return;
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),Player->GetActorLocation());
}
