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

}