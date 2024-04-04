// Copyright Epic Games, Inc. All Rights Reserved.


#include "MineCraftPlayerController.h"
#include "EnhancedInputSubsystems.h"

AMineCraftPlayerController::AMineCraftPlayerController()
{
}

void AMineCraftPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);

		UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));
	}
}