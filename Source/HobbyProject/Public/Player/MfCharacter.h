// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MfCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class HOBBYPROJECT_API AMfCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMfCharacter();

protected:

	//Start 3D camera
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;
	//End 3D camera

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Start movement
	void MoveForward(float InMovement);
	void MoveRight(float InMovement);
	//End movement

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};