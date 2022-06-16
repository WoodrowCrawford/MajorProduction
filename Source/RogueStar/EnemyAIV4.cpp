// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIV4.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UEnemyAIV4::UEnemyAIV4()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Reach = 500.0f;
}


// Called when the game starts
void UEnemyAIV4::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UEnemyAIV4::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CheckForPlayer();
}

void UEnemyAIV4::CheckForPlayer()
{
	UE_LOG(LogTemp, Warning, TEXT("Check for player started\n"));

	FVector start = GetComponentLocation();
	FVector end = start + GetForwardVector() * Reach;

	//Declare a hitresult to store the raycast to hit in
	FHitResult OutHit;

	//Initializes the query params - Ignore the actor
	FCollisionQueryParams collisionQP;

	collisionQP.AddIgnoredActor(GetOwner()); //add this if it hits the enemy from inside but move scene component out first as a test

	DrawDebugLine(GetWorld(), start, end, FColor::Red, false, 0);

	//cast the line trace
	if (GetWorld()->LineTraceSingleByChannel(OutHit, start, end, ECC_Visibility, collisionQP))
	{
		if (ARogueStarCharacter* Player = Cast<ARogueStarCharacter>(OutHit.GetActor()))
		{
			//SetPlayerMeter += StealthCompromised;
			UE_LOG(LogTemp, Warning, TEXT("Player InSight\n"));
			return;
		}
		else
		{
			//SetPlayerMeter -= StealthCompromised/2;
			UE_LOG(LogTemp, Warning, TEXT("Player is not in sight\n"));
			return;
		}
	}

	if (GetWorld() == NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("There is no world\n"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Didn't get to GetWorld\n"));
	return;
}

