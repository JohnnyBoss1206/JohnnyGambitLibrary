// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

//UENUM(BlueprintType)
enum  EGAMBIT_TARGET : uint8
{
	OPPOSITION,
	SELF,
	SELF_PT,
	FIELD
};

enum EGAMBIT_COND : uint8
{
	LOWER,
	HIGHER,
	EQUALS,
	INEQUALS,
	MAX,
	MIN
};


