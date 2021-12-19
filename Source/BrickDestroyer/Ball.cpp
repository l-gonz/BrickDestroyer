// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

bool BallLaunched;

ABall::ABall()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	Mesh->SetSimulatePhysics(true);
	Mesh->SetEnableGravity(false);
	Mesh->SetConstraintMode(EDOFMode::XZPlane);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionProfileName(TEXT("PhysicsActor"));

	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	Movement->bShouldBounce = true;
	Movement->Bounciness = 1.1f;
	Movement->Friction = 0.0f;
	Movement->Velocity.X = 0.0f;
}

void ABall::Launch()
{
	if (!BallLaunched)
	{
		Mesh->AddImpulse(FVector(140.0f, 0.0f, 130.0f), FName(), true);
		BallLaunched = true;
	}
}

UStaticMeshComponent* ABall::GetMesh()
{
	return Mesh;
}