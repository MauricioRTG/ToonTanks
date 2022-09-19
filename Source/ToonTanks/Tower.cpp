// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Find distance to the tank
	if (Tank)
	{
		float Distance = FVector::Distance(GetActorLocation(), Tank->GetActorLocation());

		if (Distance <= FireRange)
		{
			RotateTorret(Tank->GetActorLocation());
		}
	}
	
}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
