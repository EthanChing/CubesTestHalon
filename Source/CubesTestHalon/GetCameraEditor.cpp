// Fill out your copyright notice in the Description page of Project Settings.


#include "GetCameraEditor.h"
#include "Editor/UnrealEd/Public/EditorViewportClient.h"
#include "Editor/EditorEngine.h"
#include "MyActor.h"

UGetCameraEditor::UGetCameraEditor(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer) 
{

}

FVector UGetCameraEditor::GetEditorCameraLocation()
{
	FEditorViewportClient* client = (FEditorViewportClient*)(GEditor->GetActiveViewport()->GetClient());
	FVector editorCameraLocation = client->GetViewLocation();
	return editorCameraLocation;
}

FVector UGetCameraEditor::GetEditorCameraFacingDirection()
{
	FEditorViewportClient* client = (FEditorViewportClient*)(GEditor->GetActiveViewport()->GetClient());
	FVector editorCameratRotation = client->GetViewRotation().Vector();
	return editorCameratRotation;
}

FRotator UGetCameraEditor::GetEditorCameraRotation()
{
	FEditorViewportClient* client = (FEditorViewportClient*)(GEditor->GetActiveViewport()->GetClient());
	FRotator editorCameratRotation = client->GetViewRotation();
	return editorCameratRotation;
}

void UGetCameraEditor::SetViewLocation(FVector pnewviewlocation)
{
	FEditorViewportClient* client = (FEditorViewportClient*)(GEditor->GetActiveViewport()->GetClient());
	client->SetViewLocation(pnewviewlocation);
}

void UGetCameraEditor::SetViewRotation(FVector pnewRotation)
{
	FEditorViewportClient* client = (FEditorViewportClient*)(GEditor->GetActiveViewport()->GetClient());
	client->SetViewRotation(pnewRotation.Rotation());
}

void UGetCameraEditor::SpawnExampleActor(const UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	FEditorViewportClient* client = (FEditorViewportClient*)(GEditor->GetActiveViewport()->GetClient());
	FVector editorCameraDirection = client->GetViewRotation().Vector();
	FVector editorCameraPosition = client->GetViewLocation();
	FVector actorLocation = editorCameraPosition + (editorCameraDirection * 100);
	FRotator actorRotation = FRotationMatrix::MakeFromX(client->GetViewRotation().GetInverse().Add(0, 180, 0).GetInverse().Vector()).Rotator();
	AMyActor* exampleSpawnActor = World->SpawnActor<AMyActor>(actorLocation, actorRotation);
}
