// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UnitStats.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TURNBASE_API UUnitStats : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUnitStats();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Health of unit
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Health = 0;
	// Physical attack of unit. Affects moves that are physical.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Attack = 0;
	// Magic attack of unit. Affects moves that are magical.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MAttack = 0;
	// Physical defense of unit. Affects moves that are physical.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Def = 0;
	// Magical defense of unit. Affects moves that are magical.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Res = 0;
	// Speed of unit, determines turn order
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Speed = 0;

public:
	float GetHealth() { return Health; }
	float GetAttack() { return Attack; }
	float GetMAttack() { return MAttack; }
	float GetDef() { return Def; }
	float GetRes() { return Res; }
	float GetSpeed() { return Speed; }
	
		
};
