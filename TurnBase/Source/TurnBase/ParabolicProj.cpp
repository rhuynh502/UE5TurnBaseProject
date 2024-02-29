// Fill out your copyright notice in the Description page of Project Settings.


#include "ParabolicProj.h"
#include "Components/SphereComponent.h"

AParabolicProj::AParabolicProj(int a, int b, int z, int Damage, int Lifetime)
{
	ParabolaA = a;
	ParabolaB = b;
	ParabolaZ = z;

	WepDamage = Damage;
	WepLifetime = Lifetime;

	HitBox = CreateDefaultSubobject<USphereComponent>(FName("HitBox"));
}

void AParabolicProj::Tick(float DeltaTime)
{
}
