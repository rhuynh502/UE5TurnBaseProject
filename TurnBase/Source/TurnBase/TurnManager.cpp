// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnManager.h"

// Sets default values for this component's properties
UTurnManager::UTurnManager()
{

}


// Called when the game starts
void UTurnManager::BeginPlay()
{
	// Sort All players via speed
	// AllPawns.Sort();
	// CurrentPawn = AllPawns.Pop();
}


void UTurnManager::PopulatePlayers(TArray<APawn*> Team1, TArray<APawn*> Team2)
{
	for (int i = 0; i < Team1.Num(); i++)
		AllPawns.Add(Team1[i]);
	for (int i = 0; i < Team2.Num(); i++)
		AllPawns.Add(Team2[i]);
}

void UTurnManager::StartTurn()
{
	// Tick all buff and debuff turns and use their effects
	// CurrentPawn->ApplyBuffs();
	// CurrentPawn->ApplyDebuffs();
}

void UTurnManager::EndTurn()
{
	// Remove a counter from all buffs and debuffs as turn has ended
	// CurrentPawn->CountdownBuffs();
	// CurrentPawn->CountdownDebuffs();

	// Set next player to take turn
	// AllPawns.Add(CurrentPawn);
	// CurrentPawn = AllPawns.Pop();
}

