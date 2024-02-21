#include "UE5_C_plus_plusEditor.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"

IMPLEMENT_GAME_MODULE(FUE5_C_plus_plusEditorModule, UE5_C_plus_plusEditor)

void FUE5_C_plus_plusEditorModule::StartupModule()
{
    // Check if editor is valid
    if(GUnrealEd)
    {
        // Register the move visualizer
        TSharedPtr<FMoveComponentVisualizer> MoveVisualizer = MakeShareable(new FMoveComponentVisualizer());
        if(MoveVisualizer.IsValid())
        {
            GUnrealEd->RegisterComponentVisualizer(UMoveSceneComponent::StaticClass()->GetFName(), MoveVisualizer);
            MoveVisualizer->OnRegister();
        }
    }
}

void FUE5_C_plus_plusEditorModule::ShutdownModule()
{
    // Check if editor is valid
    if(GUnrealEd)
    {
        GUnrealEd->UnregisterComponentVisualizer(UMoveSceneComponent::StaticClass()->GetFName());
    }
}