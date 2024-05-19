// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MfCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UMfInteractionComponent;

UCLASS()
class HOBBYPROJECT_API AMfCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMfCharacter();

protected:

	//Start 3D camera
	UPROPERTY(BlueprintReadWrite)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;
	//End 3D camera

	UPROPERTY(VisibleAnywhere)
	UMfInteractionComponent* InteractionComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Start movement
	void MoveForward(float InMovement);
	void MoveRight(float InMovement);
	//End movement
	void PrimaryInteract();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
