// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WinLoseUI.h"
#include "TimerManager.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "PauseMenuUI.generated.h"

/**
 * 
 */
UCLASS()
class ROGUESTAR_API UPauseMenuUI : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void MenuVisibility(UCanvasPanel* PauseMenu);

	UFUNCTION(BlueprintCallable)
	void PauseMenuSetup(APlayerController* PlayerController, UWinLoseUI* WinLoseUI);

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsGamePaused;
	
};
