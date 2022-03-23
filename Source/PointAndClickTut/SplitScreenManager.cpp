// Fill out your copyright notice in the Description page of Project Settings.


#include "SplitScreenManager.h"

// Sets default values
ASplitScreenManager::ASplitScreenManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASplitScreenManager::BeginPlay()
{
	Super::BeginPlay();

    UWorld* OurWorld = GetWorld();

    if (!OurWorld)
        return;

	UGameViewportClient* Viewport = OurWorld->GetGameViewport();
    
    FSplitscreenData ScreenLayout;
    auto Screen1 = FPerPlayerSplitscreenData(1, 0.725f, 0, 0);
    ScreenLayout.PlayerData.Add(Screen1);

    if (!Viewport)
        return;

    Viewport->SetDisableSplitscreenOverride(true);
    Viewport->SplitscreenInfo[ESplitScreenType::None] = ScreenLayout;
         
}

// Called every frame
void ASplitScreenManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

