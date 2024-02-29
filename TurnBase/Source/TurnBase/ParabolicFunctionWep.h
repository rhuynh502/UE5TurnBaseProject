// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWeapon.h"
#include "ParabolicFunctionWep.generated.h"

/**
 * 
 */
UCLASS()
class TURNBASE_API AParabolicFunctionWep : public ABaseWeapon
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class ABaseProjectile* Proj;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int a;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int b;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int z;
};
