// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddleController.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "Paddle.h"
#include "Ball.h"

APaddle* Paddle;
ABall* BallInstance;

const FVector BallSpawnLocation = FVector(10.0f, 0.0f, 40.0f);

APaddleController::APaddleController(){}

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
    if (BallInstance)
        BallInstance->Launch();
    else
        UE_LOG(LogTemp, Error, TEXT("No spawned ball"));
}

void APaddleController::SpawnNewBall()
{
    if (BallClass)
        BallInstance = GetWorld()->SpawnActor<ABall>(BallClass, BallSpawnLocation, FRotator::ZeroRotator);
    else
        UE_LOG(LogTemp, Error, TEXT("Ball reference not set"));
}
