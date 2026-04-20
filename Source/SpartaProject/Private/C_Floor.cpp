// Fill out your copyright notice in the Description page of Project Settings.


#include "C_Floor.h"

// Sets default values
AC_Floor::AC_Floor()
{

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);


	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Fantastic_Dungeon_Pack/meshes/modular/floor/pivotEdge/MOD_Floor_01_E_convex_med_2.MOD_Floor_01_E_convex_med_2"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Fantastic_Dungeon_Pack/materials/MI_MOD_Floor_01_v3.MI_MOD_Floor_01_v3"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RotateSpeed = 50.0f;

}

// Called when the game starts or when spawned
void AC_Floor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AC_Floor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotateSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotateSpeed * DeltaTime, 0.0f));
	}



}

