// Fill out your copyright notice in the Description page of Project Settings.


#include "cpp_PlanetBase.h"

// Sets default values
Acpp_PlanetBase::Acpp_PlanetBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Acpp_PlanetBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Acpp_PlanetBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Acpp_PlanetBase::CalculateIntervalProduction()
{
    IntervalProduction = FResourceList();
    IntervalProduction.Energy = Technicians.Current * 6;


    IntervalProduction.Minerals = Miners.Current * 4;
    IntervalProduction.Food = Farmers.Current * 6;
    IntervalProduction.Alloys = Metallurgists.Current * 3;
    IntervalProduction.Science = Scientists.Current * 2;


    // Metallurgist Upkeep
    IntervalProduction.Minerals -= Metallurgists.Current * 6;
    // Scientist Upkeep
    IntervalProduction.Energy -= Scientists.Current * 3;
    //Planetary Weapons Upkeep
    IntervalProduction.Alloys -= Gunners * 2;
    IntervalProduction.Energy -= Gunners * 1;

    // Pop Upkeep
    IntervalProduction.Food -= Population;
}

// For Buildings
void Acpp_PlanetBase::AddMaxWorker(FString name)
{

}

// For districts
void Acpp_PlanetBase::AddMaxWorker(int32 index)
{
    if(index == 0)
    {
        Miners.Max += 2;
    }
    if(index == 1)
    {
        Metallurgists.Max += 2;
    }
    if(index == 2)
    {
        Technicians.Max += 2;
    }
    if(index == 3)
    {
        Farmers.Max += 2;
    }
}

void Acpp_PlanetBase::AddCurrentWorker(FString Name)
{
    // Cannot Assign Workers If There Is No One To Assign
    if(Unemployed == 0)
    {
        return;
    }

    if(Name == "Technician")
    {
        Technicians.Current++;
    }
    else if(Name == "Miner")
    {
        Miners.Current++;
    }
    else if(Name == "Farmer")
    {
        Farmers.Current++;
    }
    else if(Name == "Metallurgist")
    {
        Metallurgists.Current++;
    }
    else if(Name == "Scientist")
    {
        Scientists.Current++;
    }
    else if(Name == "Gunner")
    {
        Gunners++;
    }
}
void Acpp_PlanetBase::RemoveCurrentWorker(FString Name)
{
    if(Name == "Technician" && Technicians.Current)
    {
        Technicians.Current--;
    }
    else if(Name == "Miner" && Miners.Current)
    {
        Miners.Current--;
    }
    else if(Name == "Farmer" && Farmers.Current)
    {
        Farmers.Current--;
    }
    else if(Name == "Metallurgist" && Metallurgists.Current)
    {
        Metallurgists.Current--;
    }
    else if(Name == "Scientist" && Scientists.Current)
    {
        Scientists.Current--;
    }
    else if(Name == "Gunner" && Gunners)
    {
        Gunners--;
    }
}