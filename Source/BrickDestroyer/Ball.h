// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

class UProjectileMovementComponent;

UCLASS()
class BRICKDESTROYER_API ABall : public AActor
{
	GENERATED_BODY()
	
public:

	ABall();
	virtual void Launch();

	UFUNCTION()
		UStaticMeshComponent* GetMesh();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UProjectileMovementComponent* Movement;

};
