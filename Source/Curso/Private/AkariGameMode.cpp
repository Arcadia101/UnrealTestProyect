// Fill out your copyright notice in the Description page of Project Settings.


#include "Curso/Public/AkariGameMode.h"

AAkariGameMode::AAkariGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClass(TEXT("/Game/Blueprints/BP_PlayerCharacter"));
	if (PlayerPawnClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnClass.Class;
	}
}
