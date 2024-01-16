// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputConfig.h"
#include "UnitStats.h"


// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComp->SetupAttachment(GetRootComponent());

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComp->SetupAttachment(SpringArmComp);

	Stats = CreateDefaultSubobject<UUnitStats>(TEXT("Unit Stats"));

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	
	// Get player subsystem
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	// Clear input mappings
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);
	// Get enhanced input system
	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	// Bind the actions
	EnhancedInput->BindAction(InputActions->InputMove, ETriggerEvent::Triggered, this, &AMainCharacter::Move);
	EnhancedInput->BindAction(InputActions->InputLook, ETriggerEvent::Triggered, this, &AMainCharacter::Look);
	EnhancedInput->BindAction(InputActions->InputZoom, ETriggerEvent::Triggered, this, &AMainCharacter::Zoom);
}

void AMainCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MoveValue = Value.Get<FVector2D>();
	FRotator MoveRotation(0, Controller->GetControlRotation().Yaw, 0);
	// Forwards/Backwards
	if (MoveValue.Y != 0)
	{
		FVector Direction = MoveRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(Direction, MoveValue.Y);
	}
	// Left/Right
	if (MoveValue.X != 0)
	{
		FVector Direction = MoveRotation.RotateVector(FVector::RightVector);
		AddMovementInput(Direction, MoveValue.X);
	}
}

void AMainCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookValue = Value.Get<FVector2D>();

	if (LookValue.X != 0.f)
		AddControllerYawInput(LookValue.X);

	if (LookValue.Y != 0.f)
		AddControllerPitchInput(LookValue.Y);
	
}

void AMainCharacter::Zoom(const FInputActionValue& Value)
{
	SpringArmComp->TargetArmLength = FMath::Clamp(SpringArmComp->TargetArmLength + Value.GetMagnitude() * ZoomSpeed, MinZoom, MaxZoom);

}


