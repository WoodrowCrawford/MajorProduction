// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPatrolAi.h"

// Sets default values
AEnemyPatrolAi::AEnemyPatrolAi()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyPatrolAi::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyPatrolAi::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckForPlayer();
}

void AEnemyPatrolAi::CheckForPlayer()
{
	UE_LOG(LogTemp, Warning, TEXT("CheckForPlayer is being checked\n"));

	//to linetrace, got the start and end traces
	/*FVector StartTrace = Enemy->GetActorLocation();
	FVector EndTrace = StartTrace + Enemy->GetActorForwardVector() + Reach;*/

	//Declare a hitresult to store the raycast to hit in
	/*FHitResult HitResult;*/
}

