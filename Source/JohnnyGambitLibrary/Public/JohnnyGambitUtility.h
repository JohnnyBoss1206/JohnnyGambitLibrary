// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JohnnyGambitUtility.generated.h"

/**
 * 
 */
UCLASS()
class JOHNNYGAMBITLIBRARY_API UJohnnyGambitUtility : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	template<typename T>
	static void AdjustWeight(TArray<TPair<int, T>>& weightList)
	{
		for (TPair<int, T>& pair : weightList)
		{
			pair.Key++;
		}
	}

	template<typename T>
	static int GetTotalWeight(TArray<TPair<int, T>>& weightList)
	{
		int total = 0;
		for (TPair<int, T>& pair : weightList)
		{
			total += pair.Key;
		}
		return total;
	}

	template<typename T>
	static T CalcWeightRate(TArray<TPair<int, T>>& weightList,int totalWeight)
	{
		int total = totalWeight;
		T ret = T();
		int keyWeight = FMath::RandRange(0,totalWeight);
		for (TPair<int, T>& pair : weightList)
		{
			int weight = pair.Key;
			T value = pair.Value;
			total -= weight;
			if (total <= keyWeight)
				return value;
			ret = value;
		}
		return ret;
	}
};
