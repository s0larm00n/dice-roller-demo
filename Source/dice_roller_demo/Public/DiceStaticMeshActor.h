// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "DiceStaticMeshActor.generated.h"

/**
 * 
 */
UCLASS()
class DICE_ROLLER_DEMO_API ADiceStaticMeshActor : public AStaticMeshActor
{
	GENERATED_BODY()

	FVector FaceUpVectors[6] = {
		FVector(1.0f, 0.0f, 0.0f), // 1
		FVector(0.0f, -1.0f, 0.0f), // 2
		FVector(0.0f, 0.0f, 1.0f), // 3
		FVector(0.0f, 0.0f, -1.0f), // 4
		FVector(0.0f, 1.0f, 0.0f), // 5
		FVector(-1.0f, 0.0f, 0.0f) // 6 
	};

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Material{1};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString CountString;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Count;

	virtual void Tick(float DeltaTime) override;

	ADiceStaticMeshActor();
};
