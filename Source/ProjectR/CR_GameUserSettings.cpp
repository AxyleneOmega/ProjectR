// Fill out your copyright notice in the Description page of Project Settings.


#include "CR_GameUserSettings.h"

UCR_GameUserSettings::UCR_GameUserSettings(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	AimFalloffRadius = 500.f;
	AimLerpStrength = 1.f;
}

UCR_GameUserSettings* UCR_GameUserSettings::GetCR_GameUserSettings()
{
	return Cast<UCR_GameUserSettings>(UGameUserSettings::GetGameUserSettings());
}

void UCR_GameUserSettings::SetIsAimAssistEnabled(bool isEnabled)
{
	bAimAssistEnabled = isEnabled;
}

bool UCR_GameUserSettings::GetIsAimAssistEnabled() const
{
	return bAimAssistEnabled;
}

float UCR_GameUserSettings::GetAimFalloffRadius() const
{
	return AimFalloffRadius;
}

float UCR_GameUserSettings::GetAimLerpStrength() const
{
	return AimLerpStrength;
}

void UCR_GameUserSettings::SetAimFalloffRadius(float NewAimFalloffRadius)
{
	AimFalloffRadius = NewAimFalloffRadius;
}

void UCR_GameUserSettings::SetAimLerpStrength(float NewAimLerpStrength)
{
	AimLerpStrength = NewAimLerpStrength;
}
