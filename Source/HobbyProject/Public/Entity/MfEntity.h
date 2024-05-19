// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "MfGameplayInterface.h"

//generated include should always be at bottom
#include "MfEntity.generated.h"

class UBoxComponent;
class UWidgetComponent;

UCLASS()
class HOBBYPROJECT_API AMfEntity : public ACharacter, public IMfGameplayInterface
{
	GENERATED_BODY()

	//We gotta add out function for the interface that should be triggered when Interact is called. _Implementation because native event stuff
	void Interact_Implementation(APawn* InstigatorPawn);

public:
	// Sets default values for this character's properties
	AMfEntity();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Entity Properties")
	float Restoration;

	UPROPERTY(BlueprintReadOnly, Category = "Entity Properties")
	bool bIsInteractable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> InteractionVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UWidgetComponent> InteractionWidget;
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

	UFUNCTION()
	void OnVolumeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnVolumeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:	

	UFUNCTION(BlueprintCallable, Category = "MF Attributes")
	bool ApplyRestorationChange(float Delta);

	UFUNCTION(BlueprintCallable, Category = "MF Attributes")
	float GetRestoration();

	// Called every frame
	//virtual void Tick(float DeltaTime) override;

};
