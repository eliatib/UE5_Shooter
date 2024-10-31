// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"

#include "AIController.h"
#include "ShooterCharacter.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = "Shoot Task";
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	AShooterCharacter* Pawn = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	if(Pawn == nullptr) return EBTNodeResult::Failed;

	Pawn->Shoot();
	
	return EBTNodeResult::Succeeded;
}
