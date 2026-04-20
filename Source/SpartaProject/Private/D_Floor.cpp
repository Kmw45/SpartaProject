#include "D_Floor.h"

AD_Floor::AD_Floor()
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
    DisappearDelay = 3.0f;
    RespawnDelay = 2.0f;
    bEnableRespawn = true;
}

void AD_Floor::BeginPlay()
{
    Super::BeginPlay();

    GetWorldTimerManager().SetTimer(
        DisappearTimerHandle,
        this,
        &AD_Floor::OnDisappearTimer,
        DisappearDelay,
        false
    );
}

void AD_Floor::OnDisappearTimer()
{
    StaticMeshComp->SetVisibility(false);
    StaticMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    if (bEnableRespawn && RespawnDelay > 0.0f)
    {
        GetWorldTimerManager().SetTimer(
            RespawnTimerHandle,
            this,
            &AD_Floor::OnRespawnTimer,
            RespawnDelay,
            false
        );
    }
}

void AD_Floor::OnRespawnTimer()
{
    StaticMeshComp->SetVisibility(true);
    StaticMeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

    GetWorldTimerManager().SetTimer(
        DisappearTimerHandle,
        this,
        &AD_Floor::OnDisappearTimer,
        DisappearDelay,
        false
    );
}

void AD_Floor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!FMath::IsNearlyZero(RotateSpeed))
        AddActorLocalRotation(FRotator(0.0f, RotateSpeed * DeltaTime, 0.0f));
}