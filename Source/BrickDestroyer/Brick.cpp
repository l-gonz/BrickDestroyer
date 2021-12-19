// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

#include "Ball.h"


const float SpeedModifierOnBounce = 1.01f;

ABrick::ABrick()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));

	RootComponent = BoxCollision;
}

void ABrick::BeginPlay()
{
	Super::BeginPlay();
	
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);
}

void ABrick::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep,
		const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Ball"))
	{
		ABall* Ball = Cast<ABall>(OtherActor);
		Ball->GetMesh()->SetPhysicsLinearVelocity(Ball->GetVelocity() * SpeedModifierOnBounce);

		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrick::DestroyBrick, 0.1f, false);
	}
}

void ABrick::DestroyBrick()
{
	Destroy();
}
