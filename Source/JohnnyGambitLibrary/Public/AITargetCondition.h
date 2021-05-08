// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AITargetCondition.generated.h"

/**
 * GambitAIのGambitが持つターゲット取得クラス
 * このクラスを継承したBPで条件を満たすかどうか判定を行う
 */
UCLASS(Blueprintable, BlueprintType)
class JOHNNYGAMBITLIBRARY_API UAITargetCondition : public UObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "AI Condition")
	FName GetGambitTargetID(const class UGambitAIParameter* my, const TArray<class UGambitAIParameter*>& targetList);

};
