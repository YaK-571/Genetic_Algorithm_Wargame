// Copyright Epic Games, Inc. All Rights Reserved.

#include "WargameGameMode.h"
#include "WargameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWargameGameMode::AWargameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
