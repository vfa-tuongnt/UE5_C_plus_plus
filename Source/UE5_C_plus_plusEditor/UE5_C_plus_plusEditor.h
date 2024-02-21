#pragma once

#include "Engine.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "UnrealEd.h"
#include "MoveComponentVisualizer.h"
#include "UE5_C_plus_plus/MoveSceneComponent.h"

DECLARE_LOG_CATEGORY_EXTERN(UE5_C_plus_plusEditor, All, All)

class FUE5_C_plus_plusEditorModule: public IModuleInterface
{
public:
    void StartupModule() override;
    void ShutdownModule() override;
};