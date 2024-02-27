// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DuskInventoryItem.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FInventoryItem
{
     GENERATED_BODY()

public:
     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
     FName ItemID;

     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
     FString ItemName;

     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
     int32 Quantity;

     FInventoryItem() : ItemID(NAME_None), ItemName(TEXT("")), Quantity(0) {}

     FInventoryItem(FName NewItemID, FString NewItemName, int32 NewQuantity)
          : ItemID(NewItemID), ItemName(NewItemName), Quantity(NewQuantity) {}
};
