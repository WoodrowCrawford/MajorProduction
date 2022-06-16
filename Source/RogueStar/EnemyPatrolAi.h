// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyPatrolAi.generated.h"

UCLASS()
class ROGUESTAR_API AEnemyPatrolAi : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyPatrolAi();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CheckForPlayer();


private:
	AActor* Enemy;

public:
	//Player
	//ACharacterCode* Player;

	float Reach;
	float StealthCompromised;
};
