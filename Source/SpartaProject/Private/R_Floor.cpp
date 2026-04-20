// Fill out your copyright notice in the Description page of Project Settings.


#include "R_Floor.h"

// Sets default values
AR_Floor::AR_Floor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Fantastic_Dungeon_Pack/meshes/modular/floor/pivotEdge/MOD_Floor_01_E_straight_tiny.MOD_Floor_01_E_straight_tiny"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Fantastic_Dungeon_Pack/materials/MI_MOD_Floor_01_v3.MI_MOD_Floor_01_v3"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	MovingSpeed = 300.0f;

	MaxRange = 300.0f;
}

// Called when the game starts or when spawned
void AR_Floor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

}

// Called every frame
void AR_Floor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(MovingSpeed))
	{
		AddActorLocalOffset(FVector(MovingSpeed * DeltaTime, 0.0f, 0.0f));

		float FloorX = GetActorLocation().X - StartLocation.X;

		if (FloorX > MaxRange)
		{
			MovingSpeed = -FMath::Abs(MovingSpeed);
		}
		else if (FloorX < -MaxRange)
		{
			MovingSpeed = FMath::Abs(MovingSpeed);
		}
	}

}

