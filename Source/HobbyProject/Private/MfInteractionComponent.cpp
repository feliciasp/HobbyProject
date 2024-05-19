// Fill out your copyright notice in the Description page of Project Settings.


#include "MfInteractionComponent.h"
#include "MfGameplayInterface.h"

// Sets default values for this component's properties
UMfInteractionComponent::UMfInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	IsInteractable = false;
	InteractionRange = 300.0f;
	// ...
}


// Called when the game starts
void UMfInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMfInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMfInteractionComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	//gets player character 
	AActor* Owner = GetOwner();

	FCollisionQueryParams QueryParams(FName(TEXT("TraceParams")), true, Owner);

	FVector Start = Owner->GetActorLocation();
	Start = Start - FVector(0.0f, 0.0f, 15.0f);
	FVector End = Start + Owner->GetActorRotation().Vector() * InteractionRange;
	//.Vector gives direction vector

	TArray<FHitResult> Hits;
	//looking for things that are world dynamic atm. We could do a custom channel instead for interactable.
	//GetWorld()->LineTraceSingleByObjectType(Hit, Start, End, ObjectQueryParams);
	float Radius = 50.0f;
	FCollisionShape Shape;
	Shape.SetSphere(Radius);
	//sweep "sweeps" a geo shape along line and return all traces
	GetWorld()->SweepMultiByObjectType(Hits, Start, End, FQuat::Identity, ObjectQueryParams, Shape, QueryParams);

	for (FHitResult Hit : Hits)
	{
		//DrawDebugSphere(GetWorld(), Hit.ImpactPoint, Radius, 32, FColor::Red, false, 2.0f);
		AActor* HitActor = Hit.GetActor();
		if (HitActor)
		{
			if (HitActor->Implements<UMfGameplayInterface>())
			{
				APawn* Pawn = Cast<APawn>(Owner);
				//syntax for interface function calls
				IMfGameplayInterface::Execute_Interact(HitActor, Pawn);
				break;
			}
		}
	}

	//DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 2.0f, 0, 2.0f);
}
