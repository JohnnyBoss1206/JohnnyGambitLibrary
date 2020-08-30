// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GambitAIActor.generated.h"

UCLASS()
class JOHNNYGAMBITLIBRARY_API AGambitAIActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGambitAIActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, Category = "Gambit AI")
	class UGambitAIComponent* GetGambitAIComponent()const {return gambitAIComponent;}

protected:
	UPROPERTY(VisibleAnywhere, Category = "Gambit AI")
	class UGambitAIComponent* gambitAIComponent;

};
