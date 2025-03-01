// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MfCharacter.h"

//comp includes
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MfInteractionComponent.h"
#include "Player/Encyclopedia/MfEncyclopedia.h"

// Sets default values
AMfCharacter::AMfCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initialize comps 
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	InteractionComp = CreateDefaultSubobject<UMfInteractionComponent>("InteractionComp");

	BaseEyeHeight = 50.0f;
}

// Called when the game starts or when spawned
void AMfCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMfCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMfCharacter::MoveForward(float InMovement)
{
	if(!bDisableMovement)
		AddMovementInput(GetActorForwardVector(), InMovement);
}

void AMfCharacter::MoveRight(float InMovement)
{
	if (!bDisableMovement)
		AddMovementInput(GetActorRightVector(), InMovement);
}

// Called to bind functionality to input
void AMfCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Basic axis movement
	PlayerInputComponent->BindAxis("MoveForward", this, &AMfCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMfCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);

	PlayerInputComponent->BindAction("PrimaryInteract", IE_Pressed, this, &AMfCharacter::PrimaryInteract);
}

void AMfCharacter::PrimaryInteract()
{
	if (InteractionComp)
	{
		InteractionComp->PrimaryInteract();
	}
}