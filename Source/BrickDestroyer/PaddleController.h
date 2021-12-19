// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PaddleController.generated.h"

class ABall;

UCLASS()
class BRICKDESTROYER_API APaddleController : public APlayerController
{
	GENERATED_BODY()

	UFUNCTION()
		virtual void SetupInputComponent() override;

public:
	APaddleController();
	void SpawnNewBall();

protected:

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallClass;

	virtual void BeginPlay() override;

	void MoveHorizontal(float AxisValue);
	void Launch();
	
};
