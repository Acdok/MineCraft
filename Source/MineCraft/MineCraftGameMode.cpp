// Copyright Epic Games, Inc. All Rights Reserved.

#include "MineCraftGameMode.h"
#include "MineCraftCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMineCraftGameMode::AMineCraftGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
