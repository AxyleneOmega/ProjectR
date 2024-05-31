// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS_Character.h"
#include "AbilitySystemComponent.h"
#include "CharacterAttributeSet.h"

// Sets default values
AGAS_Character::AGAS_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	CharacterType.AddTag(FGameplayTag::EmptyTag);
	CharacterState.AddTag(FGameplayTag::EmptyTag);
}

// Called when the game starts or when spawned
void AGAS_Character::BeginPlay()
{
	Super::BeginPlay();

	if(IsValid(AbilitySystemComponent)) {
		CharacterAttributeSet = AbilitySystemComponent->GetSet<UCharacterAttributeSet>();
	}
	
}

AActor* AGAS_Character::DistancesToActors(FVector Origin, const TArray<AActor*>& ActorsToCheck, float& SecondDistance, AActor*& SecondActor, float& ReturnValueDistance)
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

// Called every frame
void AGAS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGAS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FGameplayTagContainer AGAS_Character::GetCharacterType() const { return CharacterType; }

FGameplayTagContainer AGAS_Character::GetCharacterState() const { return CharacterState; }
