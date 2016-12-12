// Fill out your copyright notice in the Description page of Project Settings.

#include "PakTester.h"
#include "PakResourceTestLoader.h"

APakResourceTestLoader::APakResourceTestLoader()
	: m_PakPlatformFile(new FPakPlatformFile)
	, m_Stream(new FStreamableManager) {

	PrimaryActorTick.bCanEverTick = true;

	IPlatformFile& InnerPlatform = FPlatformFileManager::Get().GetPlatformFile();
	m_PakPlatformFile->Initialize(&InnerPlatform, TEXT(""));
	FPlatformFileManager::Get().SetPlatformFile(*m_PakPlatformFile);
}

void APakResourceTestLoader::Load(const FString & pakName) {
	auto pakPath = FPaths::GamePersistentDownloadDir() / pakName + ".pak";
	auto mountingPath = FPaths::GamePersistentDownloadDir() / pakName;
	m_PakPlatformFile->Mount(*pakPath, 0, *mountingPath);


	//auto readFilePath = FPaths::GamePersistentDownloadDir() / "NewBlueprint.uasset";
	//auto readFileHandle = m_PakPlatformFile->OpenRead(*readFilePath, false);


	TSet<FString> fileList;
	IPlatformFile& InnerPlatform = FPlatformFileManager::Get().GetPlatformFile();
	FPakFile PakFile(&InnerPlatform, *pakPath, false);
	PakFile.FindFilesAtPath(fileList, *PakFile.GetMountPoint(), true, false, true);
	for (auto & ele : fileList) {
		FString assetShortName = FPackageName::GetShortName(ele);
		//assetShortName.RemoveFromEnd(FPackageName::GetAssetPackageExtension());
		ele = FPaths::GamePersistentDownloadDir() / pakName / assetShortName;  // +TEXT(".") + assetShortName;
	}
	for (const auto & target : fileList) {
		m_Stream->SynchronousLoad(target);
	}
}

void APakResourceTestLoader::Test() {
	//auto pakName = "targetPak";
	//Load(pakName);

	//auto readFilePath = FPaths::GamePersistentDownloadDir() / pakName / "TestActor.uasset";
	//auto readFileHandle = m_PakPlatformFile->OpenRead(*readFilePath, false);

	//int PacketSize = 1000;
	//uint8* buffer = new uint8[PacketSize];
	//bool result = readFileHandle->Read(buffer, PacketSize);
	//UE_LOG(LogTemp, Log, TEXT("read result: %d"), result? 1:0);

}

void APakResourceTestLoader::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("APakResourceTestLoader::BeginPlay() 1"))
	Test();
}

void APakResourceTestLoader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}




// Called when the game starts or when spawned
//void APakResourceTestLoader::BeginPlay()
//{
//Super::BeginPlay();
//FPakPlatformFile::CreatePakFileHandle
//IFileHandle* FPakPlatformFile::CreatePakFileHandle(const TCHAR* Filename,
//FPakFile* PakFile, 
//	const FPakEntry* FileEntry)
//https://answers.unrealengine.com/questions/454847/can-not-load-encrypted-pak-files.html


//IFileHandle* FPakPlatformFile::OpenRead(const TCHAR* Filename, bool bAllowWrite)

//m_PakPlatformFile->CreatePakFileHandle();
//m_PakPlatformFile->

//auto pakPath = FPaths::GameContentDir() + "MyProject2-WindowsNoEditor" + ".pak";
//auto mountingPath = FPaths::GameContentDir();
//m_PakPlatformFile->Mount(*pakPath, 0, *mountingPath);
////auto mountingPath = FPaths::EngineContentDir() + "test" + "/";
//auto readFilePath = FPaths::GameContentDir() + "MyProject2/Content/NewBlueprint.uasset";

////	virtual bool		Read(uint8* Destination, int64 BytesToRead) = 0;
//auto readFileHandle = m_PakPlatformFile->OpenRead(*readFilePath, false);
//int PacketSize = 1000;
//uint8* buffer = new uint8[PacketSize];
//bool result = readFileHandle->Read(buffer, PacketSize);

//UE_LOG(LogTemp, Log, TEXT("======%d"), result? 1:0);
//}