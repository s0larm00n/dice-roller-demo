#include "DiceRoller.h"
#include "Kismet/GameplayStatics.h"

UDiceRoller::UDiceRoller()
{
}

UDiceRoller::~UDiceRoller()
{
}

void UDiceRoller::Initialize(const UObject* WorldContextObject)
{
	TArray<AActor*> RawContainers;
	UGameplayStatics::GetAllActorsOfClass(WorldContextObject, AContainerStaticMeshActor::StaticClass(), RawContainers);
	Container = Cast<AContainerStaticMeshActor>(RawContainers[0]);

	TArray<AActor*> RawDices;
	UGameplayStatics::GetAllActorsOfClass(WorldContextObject, ADiceStaticMeshActor::StaticClass(), RawDices);
	for (int i = 0; i < 3; i++)
	{
		int j = -1;
		if (RawDices[i]->GetActorLabel() == "Dice1")
		{
			j = 0;
		}
		if (RawDices[i]->GetActorLabel() == "Dice2")
		{
			j = 1;
		}
		if (RawDices[i]->GetActorLabel() == "Dice3")
		{
			j = 2;
		}
		Dices[j] = Cast<ADiceStaticMeshActor>(RawDices[i]);
		Cubes[j] = Cast<UStaticMeshComponent>(RawDices[i]->GetDefaultSubobjectByName(TEXT("Cube")));
	}
}

void UDiceRoller::ShakeCube(
	float MinX, float MaxX,
	float MinY, float MaxY,
	float MixZ, float MaxZ,
	UStaticMeshComponent* Cube
)
{
	Cube->AddImpulse(FVector(
		FMath::RandRange(MinX, MaxX),
		FMath::RandRange(MinY, MaxY),
		FMath::RandRange(MixZ, MaxZ)
	));
	Cube->AddAngularImpulseInDegrees(
		FVector(
			FMath::RandRange(90, 180),
			FMath::RandRange(90, 180),
			FMath::RandRange(90, 180)
		),
		NAME_None,
		true
	);
}

void UDiceRoller::ShakeAllDicesWithRandomIndividualImpulse(
	float MinX, float MaxX,
	float MinY, float MaxY,
	float MixZ, float MaxZ
)
{
	for (UStaticMeshComponent* Cube : Cubes)
	{
		ShakeCube(MinX, MaxX, MinY, MaxY, MixZ, MaxZ, Cube);
	}
}

void UDiceRoller::ShakeDiceWithRandomImpulse(
	int Index,
	float MinX, float MaxX,
	float MinY, float MaxY,
	float MixZ, float MaxZ)
{
	ShakeCube(MinX, MaxX, MinY, MaxY, MixZ, MaxZ, Cubes[Index - 1]);
}

void UDiceRoller::ShakeContainer()
{
	Container->SetOffShaking();
}
