// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

#include "ShooterCharacter.h"
#include "Engine/DamageEvents.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Scenecomp = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = Scenecomp;
	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun Mesh"));
	GunMesh->SetupAttachment(RootComponent);
}

void AGun::Shoot()
{
	UGameplayStatics::SpawnEmitterAttached(FireFlash,GunMesh,TEXT("MuzzleFlashSocket"));
	UGameplayStatics::SpawnSoundAttached(FireSound,GunMesh,TEXT("MuzzleFlashSocket"));
	
	FHitResult Hit;
	FVector Direction;
	if(GunTrace(Hit,Direction))
	{
		
		UGameplayStatics::SpawnEmitterAtLocation(this,Impact,Hit.Location, Direction.Rotation());
		UGameplayStatics::SpawnSoundAtLocation(this,HitSound,Hit.Location, Direction.Rotation());
		
		AActor* ShootActor = Hit.GetActor();
		if(ShootActor != nullptr)
		{
			FPointDamageEvent DamageE(Damage,Hit,Direction,nullptr);
			AController* OC = GetOwnerController();
			if(OC == nullptr) return;
			ShootActor->TakeDamage(Damage,DamageE,OC,this);
		}
	}
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AGun::GunTrace(FHitResult& Hit, FVector& ShotDirection)
{
	AController* OC = GetOwnerController();
	if(OC == nullptr) return false;
	FVector CamLoc;
	FRotator CamRot;
	OC->GetPlayerViewPoint(CamLoc,CamRot);
	FVector End = CamLoc + CamRot.Vector() * MaxRange;
	ShotDirection = - CamRot.Vector();
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	return GetWorld()->LineTraceSingleByChannel(Hit,CamLoc,End,TraceChannelProperty, Params);
}

AController* AGun::GetOwnerController() const
{
	APawn* OwnerGun =  Cast<AShooterCharacter>(GetOwner());
	if(OwnerGun == nullptr) return nullptr;
	AController* OC = OwnerGun->GetController();
	return OC;
}

