// Copyright Epic Games, Inc. All Rights Reserved.


#include "RogueStarGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "MenuPlayerController.h"
#include "PlayerHUD.h"


ARogueStarGameModeBase::ARogueStarGameModeBase()
{
	static ConstructorHelpers::FClassFinder<ARogueStarCharacter>;/* PlayerCharacterFinder(TEXT("/Game/RogueStar/C++ Classes/RogueStarCharacter"));
	DefaultPawnClass = PlayerCharacterFinder.Class;*/
	
	Player = Cast<ARogueStarCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = APlayerHUD::StaticClass();
}