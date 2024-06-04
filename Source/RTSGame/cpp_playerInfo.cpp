// Fill out your copyright notice in the Description page of Project Settings.


#include "cpp_playerInfo.h"

// Sets default values
Acpp_playerInfo::Acpp_playerInfo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CurrentResources = FResourceList(600);

}

// Called when the game starts or when spawned
void Acpp_playerInfo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Acpp_playerInfo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Called every frame
void Acpp_playerInfo::UpdateResources()
{
	CurrentResources += IntervalProduction;
	if(CurrentResources.Energy <= 0)
	{
		CurrentResources.Energy = 0;
	}
	if(CurrentResources.Minerals <= 0)
	{
		CurrentResources.Minerals = 0;
	}
	if(CurrentResources.Food <= 0)
	{
		CurrentResources.Food = 0;
	}
	if(CurrentResources.Alloys <= 0)
	{
		CurrentResources.Alloys = 0;
	}
	if(CurrentResources.Science <= 0)
	{
		CurrentResources.Science = 0;
	}

}

UFUNCTION(BlueprintCallable)
void Acpp_playerInfo::ChangeResource(int32 index, int32 amount)
{
	if(index == 0)
	{
		CurrentResources.Energy += amount;
	}
	else if(index == 1)
	{
		CurrentResources.Minerals += amount;
	}
	else if(index == 2)
	{
		CurrentResources.Food += amount;
	}
	else if(index == 3)
	{
		CurrentResources.Alloys += amount;
	}
	else if(index == 4)
	{
		CurrentResources.Science += amount;
	}
} 