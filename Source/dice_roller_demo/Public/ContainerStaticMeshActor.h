// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "ContainerStaticMeshActor.generated.h"

enum MovementPhase
{
	IDLE,
	PHASE_1,
	PHASE_2,
	PHASE_3
};

UCLASS()
class DICE_ROLLER_DEMO_API AContainerStaticMeshActor : public AStaticMeshActor
{
	GENERATED_BODY()

	FVector Pos1 = FVector(1000, 1000, 1000);
	FVector Pos2 = FVector(-1000, -1000, -1000);
	FVector Origin = FVector(0, 0, 0);
	FRotator OriginRot{};
	float Duration1 = 0.5f; // Pos1 -> Pos2
	float Duration2 = 0.8f; // Pos2 -> Pos3
	float Duration3 = 0.5f; // Pos3 -> Pos1
	float ElapsedTime = 0.0f;
	MovementPhase Phase = IDLE;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetOffShaking();

	AContainerStaticMeshActor();
};
