#include "M_Floor.h"

AM_Floor::AM_Floor()
{
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
        TEXT("/Game/Fantastic_Dungeon_Pack/meshes/modular/floor/pivotEdge/MOD_Floor_01_E_convex_med_2.MOD_Floor_01_E_convex_med_2"));
    if (MeshAsset.Succeeded())
        StaticMeshComp->SetStaticMesh(MeshAsset.Object);

    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(
        TEXT("/Game/Fantastic_Dungeon_Pack/materials/MI_MOD_Floor_01_v3.MI_MOD_Floor_01_v3"));
    if (MaterialAsset.Succeeded())
        StaticMeshComp->SetMaterial(0, MaterialAsset.Object);

    PrimaryActorTick.bCanEverTick = true;

    RotateSpeed = 50.0f;
    MoveSecond = 2.0f;
    MoveRange = 300.0f;
    MoveSpeed = 150.0f;
    bIsMoving = false;
}

void AM_Floor::BeginPlay()
{
    Super::BeginPlay();

    TargetLocation = GetActorLocation();

    GetWorldTimerManager().SetTimer(
        MoveTimerHandle,
        this,
        &AM_Floor::OnMoveTimer,
        MoveSecond,
        true
    );
}

void AM_Floor::OnMoveTimer()
{
    FVector Current = GetActorLocation();

    float RandomX = FMath::RandRange(-MoveRange, MoveRange);
    float RandomY = FMath::RandRange(-MoveRange, MoveRange);

    TargetLocation = FVector(
        Current.X + RandomX,
        Current.Y + RandomY,
        Current.Z
    );

    bIsMoving = true;
}

void AM_Floor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!FMath::IsNearlyZero(RotateSpeed))
        AddActorLocalRotation(FRotator(0.0f, RotateSpeed * DeltaTime, 0.0f));

    if (bIsMoving)
    {
        FVector Current = GetActorLocation();
        FVector NewLocation = FMath::VInterpTo(
            Current,
            TargetLocation,
            DeltaTime,
            MoveSpeed * 0.01f
        );
        SetActorLocation(NewLocation);

        if (FVector::Dist(NewLocation, TargetLocation) < 1.0f)
            bIsMoving = false;
    }
}
