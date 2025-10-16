// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class First_For_Eng_ProjEditorTarget : TargetRules
{
	public First_For_Eng_ProjEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;
		ExtraModuleNames.Add("First_For_Eng_Proj");
		
		// ---- Build speed helpers (Editor only) ----
		bUseUnityBuild          = true;   // compiles in chunks
		bUseAdaptiveUnityBuild  = true;   // only de-unify files that change often
		bUsePCHFiles            = true;   // keep a PCH so most headers come precompiled
	}
}



