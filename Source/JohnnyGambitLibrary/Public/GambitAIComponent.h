// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GambitAIComponent.generated.h"

USTRUCT()
struct JOHNNYGAMBITLIBRARY_API FGambitActionInfo
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TArray<class UAICondition*> aiConditions;
	FName actionID;
	int priority = 0;
	int weight = 0;

	bool operator==(const FGambitActionInfo& Other)const
	{
		return this->aiConditions == Other.aiConditions &&
			this->actionID == Other.actionID &&
			this->priority == Other.priority &&
			this->weight == Other.weight;
	}
	bool operator!=(const FGambitActionInfo& Other)const
	{
		return !(this == &Other);
	}
	FGambitActionInfo& operator=(const FGambitActionInfo& Other)
	{
		if (this != &Other)
		{
			this->aiConditions = Other.aiConditions;
			this->actionID = Other.actionID;
			this->priority = Other.priority;
			this->weight = Other.weight;
		}
		return *this;
	}
	
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JOHNNYGAMBITLIBRARY_API UGambitAIComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGambitAIComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void InitializeAI(class UDataTable* actionList);

	FGambitActionInfo GetCurrentAction()const {return currentGambitAction;}

public:
	void ThinkAction(const UGambitAIParameter* my, const TArray<class UGambitAIParameter*>& targetArray);

protected:
	UPROPERTY()
	TArray<FGambitActionInfo> actionTable;

	UPROPERTY()
	FGambitActionInfo currentGambitAction;

};
