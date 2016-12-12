// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "IPlatFormFilePak.h"
#include "GameFramework/Actor.h"
#include "PakResourceTestLoader.generated.h"

UCLASS()
class PAKTESTER_API APakResourceTestLoader : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APakResourceTestLoader();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	void Test();
	void Load(const FString & pakName);
private:
	FPakPlatformFile * m_PakPlatformFile;
	FStreamableManager * m_Stream;
};
