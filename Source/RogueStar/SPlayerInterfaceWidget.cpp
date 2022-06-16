// Fill out your copyright notice in the Description page of Project Settings.


#include "SPlayerInterfaceWidget.h"
#include "RogueStarGameModeBase.h"
#include "Containers/UnrealString.h"
#include "RogueStarCharacter.h"
#include "SPauseMenuWidget.h"
#include "PlayerHUD.h"
#include "GameFramework/PlayerController.h"

SPlayerInterfaceWidget::SPlayerInterfaceWidget()
{
}

#define LOCTEXT_NAMESPACE "PlayerInterface"

void SPlayerInterfaceWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	ARogueStarCharacter* Player = PlayerRef->ReturnPlayer();

	OwningHUD = InArgs._OwningHUD;

	const FMargin ContentPadding = FMargin(500.f, 300.f);

	const FText InterfaceTitle = LOCTEXT("InterfaceTitle", "Score:");

	const FText ScoreText = FText::AsNumber(Player->CollectiblesHeld);

	FSlateFontInfo TextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	TextStyle.Size = 60.f;

	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(ContentPadding)
			[
				//Title Text
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Font(TextStyle)
					.Text(InterfaceTitle)
					.Justification(ETextJustify::Left)
				]

				//Title Text
				+ SVerticalBox::Slot()
				.Padding(ContentPadding)
				[
					SNew(STextBlock)
					.Font(TextStyle)
					.Text(ScoreText)
					.Justification(ETextJustify::Left)
				]
			]
		];
}

#undef LOCTEXT_NAMESPACE