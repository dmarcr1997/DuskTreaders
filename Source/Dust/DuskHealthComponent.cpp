// Fill out your copyright notice in the Description page of Project Settings.


#include "DuskHealthComponent.h"
#include "Net/UnrealNetwork.h"
// Sets default values for this component's properties
UDuskHealthComponent::UDuskHealthComponent()
{
	DefaultHealth = 100.0f;
	Health = DefaultHealth;

	SetIsReplicatedByDefault(true);
	
}


// Called when the game starts
void UDuskHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner()->HasAuthority())
	{
		GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UDuskHealthComponent::TakeDamage);
	}
	
}

void UDuskHealthComponent::OnRep_Health(float OldHealth)
{
	float Damage = Health - OldHealth;

	OnHealthChanged.Broadcast(this, Health, Damage, nullptr, nullptr, nullptr);
}

float UDuskHealthComponent::GetHealth() const
{
	return Health;
}

void UDuskHealthComponent::Heal(float HealAmount)
{
	if (HealAmount <= 0.0f || Health <= 0.0f)
	{
		return;
	}

	Health = FMath::Clamp(Health + HealAmount, 0.0f, DefaultHealth);
	OnHealthChanged.Broadcast(this, Health, -HealAmount, nullptr, nullptr, nullptr);
}

void UDuskHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0.0f || Health <= 0.0f)
	{
		return;
	}
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);

	OnHealthChanged.Broadcast(this, Health, Damage, DamageType, InstigatedBy, DamageCauser);

	if (Health <= 0.0f)
	{
		OnDeath.Broadcast(DamagedActor, InstigatedBy);
	}
}


void UDuskHealthComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UDuskHealthComponent, Health);
}