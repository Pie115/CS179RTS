// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "cpp_PlanetBase.generated.h"

USTRUCT(BlueprintType)
struct FJob {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Job")
    int32 Max;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Job")
    int32 Current;

    FJob()
        : Max(0), Current(0) {}
};

USTRUCT(BlueprintType)
struct FResourceList {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
    int32 Energy;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
    int32 Minerals;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
    int32 Food;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
    int32 Alloys;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
    int32 Science;
    

    FResourceList()
        : Energy(0), Minerals(0), Food(0), Alloys(0), Science(0) {}
};

UCLASS()
class RTSGAME_API Acpp_PlanetBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Acpp_PlanetBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    void CalculateIntervalProduction();
    
    void AddMaxWorker(FString name);

	// For Districts
    void AddCurrentWorker(FString jobName);
	
	// For Buildings
    void AddMaxWorker(int32 index);

    void RemoveCurrentWorker(FString jobName);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlanetInfo")
    int32 Population;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlanetInfo")
    FJob Technicians;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlanetInfo")
    FJob Miners;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlanetInfo")
    FJob Farmers;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlanetInfo")
    FJob Metallurgists;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlanetInfo")
    FJob Scientists;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlanetInfo")
    int32 Gunners;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlanetInfo")
    int32 Unemployed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlanetInfo")
    FResourceList IntervalProduction;
};