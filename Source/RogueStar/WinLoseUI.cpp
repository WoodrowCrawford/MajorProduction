// Fill out your copyright notice in the Description page of Project Settings.


#include "WinLoseUI.h"
#include "PauseMenuUI.h"
#include "Components/SlateWrapperTypes.h"

void UWinLoseUI::WinTextVisibility(ARogueStarCharacter* Player, UTextBlock* WinText, UTextBlock* LoseText, UImage* Background, UButton* RestartButton, UButton* QuitButton, UButton* RefocusButton)
{
	if (!DidLose)
	{
		if (Player->CanExit)
		{
			DidWin = true;
			WinText->SetVisibility(ESlateVisibility::Visible);
			RestartButton->SetVisibility(ESlateVisibility::Visible);
			QuitButton->SetVisibility(ESlateVisibility::Visible);
			RefocusButton->SetVisibility(ESlateVisibility::Visible);
			Background->SetVisibility(ESlateVisibility::Visible);
			LoseText->SetVisibility(ESlateVisibility::Hidden);
		}
		else
		{
			WinText->SetVisibility(ESlateVisibility::Hidden);
			RestartButton->SetVisibility(ESlateVisibility::Hidden);
			QuitButton->SetVisibility(ESlateVisibility::Hidden);
			RefocusButton->SetVisibility(ESlateVisibility::Hidden);
			Background->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	if(!DidWin)
	{
		if (Player->DetectedValue >= 1.0f || DidLose)
		{
			DidLose = true;
			LoseText->SetVisibility(ESlateVisibility::Visible);
			RestartButton->SetVisibility(ESlateVisibility::Visible);
			QuitButton->SetVisibility(ESlateVisibility::Visible);
			RefocusButton->SetVisibility(ESlateVisibility::Visible);
			Background->SetVisibility(ESlateVisibility::Visible);
			WinText->SetVisibility(ESlateVisibility::Hidden);
		}
		else
		{
			LoseText->SetVisibility(ESlateVisibility::Hidden);
			RestartButton->SetVisibility(ESlateVisibility::Hidden);
			QuitButton->SetVisibility(ESlateVisibility::Hidden);
			RefocusButton->SetVisibility(ESlateVisibility::Hidden);
			Background->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void UWinLoseUI::EscapeTextVisibility(ARogueStarCharacter* Player, UTextBlock* EscapeText)
{
	if (Player->GetCollectiblesHeld() >= Player->CollectiblesNeeded)
	{
		EscapeText->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		EscapeText->SetVisibility(ESlateVisibility::Hidden);
	}
}

bool UWinLoseUI::WinLoseMenuSetup(APlayerController* PlayerController, UPauseMenuUI* PauseMenuUI)
{
	if (!PauseMenuUI->IsGamePaused)
	{
		if (DidWin || DidLose)
		{
			if (!FocusedOnce)
			{
				DidFocus = true;
				FocusedOnce = true;
				FInputModeUIOnly InputMode;
				PlayerController->SetInputMode(InputMode);
				PlayerController->bShowMouseCursor = true;

				//FTimerManager Timer;
				//FTimerHandle THandle;
				//Timer.SetTimer(THandle,, 1.0f, false, 0.1f);
			}
			else if (FocusedOnce)
			{
				DidFocus = false;
			}
		}
	}

	return DidFocus;
}
