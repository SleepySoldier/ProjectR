// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageSystem/DamageSystemComponent.h"


UDamageSystemComponent::UDamageSystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UDamageSystemComponent::InitDamageSystem()
{
	OnHealthChanged.Broadcast(Health / MaxHealth);
}

void UDamageSystemComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

float UDamageSystemComponent::Heal(const float Amount)
{
	if (!bIsDead)
	{
		Health = FMath::Min(Health += Amount, MaxHealth);
	}
	return Health;
}

bool UDamageSystemComponent::TakeDamage(const FDamageInfo DamageInfo)
{
			//Can we be damaged at all	
	if (!bIsDead && !bIsInvincible || DamageInfo.bShouldDamageInvincible)
	{		//Block or full parry
		if (bIsBlocking && DamageInfo.bCanBeBlocked)
		{
			OnBlocked.Broadcast(DamageInfo.bCanBeParried, DamageInfo.DamageCauser);
			return false;
		}
		else // Take full damage, die or stagger?
		{
			Health = FMath::Max(Health - DamageInfo.Amount, 0.f);
			//Broadcast Changes mostly for UI updates. 
			OnHealthChanged.Broadcast(Health / MaxHealth);
			if (Health <= 0.f)
			{
				bIsDead = true;
				OnDeath.Broadcast();
				return true;
			}
			else // Are we staggered
			{
				if (bIsInterruptable || DamageInfo.bShouldForceInterrupt)
				{
					OnDamageResponse.Broadcast(DamageInfo);
					return true;
				}
			}
			//Do Damage
			return true;
		}
	}
	else // No damage dealt
	{
		return false;
	}
	
}

bool UDamageSystemComponent::ReserveAttackToken(int32 TokenRequested)
{
	if (AttackToken >= TokenRequested)
	{
		AttackToken -= TokenRequested;
		return true;
	}
	return false;
}

void UDamageSystemComponent::ReturnAttackToken(int32 ReturnToken)
{
	AttackToken = ReturnToken + AttackToken;
}





