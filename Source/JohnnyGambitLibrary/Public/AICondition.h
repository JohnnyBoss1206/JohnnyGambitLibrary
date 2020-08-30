// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AICondition.generated.h"

class UGambitAIComponent;
/**
 * 
 */
UCLASS()
class JOHNNYGAMBITLIBRARY_API UAICondition : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent, Category = "AI Condition")
	bool DoActionCondition(const UGambitAIComponent* my,const TArray<UGambitAIComponent*>& targetList);
};
