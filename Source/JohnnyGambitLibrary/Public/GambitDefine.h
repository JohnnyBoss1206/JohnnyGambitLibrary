// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

//UENUM(BlueprintType)
enum class EGAMBIT_TARGET : uint8
{
	NONE,
	OPPOSITION,
	SELF,
	SELF_PT,
	FIELD
};

enum class EGAMBIT_COND : uint8
{
	NONE,
	LOWER,
	HIGHER,
	EQUALS,
	INEQUALS,
	MAX,
	MIN
};


