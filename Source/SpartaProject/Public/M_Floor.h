#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "M_Floor.generated.h"

UCLASS()
class SPARTAPROJECT_API AM_Floor : public AActor
{
    GENERATED_BODY()

public:
    AM_Floor();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "M_Floor|Components")
    USceneComponent* SceneRoot;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "M_Floor|Components")
    UStaticMeshComponent* StaticMeshComp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "M_Floor|Properties")
    float RotateSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "M_Floor|Move")
    float MoveSecond;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "M_Floor|Move")
    float MoveRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "M_Floor|Move")
    float MoveSpeed;

    FTimerHandle MoveTimerHandle;
    FVector TargetLocation;
    bool bIsMoving;

    UFUNCTION()
    void OnMoveTimer();

public:
    virtual void Tick(float DeltaTime) override;
};