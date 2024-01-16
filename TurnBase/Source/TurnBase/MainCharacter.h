// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MainCharacter.generated.h"

UCLASS()
class TURNBASE_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Unit Stats
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UUnitStats* Stats;

	// Camera Components
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCameraComponent* CameraComp;

	// Enhanced Input Subsystem
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input System")
	class UInputMappingContext* InputMapping;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input System")
	class UInputConfig* InputActions;
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Zoom(const FInputActionValue& Value);
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input System")
	float MaxZoom;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input System")
	float MinZoom;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input System")
	float ZoomSpeed = 1;

};
