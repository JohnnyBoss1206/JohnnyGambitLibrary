// Fill out your copyright notice in the Description page of Project Settings.


#include "GambitAIComponent.h"
#include "AICondition.h"
#include "DataTableGambitAISheet.h"
#include "GambitAIParameter.h"
#include "JohnnyGambitUtility.h"

// Sets default values for this component's properties
UGambitAIComponent::UGambitAIComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGambitAIComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGambitAIComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGambitAIComponent::InitializeAI(UDataTable* actionList)
{
	actionTable.Empty();
	actionList->ForeachRow<FDataTableGambitAISheet>(TEXT(__FILE__), [&](const FName& Index,const FDataTableGambitAISheet& Sheet)
		{
			FGambitActionInfo info;
			TArray<TSubclassOf<UAICondition>> actCondList = Sheet.actionConditionClassList;
			for (auto condClass : actCondList)
			{
				UAICondition* condInstance = NewObject<UAICondition>(condClass);
				if (condInstance != nullptr)
				{
					info.aiConditions.Add(condInstance);
				}
			}
			info.actionID = Sheet.ActionID;
			info.priority = Sheet.priority;
			info.weight = Sheet.weight;
			actionTable.Add(info);
		});
	actionTable.Sort([](const FGambitActionInfo& A, const FGambitActionInfo& B) 
		{
			return A.priority > B.priority;
		});
}

void UGambitAIComponent::ThinkAction(const UGambitAIParameter* my,const TArray<UGambitAIParameter*>& targetArray)
{
	TArray<FGambitActionInfo> lotTable;
	int currentPriority = 0;
	
	for (FGambitActionInfo& action : actionTable)
	{
		//�D��x���Ⴍ�Ȃ�lotTable�ɒl�������Ă���Β��o�I��
		if (currentPriority > action.priority && lotTable.Num() > 0)
			break;
		currentPriority = action.priority;
		lotTable.Add(action);

		for (UAICondition* cond : action.aiConditions)
		{
			if (!cond->DoAICondition(my, targetArray))
			{
				lotTable.Remove(action);
				break;
			}
		}
	}
	if (lotTable.Num() == 0)
	{
		FGambitActionInfo info;
		info.actionID = TEXT("NONE");
		currentGambitAction = info;
	}
	TArray<TPair<int, FGambitActionInfo>> weightList;
	for (const FGambitActionInfo& action : lotTable)
	{
		TPair<int, FGambitActionInfo> pair;
		pair.Key = action.weight;
		pair.Value = action;
		weightList.Add(pair);
	}
	UJohnnyGambitUtility::AdjustWeight(weightList);
	int totalWeitght = UJohnnyGambitUtility::GetTotalWeight(weightList);
	currentGambitAction = UJohnnyGambitUtility::CalcWeightRate(weightList,totalWeitght);
}