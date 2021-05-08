// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GambitAIParameter.h"
#include "GambitPair.h"
#include "JohnnyGambitUtility.generated.h"

/**
 * GambitAIに限らずAIに関連する便利Utilityクラス
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

	UFUNCTION(BlueprintCallable, Category = "Gambit AI Utility")
	static FName CalcWeightRateFromName(const TArray<UGambitPair*>& weightList, int totalWeight)
	{
		TArray<TPair<int, FName>> tmpWeightList;
		for (auto& pairObj : weightList)
		{
			TPair<int, FName> newPair;
			newPair.Key = pairObj->key;
			newPair.Value = pairObj->valueName;
			tmpWeightList.Add(newPair);
		}
		return CalcWeightRate(tmpWeightList, totalWeight);
	}

	UFUNCTION(BlueprintCallable, Category = "Gambit AI Utility")
	static FString CalcWeightRateFromString(const TArray<UGambitPair*>& weightList, int totalWeight)
	{
		TArray<TPair<int, FString>> tmpWeightList;
		for (auto& pairObj : weightList)
		{
			TPair<int, FString> newPair;
			newPair.Key = pairObj->key;
			newPair.Value = pairObj->valueString;
			tmpWeightList.Add(newPair);
		}
		return CalcWeightRate(tmpWeightList, totalWeight);
	}

	UFUNCTION(BlueprintCallable, Category = "Gambit AI Utility")
	static UObject* CalcWeightRateFromObject(const TArray<UGambitPair*>& weightList, int totalWeight)
	{
		TArray<TPair<int, UObject*>> tmpWeightList;
		for (auto& pairObj : weightList)
		{
			TPair<int, UObject*> newPair;
			newPair.Key = pairObj->key;
			newPair.Value = pairObj->valueObject;
			tmpWeightList.Add(newPair);
		}
		return CalcWeightRate(tmpWeightList, totalWeight);
	}

	UFUNCTION(BlueprintCallable, Category = "Gambit AI Utility")
	static int GetTotalWeightForBP(const TArray<UGambitPair*>& weightList)
	{
		TArray<TPair<int, FName>> tmpWeightList;//Total値計算なのでValue値はなんでもいい
		for (auto& pairObj : weightList)
		{
			TPair<int, FName> newPair;
			newPair.Key = pairObj->key;
			tmpWeightList.Add(newPair);
		}
		return GetTotalWeight(tmpWeightList);
	}

	UFUNCTION(BlueprintCallable, Category = "Gambit AI Utility")
	static int AdjustWeightForBP(const TArray<UGambitPair*>& weightList)
	{
		TArray<TPair<int, FName>> tmpWeightList;//AdjustするだけなのでValue値はなんでもいい
		for (auto& pairObj : weightList)
		{
			TPair<int, FName> newPair;
			newPair.Key = pairObj->key;
			tmpWeightList.Add(newPair);
		}
		return GetTotalWeight(tmpWeightList);
	}
};
