// Fill out your copyright notice in the Description page of Project Settings.


#include "DiceStaticMeshActor.h"

void ADiceStaticMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator DiceRotation = Cast<UStaticMeshComponent>(GetDefaultSubobjectByName(TEXT("Cube")))->GetRelativeRotation();
	float MaxDotProduct = -1;
	int TopFace = -1;

	for (int faceIndex = 0; faceIndex < 6; ++faceIndex)
	{
		FVector TransformedFaceUpVector = FRotationMatrix(DiceRotation).TransformVector(FaceUpVectors[faceIndex]);
		TransformedFaceUpVector.Normalize();
		const float DotProduct = FVector::DotProduct(FVector(0, 0, 1), TransformedFaceUpVector);
		if (DotProduct > MaxDotProduct)
		{
			MaxDotProduct = DotProduct;
			TopFace = faceIndex;
		}
	}

	Count = TopFace + 1;
	CountString = FString::Printf(TEXT("%d"), Count);
}

ADiceStaticMeshActor::ADiceStaticMeshActor()
{
	SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;
}
