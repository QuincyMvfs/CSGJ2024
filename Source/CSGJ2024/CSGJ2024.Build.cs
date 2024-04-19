// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CSGJ2024 : ModuleRules
{
	public CSGJ2024(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
