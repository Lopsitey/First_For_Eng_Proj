// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTwinStickPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"


// Sets default values
AMyTwinStickPawn::AMyTwinStickPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SetRootComponent(SphereCollision);
	SphereCollision->InitSphereRadius(100.0f);
	SphereCollision->SetCollisionObjectType(ECC_Pawn);
	SphereCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SphereCollision->SetCollisionResponseToChannel(ECC_Visibility,ECR_Ignore);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SphereCollision);
	StaticMesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(SphereCollision);
	SpringArm->SetRelativeRotation(FRotator(-60.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 2200.0f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 0.5f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	MovementComp = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingMovementComp"));
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

void AMyTwinStickPawn::DoMove(FVector2D Input)
{
	// Store the last move input as a direction vector for dashing
	LastMoveInput.X = Input.X;
	LastMoveInput.Y = Input.Y;

	FRotator MoveDirection = FRotator(0.0f, GetControlRotation().Yaw, GetControlRotation().Roll);
	GetMovementComponent()->AddInputVector(MoveDirection.RotateVector(FVector::ForwardVector) * Input.X);
	GetMovementComponent()->AddInputVector(MoveDirection.RotateVector(FVector::RightVector) * Input.Y);
}

void AMyTwinStickPawn::DoDash(bool Input)//if this was a UFUNCTION(BlueprintNativeevent) it would need to be called DoDash_Implementation
{
	if (Input)
	{
		DashDirection = LastMoveInput;
		GetMovementComponent()->Velocity = FVector(DashDirection * DashImpulse,0.0f);
	}
}