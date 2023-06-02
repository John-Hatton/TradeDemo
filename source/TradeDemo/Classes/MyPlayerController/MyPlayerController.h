// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * The MyPlayerController class implements some of the UI components of the Player's experience on screen.
 */
UCLASS()
class TRADEDEMO_API AMyPlayerController: public APlayerController
{
	GENERATED_BODY()


public:

	AMyPlayerController();


protected:
	virtual void BeginPlay() override;
	
private:

	/** Reference to the Overall HUD overlay Blueprint Class **/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> HUDOverlayClass;

	/** Variable to hold the HUDOverlay Widget, after creating it **/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Widgets, meta = (AllowPrivateAccess = "true"))
	UUserWidget* HUDOverlay;
};