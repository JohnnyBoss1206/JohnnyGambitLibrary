// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GambitData.generated.h"

/**
 * 
 */
UCLASS()
class JOHNNYGAMBITLIBRARY_API UGambitData : public UObject
{
	GENERATED_BODY()
private:
	FString condition;
	TFunction<void(void)> action;
};
