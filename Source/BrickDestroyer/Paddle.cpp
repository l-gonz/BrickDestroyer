// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"

#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
APaddle::APaddle()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Paddle Mesh"));
	RootComponent = Mesh;

	Mesh->SetEnableGravity(false);
	Mesh->SetConstraintMode(EDOFMode::XZPlane);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionProfileName(TEXT("PhysicsActor"));

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));
}

void APaddle::MoveHorizontal(float AxisValue)
{
	AddMovementInput(FVector(AxisValue, 0.0f, 0.0f));
}
