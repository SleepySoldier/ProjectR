// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageSystem/DamageTypes.h"
#include "DamageSystemComponent.generated.h"

USTRUCT(BlueprintType)
struct FDamageInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Amount = 0.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDamageType DamageType = EDamageType::None;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDamageResponse DamageResponse = EDamageResponse::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector HitLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName BoneName = "None";
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bShouldDamageInvincible = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanBeBlocked = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanBeParried = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bShouldForceInterrupt = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<AActor> DamageCauser = nullptr;
	
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, HealthPercent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageResponse, FDamageInfo, DamageInfo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBlocked, bool, CanBeParried, AActor*, DamageCauser);




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class PROJECT_R_REVIVAL_API UDamageSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDamageSystemComponent();

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;
	UPROPERTY(BlueprintAssignable)
	FOnBlocked OnBlocked;
	UPROPERTY(BlueprintAssignable)
	FOnDamageResponse OnDamageResponse;
	UPROPERTY(BlueprintAssignable)
	FOnDeath OnDeath;

	UFUNCTION(BlueprintCallable)
	void InitDamageSystem();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	float Heal(const float Amount);
	
	UFUNCTION(BlueprintCallable)
	bool TakeDamage(const FDamageInfo DamageInfo);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsInvincible = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsDead = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsInterruptable = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsBlocking = false;


	/** Team combat **/

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AttackToken = 1;
	
	UFUNCTION(BlueprintCallable)
	bool ReserveAttackToken(int32 TokenRequested);
	
	UFUNCTION(BlueprintCallable)
	void ReturnAttackToken(int32 ReturnToken);
private:



		
};

