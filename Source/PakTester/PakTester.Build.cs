// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class PakTester : ModuleRules
{
	public PakTester(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "PakFile" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
        //Definitions.Add("IS_PROGRAM=1");
        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
