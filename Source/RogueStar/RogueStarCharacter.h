// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RogueStarCharacter.generated.h"

UCLASS()
class ROGUESTAR_API ARogueStarCharacter : public ACharacter
{

	GENERATED_BODY()

		/** Camera boom positioning the camera behind the character */
		//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		//class USpringArmComponent* CameraBoom;

	/** Follow camera */
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		//class UCameraComponent* FollowCamera;


public:
	ARogueStarCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	/** Value determinds if the game will end **/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float DetectedValue;

	/** Amount of Collectibles needed to complete the level. **/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float CollectiblesNeeded;

	/** Amount of Collectibels collected. **/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CollectiblesHeld;

	/** If true, the player can exit the level **/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool CanExit;

protected:


	//Called for forwards/backward input
	//void MoveForward(float Value);

	//Called for side to side input
	//void MoveRight(float Value);


	//Called via input to turn at a given rate. 
	void TurnAtRate(float Rate);


	//Called via input to turn look up/down at a given rate. 
	void LookUpAtRate(float Rate);




protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	//FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	//FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	/** Use to tell the player how to interact with certain objects on an overlap collision **/
	UFUNCTION()
	void PlayerInteraction(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
	float GetCollectiblesHeld() const { return CollectiblesHeld; }
};
