// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectibleTestCharacter.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ACollectibleTestCharacter::ACollectibleTestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACollectibleTestCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ACollectibleTestCharacter::PickupCollectible);
}

// Called every frame
void ACollectibleTestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACollectibleTestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//Checks if the object that enters the Collider is a collectible, and if so, increases CollectiblesHeld.
void ACollectibleTestCharacter::PickupCollectible(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetRootComponent()->ComponentHasTag("Collectible"))
	{
		CollectiblesHeld++;
	}
}

float ACollectibleTestCharacter::GetCollectiblesHeld()
{
	return CollectiblesHeld;
}

