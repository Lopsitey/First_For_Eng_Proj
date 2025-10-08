// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "MyTwinStickController.generated.h"

/**
 * 
 */
UCLASS()
class FIRST_FOR_ENG_PROJ_API AMyTwinStickController : public APlayerController
{
	GENERATED_BODY()
	
	protected:
		virtual void BeginPlay() override;
		void SetInputMappingContext();
		UPROPERTY(EditDefaultsOnly)
		UInputMappingContext* MappingContext;
	
	
};
