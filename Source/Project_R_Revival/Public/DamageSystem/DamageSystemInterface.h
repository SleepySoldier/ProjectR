// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageSystemInterface.generated.h"



// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDamageSystemInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */


struct FDamageInfo;
class PROJECT_R_REVIVAL_API IDamageSystemInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Damage System | Implement")
	float GetMaxHealth();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Damage System")
	float GetCurrentHealth();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Damage System")
	bool IsDead();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Damage System")
	float Heal(float Amount);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Damage System")
	bool TakeDamage(const FDamageInfo& DamageInfo);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Damage System")
	bool IsAttacking();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Damage System")
	void ResetRecoveryState();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Damage System ")
	bool ReserveAttackToken(int32 Token);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Damage System")
	void ReturnAttackToken(int32 AttackToken);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Damage System | Implement")
	int32 GetTeamNumber();
	
	
};
