// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AITargetCondition.generated.h"

/**
 * GambitAI��Gambit�����^�[�Q�b�g�擾�N���X
 * ���̃N���X���p������BP�ŏ����𖞂������ǂ���������s��
 */
UCLASS(Blueprintable, BlueprintType)
class JOHNNYGAMBITLIBRARY_API UAITargetCondition : public UObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "AI Condition")
	FName GetGambitTargetID(const class UGambitAIParameter* my, const TArray<class UGambitAIParameter*>& targetList);

};
