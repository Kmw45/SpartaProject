// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "R_Floor.generated.h"

UCLASS()
class SPARTAPROJECT_API AR_Floor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AR_Floor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="R_Floor|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "R_Floor|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "R_Floor|properties")
	float MovingSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "R_Floor|properties")
	float MaxRange;

	FVector StartLocation;


	virtual void Tick(float DeltaTime) override;

};
