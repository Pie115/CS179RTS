// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "cpp_playerInfo.generated.h"


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
    

    FResourceList(int32 amount = 0)
        : Energy(amount), Minerals(amount), Food(amount), Alloys(amount), Science(amount) {}


	FResourceList operator+(const FResourceList& Other) const {
        FResourceList Result;
        Result.Energy = this->Energy + Other.Energy;
        Result.Minerals = this->Minerals + Other.Minerals;
        Result.Food = this->Food + Other.Food;
        Result.Alloys = this->Alloys + Other.Alloys;
        Result.Science = this->Science + Other.Science;
        return Result;
    }

    // Overload the - operator
    FResourceList operator-(const FResourceList& Other) const {
        FResourceList Result;
        Result.Energy = this->Energy - Other.Energy;
        Result.Minerals = this->Minerals - Other.Minerals;
        Result.Food = this->Food - Other.Food;
        Result.Alloys = this->Alloys - Other.Alloys;
        Result.Science = this->Science - Other.Science;
        return Result;
    }

	FResourceList& operator+=(const FResourceList& Other) {
		*this = *this + Other;
		return *this;
	}

	FResourceList& operator-=(const FResourceList& Other) {
		*this = *this - Other;
		return *this;
	}

};

UCLASS()
class RTSGAME_API Acpp_playerInfo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Acpp_playerInfo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ResourceInfo")
    FResourceList IntervalProduction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ResourceInfo")
    FResourceList CurrentResources;
	
	UFUNCTION(BlueprintCallable)
    void UpdateResources();

	UFUNCTION(BlueprintCallable)
    void ChangeResource(int32 a, int32 b);

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
