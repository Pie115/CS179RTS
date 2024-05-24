#include "MyBlueprintFunctionLibrary.h"

void UMyBlueprintFunctionLibrary::SortEnemiesByDistance(const TArray<FEnemyDistanceStruct>& Enemies, TArray<FEnemyDistanceStruct>& SortedEnemies)
{
    SortedEnemies = Enemies;
    SortedEnemies.Sort([](const FEnemyDistanceStruct& A, const FEnemyDistanceStruct& B)
        {
            return A.Distance < B.Distance;
        });
}
