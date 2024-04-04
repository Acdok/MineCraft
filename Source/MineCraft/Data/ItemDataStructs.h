#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/StaticMesh.h"
#include "ItemDataStructs.generated.h"

UENUM()
enum class EInvenItemType : uint8
{
	Buildable UMETA(DisplayName = "Buildable"),
	Wearable UMETA(DisplayName = "Wearable"),
	Consumable UMETA(DisplayName = "Consumable"),
	Burnable UMETA(DisplayName = "Burnable"),
	Cookable UMETA(DisplayName = "Cookable"),
	Mundane UMETA(DisplayName = "Mundane")
};


USTRUCT()
struct FItemStatistics
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnyWhere)
	float ArmorRating;

	UPROPERTY(EditAnyWhere)
	float DamageValue;

	UPROPERTY(EditAnyWhere)
	float RestorationAmount;

};

USTRUCT()
struct  FItemTextData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnyWhere)
	FText Name;

	UPROPERTY(EditAnyWhere)
	FText Description;

	UPROPERTY(EditAnyWhere)
	FText InteractionText;

	UPROPERTY(EditAnyWhere)
	FText UsageText;

};

USTRUCT()
struct  FItemNumericData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	int32 MaxStackSize;

	UPROPERTY(EditAnywhere)
	bool bIsStackable;
};

USTRUCT()
struct FItemAssetData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere)
	UTexture2D* Mesh;
};

USTRUCT()
struct FItemData : public FTableRowBase 
{
	GENERATED_USTRUCT_BODY()
	

	UPROPERTY(EditAnyWhere, Category = "Item Data")
	FName ID;

	UPROPERTY(EditAnyWhere, Category = "Item Data")
	EInvenItemType InvenItemType;

	UPROPERTY(EditAnywhere, Category = "Inventory Item Data")
	FItemStatistics ItemStatistics;

	UPROPERTY(EditAnywhere, Category = "Inventory Item Data")
	FItemTextData TextData;

	UPROPERTY(EditAnywhere, Category = "Inventory Item Data")
	FItemNumericData NumricData;

	UPROPERTY(EditAnywhere, Category = "Inventory Item Data")
	FItemAssetData AssetData;
};
