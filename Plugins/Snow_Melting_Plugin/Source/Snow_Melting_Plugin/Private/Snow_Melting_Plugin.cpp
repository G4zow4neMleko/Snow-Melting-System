// Copyright Epic Games, Inc. All Rights Reserved.

#include "Snow_Melting_Plugin.h"

#define LOCTEXT_NAMESPACE "FSnow_Melting_PluginModule"

void FSnow_Melting_PluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FSnow_Melting_PluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSnow_Melting_PluginModule, Snow_Melting_Plugin)