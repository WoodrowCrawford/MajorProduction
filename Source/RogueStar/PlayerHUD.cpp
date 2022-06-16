// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "SPauseMenuWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"
#include "GameFramework/HUD.h"
#include "GameFramework/PlayerController.h"

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerHUD::ShowMenu()
{
	if (GEngine && GEngine->GameViewport)
	{
		PauseWidget = SNew(SPauseMenuWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(PauseWidgetContainer, SWeakWidget).PossiblyNullContent(PauseWidget.ToSharedRef()));

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

void APlayerHUD::RemoveMenu()
{
	if (GEngine && GEngine->GameViewport && PauseWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(PauseWidgetContainer.ToSharedRef());

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}
