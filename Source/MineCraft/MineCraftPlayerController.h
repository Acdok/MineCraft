// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MineCraftPlayerController.generated.h"

class UInputMappingContext;

/**
 *
 */
UCLASS()
class MINECRAFT_API AMineCraftPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMineCraftPlayerController();

private:
	TSubclassOf<UUserWidget>	mMainWidgetClass;
	class UMainViewportWidget* mMainWidget;
	float	mMoveDir;

public:
	class UMainViewportWidget* GetMainWidget()
	{
		return mMainWidget;
	}

	float GetMoveDir()
	{
		return mMoveDir;
	}
protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	// Begin Actor interface
protected:

	virtual void BeginPlay() override;

	// End Actor interface
};
