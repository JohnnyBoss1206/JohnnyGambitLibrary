// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AICondition.generated.h"

/**
 * GambitAI��Gambit����
 * ���̃N���X���p������BP�ŏ����𖞂������ǂ���������s��
 */
UCLASS(Blueprintable, BlueprintType)
class JOHNNYGAMBITLIBRARY_API UAICondition : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "AI Condition")
	bool DoGambitAICondition(const class UGambitAIParameter* my,const TArray<class UGambitAIParameter*>& targetList);
};
