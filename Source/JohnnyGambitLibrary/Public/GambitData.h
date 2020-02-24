// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GambitData.generated.h"

enum EGAMBIT_TARGET;
enum EGAMBIT_COND;

/**
 * 
 */
UCLASS()
class JOHNNYGAMBITLIBRARY_API UGambitData : public UObject
{
	GENERATED_BODY()
private:
	EGAMBIT_TARGET target;
	EGAMBIT_COND formula;


	FString parameterTypes;

	TFunction<void(void)> action;
};
