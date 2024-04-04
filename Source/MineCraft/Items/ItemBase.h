// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/ItemDataStructs.h"
#include "MineCraft/MineCraftCharacter.h"
#include "ItemBase.generated.h"

/**
 * 
 */
UCLASS()
class MINECRAFT_API UItemBase : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnyWhere, Category = "Item")
	int32 Quantity;

	UPROPERTY(VisibleAnyWhere, Category = "Item")
	FName ID;

	UPROPERTY(VisibleAnyWhere, Category = "Item")
	EInvenItemType InvenItemType;

	UPROPERTY(VisibleAnyWhere, Category = "Item")
	FItemStatistics ItemStatistics;

	UPROPERTY(VisibleAnyWhere, Category = "Item")
	FItemTextData TextData;

	UPROPERTY(VisibleAnyWhere, Category = "Item")
	FItemNumericData NumricData;

	UPROPERTY(VisibleAnyWhere, Category = "Item")
	FItemAssetData AssetData;
	
	//=============================
	//FUNCTIONS
	//=============================


	UItemBase();

	UItemBase* CreateItemCopy() const;

	UFUNCTION(Category = "Item")
	FORCEINLINE bool IsFullItemStack() const { return Quantity == NumricData.MaxStackSize; };
	
	UFUNCTION(Category = "Item")
	void SetQuantity(const int32 NewQuantity);
	
	UFUNCTION(Category = "Item")
	virtual void Use(AMineCraftCharacter* Character);

protected:
	bool operator ==(const FName& OtherID) const
	{
		return this->ID == OtherID;
	}

};