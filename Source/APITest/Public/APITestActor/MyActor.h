// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Http.h"
#include "MyActor.generated.h"

UCLASS()
class APITEST_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActor();

protected:
	virtual void BeginPlay() override;

	void InitGetRequest();
	void InitPostRequest();

	void OnResponseGetRequest(FHttpRequestPtr Requset, FHttpResponsePtr Response, bool bConnectedSuccessfully);
	void OnResponsePostRequest(FHttpRequestPtr Requset, FHttpResponsePtr Response, bool bConnectedSuccessfully);

public:	
	virtual void Tick(float DeltaTime) override;

};
