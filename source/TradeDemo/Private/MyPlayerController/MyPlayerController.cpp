// MyPlayerController.cpp

#include "TradeDemo/Classes/MyPlayerController/MyPlayerController.h"
#include "Blueprint/UserWidget.h"

AMyPlayerController::AMyPlayerController()
{
	// Ensuring that the HUDOverlayClass is set to nullptr at start
	HUDOverlayClass = nullptr;

	// Ensuring that the HUDOverlay widget is set to nullptr at start
	HUDOverlay = nullptr;
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Check if the HUDOverlayClass is set in the blueprint
	if (HUDOverlayClass)
	{
		// Create the HUDOverlay widget
		HUDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayClass);

		// Check if the HUDOverlay widget was created successfully
		if (HUDOverlay)
		{
			// Add the HUDOverlay widget to the viewport
			HUDOverlay->AddToViewport();
			HUDOverlay->SetVisibility(ESlateVisibility::Visible);
		}
	}
}
