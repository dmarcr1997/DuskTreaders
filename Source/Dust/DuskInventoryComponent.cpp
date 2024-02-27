// Fill out your copyright notice in the Description page of Project Settings.


#include "DuskInventoryComponent.h"

// Sets default values for this component's properties
UDuskInventoryComponent::UDuskInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDuskInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UDuskInventoryComponent::AddItem(const FName& ItemID, const FInventoryItem& Item)
{
	FInventoryItem* ExistingItem = Inventory.Find(ItemID);
	if (ExistingItem)
	{
		// If the item exists, increase its count
		ExistingItem->Quantity += Item.Quantity;
	}
	else
	{
		// If the item does not exist, add it to the inventory
		Inventory.Add(ItemID, Item);
	}
}

bool UDuskInventoryComponent::RemoveItem(const FName& ItemID)
{
	return Inventory.Remove(ItemID) > 0;
}

bool UDuskInventoryComponent::FindItem(const FName& ItemID, FInventoryItem& OutItem) const
{
	if (const FInventoryItem* FoundItem = Inventory.Find(ItemID))
	{
		OutItem = *FoundItem; // Copy the found item's details to the output parameter
		return true; // Item was found
	}
	return false; // Item was not found
}


