// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MineCraft : ModuleRules
{
	public MineCraft(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore"
			, "UMG"
			, "EnhancedInput"
			, "AIModule"
			, "NavigationSystem"
			, "Niagara"
			, "LevelSequence"
			, "MovieScene"
			, "MediaAssets" });

        PrivateDependencyModuleNames.AddRange(new string[] { });
        PublicDependencyModuleNames.AddRange(new string[] { "ProceduralMeshComponent" });
        PublicIncludePaths.Add("MineCraft");

        // Uncomment if you are using Slate UI
        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        PrivateDependencyModuleNames.Add("OnlineSubsystem");
    }
}
