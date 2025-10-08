// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTwinStickController.h"

void AMyTwinStickController::BeginPlay()
{
    Super::BeginPlay();
    // Additional logic if needed
}

void AMyTwinStickController::SetInputMappingContext()
{
	Super::SetupInputComponent();
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		Subsystem->AddMappingContext(MappingContext, 0);
		
}

