// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveSceneComponent.h"

// Sets default values for this component's properties
UMoveSceneComponent::UMoveSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// Set position
	StartRelativeLocation = this -> GetRelativeLocation();	
	MoveOffsetNorm = MoveOffset;
	MoveOffsetNorm.Normalize();
	MaxDistance = MoveOffset.Length();
}


// Called every frame
void UMoveSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Compute location overtime
	CurDistance += speed * DeltaTime * MoveDirection;
	if(CurDistance >= MaxDistance || CurDistance <= 0.0f)
	{
		MoveDirection *= -1;
	}

	// Set end position
	SetRelativeLocation(StartRelativeLocation + MoveOffsetNorm * CurDistance);
}

