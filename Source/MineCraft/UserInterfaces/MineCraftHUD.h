// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MineCraftHUD.generated.h"

struct FInteractableData;
class UInteractionWidget;
class UMainMenu;
/**
 * 
 */
UCLASS()
class MINECRAFT_API AMineCraftHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	//==========================================================================
	//PROPERTIES & VARIABLES
	//==========================================================================
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UMainMenu> MainMenuClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UInteractionWidget> InteractionWidgetClass;

	bool bIsMenuVisible;

	//==========================================================================
	// FUNCTIONS
	//==========================================================================
	AMineCraftHUD();

	void DisplayMenu();
	void HideMenu();

	void ShowInteractionWidget();
	void HideInteractionWidget();
	void UpdateInteractionWidget(const FInteractableData* InteractableData);

	//==========================================================================
	//PROPERTIES & VARIABLES
	//==========================================================================
	
	UPROPERTY()
	UMainMenu* MainMenuWidget;

	UPROPERTY()
	UInteractionWidget* InteractionWidget;

	virtual void BeginPlay() override;
};
