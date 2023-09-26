// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	DiceRoller = NewObject<UDiceRoller>();
}

void UMyGameInstance::OnBeginPlay()
{
	DiceRoller->Initialize(GetWorld());
}

void UMyGameInstance::Init()
{
	Super::Init();
}

void UMyGameInstance::Shutdown()
{
	Super::Shutdown();
}
