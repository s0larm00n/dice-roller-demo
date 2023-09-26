#include "ContainerStaticMeshActor.h"

void AContainerStaticMeshActor::Tick(float DeltaTime)
{
	switch (Phase)
	{
	case IDLE:
		{
			break;
		}
	case PHASE_1:
		{
			ElapsedTime += DeltaTime;
			SetActorLocation(FMath::Lerp(Origin, Pos1, FMath::Clamp(ElapsedTime / Duration1, 0.0f, 1.0f)));
			FRotator Rotation = FRotator(
				0,
				0.0f,
				FMath::Lerp(0, 20, FMath::Clamp(ElapsedTime / Duration1, 0.0f, 1.0f))
			);
			SetActorRotation(OriginRot + Rotation);
			if (ElapsedTime >= Duration1)
			{
				SetActorLocation(Pos1);
				SetActorRotation(OriginRot + FRotator(0, 0.0f, 20));
				Phase = PHASE_2;
				ElapsedTime = 0.0f;
			}
			break;
		}
	case PHASE_2:
		{
			ElapsedTime += DeltaTime;
			SetActorLocation(FMath::Lerp(Pos1, Pos2, FMath::Clamp(ElapsedTime / Duration2, 0.0f, 1.0f)));
			FRotator Rotation = FRotator(
				0,
				0.0f,
				FMath::Lerp(20, -20, FMath::Clamp(ElapsedTime / Duration1, 0.0f, 1.0f))
			);
			SetActorRotation(OriginRot + Rotation);
			if (ElapsedTime >= Duration2)
			{
				SetActorLocation(Pos2);
				SetActorRotation(OriginRot + FRotator(0, 0.0f, -20));
				Phase = PHASE_3;
				ElapsedTime = 0.0f;
			}
			break;
		}
	case PHASE_3:
		{
			ElapsedTime += DeltaTime;
			SetActorLocation(FMath::Lerp(Pos2, Origin, FMath::Clamp(ElapsedTime / Duration3, 0.0f, 1.0f)));
			FRotator Rotation = FRotator(
				0,
				0.0f,
				FMath::Lerp(-20, 0, FMath::Clamp(ElapsedTime / Duration1, 0.0f, 1.0f))
			);
			SetActorRotation(OriginRot + Rotation);
			if (ElapsedTime >= Duration3)
			{
				SetActorLocation(Origin);
				SetActorRotation(OriginRot);
				Phase = IDLE;
				ElapsedTime = 0.0f;
			}
			break;
		}
	}
}

void AContainerStaticMeshActor::SetOffShaking()
{
	Origin = GetActorLocation();
	Pos1 = FVector(
		Origin.X + FMath::RandRange(-200, 200),
		Origin.Y + FMath::RandRange(-200, 200),
		Origin.Z + FMath::RandRange(-800, -500)
	);
	Pos2 = FVector(
		Origin.X + FMath::RandRange(-200, 200),
		Origin.Y + FMath::RandRange(-200, 200),
		Origin.Z + FMath::RandRange(500, 800)
	);
	OriginRot = GetActorRotation();
	Phase = PHASE_1;
}

AContainerStaticMeshActor::AContainerStaticMeshActor()
{
	SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;
}
