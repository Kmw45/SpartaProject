// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RY_Floor.generated.h"

UCLASS()
class SPARTAPROJECT_API ARY_Floor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARY_Floor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RY_Floor|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RY_Floor|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "RY_Floor|properties")
	float MovingSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "RY_Floor|properties")
	float MaxRange;


	virtual void Tick(float DeltaTime) override;

};
