// Fill out your copyright notice in the Description page of Project Settings.


#include "GambitAIParameter.h"

void UGambitAIParameter::SetParameter(const FName& key, const FString& value)
{
	if (parameterMap.Contains(key))
	{
		parameterMap[key] = value;
	}
	else
	{
		parameterMap.Add(key, value);
	}
}