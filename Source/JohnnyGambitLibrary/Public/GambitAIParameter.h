// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GambitAIParameter.generated.h"

/**
 * 
 */
UCLASS()
class JOHNNYGAMBITLIBRARY_API UGambitAIParameter : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Gambit AI Parameter")
	int hp;

	UPROPERTY(EditAnywhere, Category = "Gambit AI Parameter")
	int mp;
};
