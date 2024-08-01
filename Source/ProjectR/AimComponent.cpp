// Fill out your copyright notice in the Description page of Project Settings.


#include "AimComponent.h"

// Sets default values for this component's properties
UAimComponent::UAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAimComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AActor* UAimComponent::DistancesToActors(FVector Origin, const TArray<AActor*>& ActorsToCheck, float& SecondDistance, AActor*& SecondActor, float& ReturnValueDistance)
{
	//Nearest Actor = NA
	//Distance to Actor = DNA
	AActor* NA1 = nullptr;
	AActor* NA2 = SecondActor = nullptr;
	float DNA1 = ReturnValueDistance = TNumericLimits<float>::Max();
	float DNA2 = SecondDistance = TNumericLimits<float>::Max();

	for (AActor* ActorToCheck : ActorsToCheck)
	{
		if (ActorToCheck)
		{
			const float DistanceFromActorToCheck = (Origin - ActorToCheck->GetActorLocation()).SizeSquared();
			if (DistanceFromActorToCheck < DNA1)
			{
				DNA2 = DNA1;						SecondActor = NA2 = NA1;
				DNA1 = DistanceFromActorToCheck; 	NA1 = ActorToCheck;
			}
			else if (DistanceFromActorToCheck < DNA2) {
				DNA2 = DistanceFromActorToCheck;	NA2 = ActorToCheck;
			}
		}
	}

	if (NA1)
	{
		ReturnValueDistance = FMath::Sqrt(DNA1);
	}
	if (NA2)
	{
		SecondDistance = FMath::Sqrt(DNA2);
	}

	return NA1;
}