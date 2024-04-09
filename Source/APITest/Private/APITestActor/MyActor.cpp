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
	InitPostRequest();
}

void AMyActor::InitGetRequest()
{
	FHttpRequestPtr Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &AMyActor::OnResponseGetRequest);
	FString GetToken = "";
	Request->SetURL("https://core.gamirare.com/auth/login");
	Request->SetVerb("GET");
	Request->SetHeader("Authorization", GetToken);
	Request->ProcessRequest();
}

void AMyActor::InitPostRequest()
{
	FHttpRequestPtr Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &AMyActor::OnResponsePostRequest);
	FString JsonString = "";
	Request->SetURL("https://core.gamirare.com/auth/login");
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(JsonString);
	Request->ProcessRequest();
}

void AMyActor::OnResponseGetRequest(FHttpRequestPtr Requset, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	
	UE_LOG(LogTemp, Display, TEXT("OnResponseGetRequest %s"), *Response->GetContentAsString());
}

void AMyActor::OnResponsePostRequest(FHttpRequestPtr Requset, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	UE_LOG(LogTemp, Display, TEXT("OnResponsePostRequest %s"), *Response->GetContentAsString());
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

