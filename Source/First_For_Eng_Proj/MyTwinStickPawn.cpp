// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTwinStickPawn.h"

#include "GameFramework/PawnMovementComponent.h"


// Sets default values
AMyTwinStickPawn::AMyTwinStickPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyTwinStickPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTwinStickPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyTwinStickPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMyTwinStickPawn::DoMove_Implementation(FVector2D Input)
{
	// Store the last move input as a direction vector for dashing
	LastMoveInput = FVector(Input.X, Input.Y, 0.0f);

	FRotator MoveDirection = FRotator(0.0f, GetControlRotation().Yaw, GetControlRotation().Roll);
	GetMovementComponent()->AddInputVector(MoveDirection.RotateVector(FVector::ForwardVector) * Input.X);
	GetMovementComponent()->AddInputVector(MoveDirection.RotateVector(FVector::RightVector) * Input.Y);
}

void AMyTwinStickPawn::DoDash_Implementation(bool Input)
{
	if (Input)
	{
		float DashImpulse = 2500.0f;
		FVector DashDirection = LastMoveInput;
		GetMovementComponent()->Velocity = DashDirection * DashImpulse;
	}
}