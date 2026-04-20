// Fill out your copyright notice in the Description page of Project Settings.


#include "RY_Floor.h"

// Sets default values
ARY_Floor::ARY_Floor()
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

	MovingSpeed = 400.0f;

	MaxRange = 400.0f;
}

// Called when the game starts or when spawned
void ARY_Floor::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void ARY_Floor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(MovingSpeed))
	{
		AddActorLocalOffset(FVector(0.0f, MovingSpeed * DeltaTime, 0.0f));

		if (GetActorLocation().Y > MaxRange)
		{
			MovingSpeed = -FMath::Abs(MovingSpeed); 
		}
		else if (GetActorLocation().Y < -MaxRange)
		{
			MovingSpeed = FMath::Abs(MovingSpeed);  
		}
	}

}

