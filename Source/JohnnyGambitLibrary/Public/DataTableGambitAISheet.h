// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DataTableGambitAISheet.generated.h"

/**
 * GambitAIÇÃê›íËÇçsÇ§ÇΩÇﬂÇÃDataTable
 */
USTRUCT(BlueprintType)
struct JOHNNYGAMBITLIBRARY_API FDataTableGambitAISheet : public FTableRowBase
{
	GENERATED_BODY()
public:
	FDataTableGambitAISheet() {}
public:
	UPROPERTY(EditAnywhere, Category = "Gambit AI")
	TArray<TSubclassOf<class UAICondition>> actionConditionClassList;

	UPROPERTY(EditAnywhere, Category = "Gambit AI")
	FName ActionID;

	UPROPERTY(EditAnywhere, Category = "Gambit AI")
	int priority = 1;

	UPROPERTY(EditAnywhere, Category = "Gambit AI")
	int weight = 10;

	UPROPERTY(EditAnywhere, Category = "Gambit AI")
	TSubclassOf<class UAITargetCondition> targetCondition;
};
