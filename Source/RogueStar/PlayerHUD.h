// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class ROGUESTAR_API APlayerHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	TSharedPtr<class SPauseMenuWidget> PauseWidget;
	TSharedPtr<class SWidget> PauseWidgetContainer;

	virtual void BeginPlay() override;

public:

	void ShowMenu();
	void RemoveMenu();
};
