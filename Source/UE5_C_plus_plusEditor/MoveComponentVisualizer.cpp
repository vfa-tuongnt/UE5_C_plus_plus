// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponentVisualizer.h"
#include "UE5_C_plus_plus/MoveSceneComponent.h"

void FMoveComponentVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
    // Get our move component
    const UMoveSceneComponent* MovementComponent = Cast<UMoveSceneComponent>(Component);
    if(MovementComponent)
    {
        PDI->DrawLine(
            MovementComponent->GetComponentLocation(), MovementComponent->GetComponentLocation() + MovementComponent->MoveOffset, FLinearColor::Red, 
            SDPG_Foreground
        );
    }
}
