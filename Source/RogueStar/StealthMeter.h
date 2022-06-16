// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StealthMeter.generated.h"

/**
 * 
 */
UCLASS()
class ROGUESTAR_API UStealthMeter : public UUserWidget
{
	GENERATED_BODY()

//Used for values
public:

	//The value of how much the enemy spotted you. When it reaches the Max stealth bar value it's game over
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Detection Values")
		float DectectionValue = 0.0f;

	//THe max value of the stealth bar meter
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Detection Values")
		float MaxStealthBarValue = 100.0f;
	
	//A boolean used to determine if the stealth bar meter is filled
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Detection Values")
		bool isMeterFilled = false;


//Used for functions
public:
	
	//A function that ends the game whenever the stealth meter is filled
	UFUNCTION(BlueprintCallable, Category = "Stealth Functions")
	void StealthMeterFilled();

};
