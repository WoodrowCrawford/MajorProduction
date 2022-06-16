// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIV2.h"
#include "DrawDebugHelpers.h"

// Sets default values
AEnemyAIV2::AEnemyAIV2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Reach = 200;
}

// Called when the game starts or when spawned
void AEnemyAIV2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyAIV2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckForPlayer();

	UE_LOG(LogTemp, Warning, TEXT("Tick is ticking properly\n"));
}

void AEnemyAIV2::CheckForPlayer()
{
	UE_LOG(LogTemp, Warning, TEXT("Check for player started\n"));

	FVector start = GetActorLocation();
	FVector end = start + GetActorForwardVector() * Reach;

	//Declare a hitresult to store the raycast to hit in
	FHitResult OutHit;

	//Initializes the query params - Ignore the actor
	FCollisionQueryParams collisionQP;

	collisionQP.AddIgnoredActor(this);

	DrawDebugLine(GetWorld(), start, end, FColor::Red, false, 0);

	//cast the lime trace
	if (GetWorld()->LineTraceSingleByChannel(OutHit, start, end, ECC_Visibility, collisionQP))
	{
		//if(ThePlayersCode* Player = Cast<ThePlayersCode>(HistResult.GetActor())) replace GetActor with GetCharacter if that doesnt work
			//SetPlayerMeter += StealthCompromised;
			//GLog->Log("player in sight\n");
			//return;

		UE_LOG(LogTemp, Warning, TEXT("Check happened but player was not in sight\n"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("world trace did not work\n"));
	return;
}

