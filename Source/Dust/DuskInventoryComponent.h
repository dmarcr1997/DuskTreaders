// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DuskInventoryItem.h"
#include "DuskInventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUST_API UDuskInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDuskInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TMap<FName, FInventoryItem> Inventory;

	// Function to add an item
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(const FName& ItemID, const FInventoryItem& Item);

	// Function to remove an item
	bool RemoveItem(const FName& ItemID);

	// Function to find an item
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool FindItem(const FName& ItemID, FInventoryItem& OutItem) const;
		
};
