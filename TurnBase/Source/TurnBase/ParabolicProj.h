// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseProjectile.h"
#include "ParabolicProj.generated.h"

/**
 * 
 */
UCLASS()
class TURNBASE_API AParabolicProj : public ABaseProjectile
{
	GENERATED_BODY()
	
public:
	AParabolicProj(int a, int b, int z, int Damage, int Lifetime);

	virtual void Tick(float DeltaTime) override;


private:
	int ParabolaA;
	int ParabolaB;
	int ParabolaZ;

	int WepDamage;
	int WepLifetime;

	class USphereComponent* HitBox;

	UFUNCTION()
	void OnComponentOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
