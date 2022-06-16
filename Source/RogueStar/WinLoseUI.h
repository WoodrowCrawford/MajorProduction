#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "TimerManager.h"
#include "Components/Image.h"
#include "Blueprint/UserWidget.h"
#include "RogueStarCharacter.h"
#include "Components/TextBlock.h"
#include "WinLoseUI.generated.h"

/**
 * 
 */
UCLASS()
class ROGUESTAR_API UWinLoseUI : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void WinTextVisibility(ARogueStarCharacter* Player, UTextBlock* WinText, UTextBlock* LoseText, UImage* Background, UButton* RestartButton, UButton* QuitButton, UButton* RefocusButton);

	UFUNCTION(BlueprintCallable)
	void EscapeTextVisibility(ARogueStarCharacter* Player, UTextBlock* EscapeText);

	UFUNCTION(BlueprintCallable)
	bool WinLoseMenuSetup(APlayerController* PlayerController, class UPauseMenuUI* PauseMenuUI);

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool DidWin = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool DidLose = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool DidFocus = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool FocusedOnce = false;
};
