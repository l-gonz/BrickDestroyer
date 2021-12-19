// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Paddle.generated.h"

class UFloatingPawnMovement;

UCLASS()
class BRICKDESTROYER_API APaddle : public APawn
{
	GENERATED_BODY()

public:

	APaddle();
	virtual void MoveHorizontal(float AxisValue);

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UFloatingPawnMovement* Movement;

};
