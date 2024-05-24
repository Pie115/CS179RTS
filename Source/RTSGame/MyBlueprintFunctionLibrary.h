#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

USTRUCT(BlueprintType)
struct FEnemyDistanceStruct
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    AActor* Enemy;

    UPROPERTY(BlueprintReadWrite)
    float Distance;

    FEnemyDistanceStruct()
        : Enemy(nullptr), Distance(0.0f)
    {
    }

    FEnemyDistanceStruct(AActor* InEnemy, float InDistance)
        : Enemy(InEnemy), Distance(InDistance)
    {
    }
};

UCLASS()
class RTSGAME_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Utilities")
    static void SortEnemiesByDistance(const TArray<FEnemyDistanceStruct>& Enemies, TArray<FEnemyDistanceStruct>& SortedEnemies);
};
