// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TurnManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TURNBASE_API UTurnManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTurnManager();

protected:
	// Called when the game starts
	virtual void BeginPlay();

	TArray<APawn*> AllPawns;

	APawn* CurrentPawn;

	// Make a sort function for AllPawns for turn order.

public:	

	// Given two teams that are fighting, it will populate the array of all players.
	void PopulatePlayers(TArray<APawn*> Team1, TArray<APawn*> Team2);
	void StartTurn();
	void EndTurn();
		
};
