// Fill out your copyright notice in the Description page of Project Settings.


#include "cpp_enemyBase.h"


// Sets default values
Acpp_enemyBase::Acpp_enemyBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Acpp_enemyBase::BeginPlay()
{
	Super::BeginPlay();
	if(shouldMove)
	{
		FVector ActorLocation = GetActorLocation();

		// Calculate the direction vector
		FVector TargetLocation = FindGate();
	
		FVector Direction = TargetLocation - ActorLocation;
		Direction.Z = 0;  // Optional: Ignore vertical difference if you want the actor to only rotate horizontally

		// Calculate the rotation
		FRotator NewRotation = FRotationMatrix::MakeFromX(Direction).Rotator();

		// Set the actor's rotation
		SetActorRotation(NewRotation);
	}	

}

// Called every frame
void Acpp_enemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(shouldMove)
	{
		FVector ActorLocatiiton = GetActorLocation();

		FVector CurrentLocation = GetActorLocation();

		CurrentLocation = GetActorLocation() + GetActorForwardVector() * Speed * DeltaTime;

		SetActorLocation(CurrentLocation);
	}
}

FVector Acpp_enemyBase::FindGate()
{
	// Load the Blueprint class at runtime

	///Game/TA2Project/Non-PlayerEntities/Gate.Gate_C
	//Game/Blueprints/Gate.Gate_C
	UE_LOG(LogTemp, Error, TEXT("Finding Gate"));
    UClass* ActorClass = StaticLoadClass(AActor::StaticClass(), nullptr, TEXT("/Game/Blueprints/Gate.Gate_C"));

    // Ensure the Blueprint class was found
    if (ActorClass)
    {
        TArray<AActor*> FoundActors;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), ActorClass, FoundActors);

		if(FoundActors.Num() == 1)
		{
			return FoundActors[0]->GetActorLocation();	
			UE_LOG(LogTemp, Log, TEXT("Gate found at location: %s"), *FoundActors[0]->GetActorLocation().ToString());
		}
		UE_LOG(LogTemp, Error, TEXT("Multiple gates found"));

		
    }
    UE_LOG(LogTemp, Error, TEXT("No gate class found"));
	return FVector(0,0,0);
}
