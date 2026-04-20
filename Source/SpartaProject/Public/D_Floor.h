#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "D_Floor.generated.h"

UCLASS()
class SPARTAPROJECT_API AD_Floor : public AActor
{
    GENERATED_BODY()

public:
    AD_Floor();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "D_Floor|Components")
    USceneComponent* SceneRoot;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "D_Floor|Components")
    UStaticMeshComponent* StaticMeshComp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "D_Floor|Properties")
    float RotateSpeed;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "D_Floor|Disappear")
    float DisappearDelay;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "D_Floor|Disappear")
    float RespawnDelay;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "D_Floor|Disappear")
    bool bEnableRespawn;

    FTimerHandle DisappearTimerHandle;
    FTimerHandle RespawnTimerHandle;

    UFUNCTION()
    void OnDisappearTimer();

    UFUNCTION()
    void OnRespawnTimer();

public:
    virtual void Tick(float DeltaTime) override;
};