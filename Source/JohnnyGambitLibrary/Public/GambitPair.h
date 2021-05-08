// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GambitPair.generated.h"

/**
 * GambitAIでコレクションクラスをBPで扱うためのクラス
 */
UCLASS(BlueprintType)
class JOHNNYGAMBITLIBRARY_API UGambitPair : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, Category = "Johnny Gambit Utility")
	int key;

	UPROPERTY(VisibleAnywhere, Category = "Johnny Gambit Utility")
	FName valueName;
	
	UPROPERTY(VisibleAnywhere, Category = "Johnny Gambit Utility")
	FString valueString;
	
	UPROPERTY(VisibleAnywhere, Category = "Johnny Gambit Utility")
	UObject* valueObject;
};
