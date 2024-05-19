// Fill out your copyright notice in the Description page of Project Settings.


#include "Entity/MfEntity.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"

// Sets default values
AMfEntity::AMfEntity()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	//Restoration = 0.0;
	InteractionVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractionVolume"));
	InteractionVolume->SetupAttachment(RootComponent);
	InteractionVolume->SetCollisionResponseToAllChannels(ECR_Ignore);
	InteractionVolume->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);

	InteractionVolume->OnComponentBeginOverlap.AddDynamic(this, &AMfEntity::OnVolumeBeginOverlap);
	InteractionVolume->OnComponentEndOverlap.AddDynamic(this, &AMfEntity::OnVolumeEndOverlap);

	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractionWidget"));
	InteractionWidget->SetupAttachment(RootComponent);

	bIsInteractable = false;
}

//// Called when the game starts or when spawned
//void AMfEntity::BeginPlay()
//{
//	Super::BeginPlay();
//}
//
//// Called every frame
//void AMfEntity::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void AMfEntity::Interact_Implementation(APawn* InstigatorPawn)
{
	//This will be overriden by blueprint function
}

void AMfEntity::OnVolumeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == this)
		return;

	bIsInteractable = true;
	InteractionWidget->SetVisibility(true);
}

void AMfEntity::OnVolumeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == this)
		return;

	bIsInteractable = false;
	InteractionWidget->SetVisibility(false);
}

bool AMfEntity::ApplyRestorationChange(float Delta)
{
	Restoration += Delta;
	return true;
}

float AMfEntity::GetRestoration()
{
	return Restoration;
}