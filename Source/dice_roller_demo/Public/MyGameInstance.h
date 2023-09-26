// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiceRoller.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

UCLASS()
class DICE_ROLLER_DEMO_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UDiceRoller* DiceRoller = NULL;

	UMyGameInstance();

	~UMyGameInstance() = default;

	UFUNCTION(BlueprintCallable)
	void OnBeginPlay();

	void Init() override;

	void Shutdown() override;
};
