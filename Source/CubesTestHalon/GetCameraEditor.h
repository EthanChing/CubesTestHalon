// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GetCameraEditor.generated.h"

/**
 * 
 */
UCLASS()
class CUBESTESTHALON_API UGetCameraEditor : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Editor Camera Location", Keywords = "Get Editor Camera Location"), Category = "Editor Camera")
		static FVector GetEditorCameraLocation();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Editor Camera Direction", Keywords = "Get Editor Camera Direction"), Category = "Editor Camera")
		static FVector GetEditorCameraFacingDirection();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Editor Camera Rotation", Keywords = "Get Editor Camera Rotation"), Category = "Editor Camera")
		static FRotator GetEditorCameraRotation();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Editor Camera Location", Keywords = "Set Editor Camera Location"), Category = "Editor Camera")
		static void SetViewLocation(FVector pnewviewlocation);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Editor Camera Rotation", Keywords = "Set Editor Camera Rotation"), Category = "Editor Camera")
		static void SetViewRotation(FVector pnewRotation);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", DisplayName = "Spawn Example Actor", Keywords = "Spawn Example Actor"), Category = "Editor Camera")
		static void SpawnExampleActor(const UObject* WorldContextObject);
};
