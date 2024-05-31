// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "CR_GameUserSettings.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTR_API UCR_GameUserSettings : public UGameUserSettings
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "CR|Settings")
	static UCR_GameUserSettings* GetCR_GameUserSettings();	
	UFUNCTION(BlueprintPure, Category = "CR|Aim|Config")
	bool GetIsAimAssistEnabled() const;

	UFUNCTION(BlueprintCallable, Category = "CR|Aim|Config")
	void SetAimFalloffRadius(float NewAimFalloffRadius);
	UFUNCTION(BlueprintPure, Category = "CR|Aim|Config")
	float GetAimFalloffRadius() const;

	UFUNCTION(BlueprintCallable, Category = "CR|Aim|Config")
	void SetAimLerpStrength(float NewAimLerpStrength);
	UFUNCTION(BlueprintPure, Category = "CR|Aim|Config")
	float GetAimLerpStrength() const;

private:
	UFUNCTION(BlueprintCallable, Category = "CR|Aim|Config")
	void SetIsAimAssistEnabled(bool isEnabled);

	UPROPERTY(VisibleAnywhere, Config, Category = "CR|Aim|Config")
	bool bAimAssistEnabled = false;

	UPROPERTY(VisibleAnywhere, Config, Category = "CR|Aim|Config")
	float AimFalloffRadius;

	UPROPERTY(VisibleAnywhere, Config, Category = "CR|Aim|Config")
	float AimLerpStrength;
};
