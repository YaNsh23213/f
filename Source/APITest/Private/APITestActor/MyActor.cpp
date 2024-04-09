// Fill out your copyright notice in the Description page of Project Settings.


#include "APITestActor/MyActor.h"
#include "Http.h"

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	InitGetRequest();
}

void AMyActor::InitGetRequest()
{
	FHttpRequestPtr Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &AMyActor::OnResponseGetRequest);
	Request->SetURL("http://localhost:3000/auth/login");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void AMyActor::InitPostRequest()
{
	FHttpRequestPtr Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &AMyActor::OnResponsePostRequest);
	Request->SetURL("http://localhost:3000/auth/check");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void AMyActor::OnResponseGetRequest(FHttpRequestPtr Requset, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	Response->GetAllHeaders();
	UE_LOG(LogTemp, Display, TEXT("OnResponseGetRequest %s"), *Response->GetContentAsString());
	int32 i = 0;
	for (auto Element : Response->GetAllHeaders())
	{
		UE_LOG(LogTemp, Display, TEXT("GetAllHeaders %i %s"), i, *Element);
		i++;
	}
	InitPostRequest();
}

void AMyActor::OnResponsePostRequest(FHttpRequestPtr Requset, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	UE_LOG(LogTemp, Display, TEXT("OnResponsePostRequest %s"), *Response->GetContentAsString());
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

