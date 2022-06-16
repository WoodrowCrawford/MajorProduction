// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"
#include "PlayerHUD.h"

AMenuPlayerController::AMenuPlayerController()
{

}

void AMenuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent)
	{
		InputComponent->BindAction("Pause Game", IE_Pressed, this, &AMenuPlayerController::OpenMenu);
	}
}

void AMenuPlayerController::OpenMenu()
{
	if(APlayerHUD* PlayerHUD = Cast<APlayerHUD>(GetHUD()))
	{
		PlayerHUD->ShowMenu();
	}
}
