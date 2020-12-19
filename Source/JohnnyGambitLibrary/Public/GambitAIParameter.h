// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GambitAIParameter.generated.h"

/**
 * GambitAIで条件判定を行う際のパラメータを保持するクラス
 * このクラスをゲーム内のActorクラスが保持してもらう
 */
UCLASS(BlueprintType)
class JOHNNYGAMBITLIBRARY_API UGambitAIParameter : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Gambit AI Parameter")
	void SetParameter(const FName& key, const FString& value);

	UFUNCTION(BlueprintCallable, Category = "Gambit AI Parameter")
	int GetValueToInt(const FName& key) { return HasKey(key) ? FCString::Strtoi(*parameterMap[key],nullptr,10) : -1; }

	UFUNCTION(BlueprintCallable, Category = "Gambit AI Parameter")
	float GetValueToFloat(const FName& key) { return HasKey(key) ? FCString::Strtoi(*parameterMap[key],nullptr,10) : -1.f; }

	UFUNCTION(BlueprintCallable, Category = "Gambit AI Parameter")
	FString GetValueToString(const FName& key) { return HasKey(key) ? parameterMap[key] : FString(); }

	UFUNCTION(BlueprintCallable, Category = "Gambit AI Parameter")
	bool HasKey(const FName& key)const { return parameterMap.Contains(key); }

	UFUNCTION(BlueprintCallable, Category = "Gambit AI Parameter")
	TMap<FName, FString> GetParameterMap()const { return parameterMap; }

protected:
	UPROPERTY(EditAnywhere, Category = "Gambit AI Parameter")
	TMap<FName,FString> parameterMap;
};
