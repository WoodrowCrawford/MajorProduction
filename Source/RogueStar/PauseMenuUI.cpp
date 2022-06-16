// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenuUI.h"

void UPauseMenuUI::MenuVisibility(UCanvasPanel* PauseMenu)
{
	if (IsGamePaused)
	{
		PauseMenu->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		PauseMenu->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UPauseMenuUI::PauseMenuSetup(APlayerController* PlayerController, UWinLoseUI* WinLoseUI)
{
	if (!WinLoseUI->DidWin || !WinLoseUI->DidLose)
	{
		IsGamePaused = true;
		FInputModeUIOnly InputMode;
		PlayerController->SetInputMode(InputMode);
		PlayerController->bShowMouseCursor = true;
	}
}