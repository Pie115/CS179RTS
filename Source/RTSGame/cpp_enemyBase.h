// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "cpp_enemyBase.generated.h"


UCLASS()
class RTSGAME_API Acpp_enemyBase : public AActor
{
	GENERATED_BODY()

private:
	FVector FindGate();	

public:	
	// Sets default values for this actor's properties
	Acpp_enemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enemy Info")
    bool shouldMove = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enemy Info")
    int32 Speed = 100;


	
};
