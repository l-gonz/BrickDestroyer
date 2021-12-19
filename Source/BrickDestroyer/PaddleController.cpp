// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddleController.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "Paddle.h"
#include "Ball.h"

APaddle* Paddle;

APaddleController::APaddleController()
{

}

void APaddleController::BeginPlay()
{
    TArray<AActor*> CameraActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);
    SetViewTarget(CameraActors[0]);

    Paddle = Cast<APaddle>(GetPawn());

    SpawnNewBall();
}

void APaddleController::SetupInputComponent()
{
    Super::SetupInputComponent();

    EnableInput(this);
    InputComponent->BindAxis("MoveHorizontal", this, &APaddleController::MoveHorizontal);
    InputComponent->BindAction("Launch", EInputEvent::IE_Pressed, this, &APaddleController::Launch);
}

void APaddleController::MoveHorizontal(float AxisValue)
{
    if (Paddle)
        Paddle->MoveHorizontal(AxisValue);
}

void APaddleController::Launch()
{
    BallInstance->Launch();
}

void APaddleController::SpawnNewBall()
{
    if (!BallInstance)
        BallInstance = nullptr;

    if (BallObj)
        BallInstance = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotation, SpawnInfo);
}
