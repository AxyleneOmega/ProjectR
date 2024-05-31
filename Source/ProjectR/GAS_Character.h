// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagsClasses.h"
#include "GAS_Character.generated.h"

// Interface to get Character State
UINTERFACE(meta = (CannotImplementInterfaceInBlueprint))
class UCharacterStateInterface : public UInterface
{
	GENERATED_BODY()
};

class PROJECTR_API ICharacterStateInterface {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "GAS|Character" )
	virtual FGameplayTagContainer GetCharacterType() const = 0;

	UFUNCTION(BlueprintCallable, Category = "GAS|Character" )
	virtual FGameplayTagContainer GetCharacterState() const = 0;
};


UCLASS()
class PROJECTR_API AGAS_Character : public ACharacter, public IAbilitySystemInterface, public ICharacterStateInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGAS_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GAS", meta = (AllowPrivateAccess="true"))
	class UAbilitySystemComponent* AbilitySystemComponent;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override {
		return AbilitySystemComponent;
	}

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS|Character", meta = (AllowPrivateAccess = "true"))
	const class UCharacterAttributeSet* CharacterAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GAS|Character", meta = (AllowPrivateAccess = "true"))
	FGameplayTagContainer CharacterState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS|Character", meta = (AllowPrivateAccess = "true"))
	FGameplayTagContainer CharacterType;

	UFUNCTION(BlueprintPure, Category = "CR|Aim")
	AActor* DistancesToActors(FVector Origin, const TArray<AActor*>& ActorsToCheck, float& SecondDistance, AActor*& SecondActor, float& ReturnValueDistance);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual FGameplayTagContainer GetCharacterType() const override;

	virtual FGameplayTagContainer GetCharacterState() const override;
};
