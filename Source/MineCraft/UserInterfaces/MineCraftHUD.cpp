// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaces/MineCraftHUD.h"
#include "UserInterfaces/MainMenu.h"
#include "UserInterfaces/InteractionWidget.h"

AMineCraftHUD::AMineCraftHUD()
{
}

void AMineCraftHUD::BeginPlay()
{
	Super::BeginPlay();
	
	if (MainMenuClass)
	{
		MainMenuWidget = CreateWidget<UMainMenu>(GetWorld(), MainMenuClass);
		MainMenuWidget->AddToViewport(5);
		MainMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (InteractionWidget)
	{
		InteractionWidget = CreateWidget<UInteractionWidget>(GetWorld(), InteractionWidgetClass);
		InteractionWidget->AddToViewport(-1);
		InteractionWidget->SetVisibility(ESlateVisibility::Collapsed);
	}

}

void AMineCraftHUD::DisplayMenu()
{
	if (MainMenuWidget)
	{
		bIsMenuVisible = true;
		MainMenuWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void AMineCraftHUD::HideMenu()
{
	if (MainMenuWidget)
	{
		bIsMenuVisible = false;
		MainMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void AMineCraftHUD::ShowInteractionWidget()
{
	if (InteractionWidget)
	{

		InteractionWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void AMineCraftHUD::HideInteractionWidget()
{
	if (InteractionWidget)
	{
		
		InteractionWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void AMineCraftHUD::UpdateInteractionWidget(const FInteractableData* InteractableData)
{
	if (InteractionWidget)
	{
		if (InteractionWidget->GetVisibility() == ESlateVisibility::Collapsed)
		{
			InteractionWidget->SetVisibility(ESlateVisibility::Visible);
		}
	}
}
