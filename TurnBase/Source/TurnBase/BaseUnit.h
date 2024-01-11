// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SkillsList.h"
#include "BaseUnit.generated.h"

UCLASS()
class TURNBASE_API ABaseUnit : public APawn, public ISkillsList
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseUnit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UUnitStats* Stats;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Model;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
