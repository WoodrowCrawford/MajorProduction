// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 *
 */
class ROGUESTAR_API SPauseMenuWidget :public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SPauseMenuWidget) {}

	SLATE_ARGUMENT(TWeakObjectPtr<class APlayerHUD>, OwningHUD)

	SLATE_END_ARGS()

	//Every widget needs a construction function
	void Construct(const FArguments& InArgs);

	FReply OnResumeClicked() const;
	FReply OnQuitClicked() const;

	//The HUD that creates this widget
	TWeakObjectPtr<class APlayerHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; }
};
