#pragma once

#include "CoreMinimal.h"
#include "ContainerStaticMeshActor.h"
#include "DiceStaticMeshActor.h"
#include "DiceRoller.generated.h"

UCLASS()
class DICE_ROLLER_DEMO_API UDiceRoller : public UObject
{
	GENERATED_BODY()

	AContainerStaticMeshActor* Container{NULL};
	TStaticArray<ADiceStaticMeshActor*, 3> Dices{NULL};
	TStaticArray<UStaticMeshComponent*, 3> Cubes{NULL};

	void ShakeCube(float MinX, float MaxX, float MinY, float MaxY, float MixZ, float MaxZ, UStaticMeshComponent* Cube);

public:
	UDiceRoller();
	~UDiceRoller();

	UFUNCTION(BlueprintCallable)
	void Initialize(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable)
	void ShakeAllDicesWithRandomIndividualImpulse(
		float MinX, float MaxX,
		float MinY, float MaxY,
		float MixZ, float MaxZ
	);

	UFUNCTION(BlueprintCallable)
	void ShakeDiceWithRandomImpulse(
		int Index,
		float MinX, float MaxX,
		float MinY, float MaxY,
		float MixZ, float MaxZ
	);

	UFUNCTION(BlueprintCallable)
	void ShakeContainer();
};
