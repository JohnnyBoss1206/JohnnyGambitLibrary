// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GambitUnit.generated.h"

class UGambitData;
/**
 * Gambit Unit
 */
UCLASS()
class JOHNNYGAMBITLIBRARY_API UGambitUnit : public UObject
{
	GENERATED_BODY()
public:
	void AddGambitData();
	void RemoveGambitData();
private:
	TArray<UGambitData> gambitDataArray;
};
