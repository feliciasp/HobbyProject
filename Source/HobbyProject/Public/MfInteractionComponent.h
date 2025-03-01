// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MfInteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HOBBYPROJECT_API UMfInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditDefaultsOnly, Category = "Interaction Properties")
	float InteractionRange;

	// Sets default values for this component's properties
	UMfInteractionComponent();

	void PrimaryInteract();

	//DEBUG OPTIONS
	UPROPERTY(EditDefaultsOnly, Category = "Interaction Debug")
	bool bEnableDebugTraces;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//UPROPERTY(VisibleAnywhere)
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
