// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RogueStarCharacter.h"
#include "RogueStarGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class ROGUESTAR_API ARogueStarGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	ARogueStarGameModeBase();

public:
	
	ARogueStarCharacter* Player;

	ARogueStarCharacter* ReturnPlayer() { return Player; }
};
