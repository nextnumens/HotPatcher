// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "Model/FHotPatcherCookModel.h"
#include "SharedPointer.h"
#include "FlibPatchParserHelper.h"


#include "Kismet/KismetSystemLibrary.h"
/**
 * Implements the cooked Maps panel.
 */
class SHotPatcherCookMaps
	: public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SHotPatcherCookMaps) { }
	SLATE_END_ARGS()

public:

	/**
	 * Constructs the widget.
	 *
	 * @param InArgs The Slate argument list.
	 */
	void Construct(	const FArguments& InArgs,TSharedPtr<FHotPatcherCookModel> InCookModel);

protected:

	// Callback for clicking the 'Select All Maps' button.
	void HandleAllMapHyperlinkNavigate(bool AllMap)
	{

		if (mCookModel.IsValid())
		{
			if (AllMap)
			{
				TArray<FString> Maps = UFlibPatchParserHelper::GetAvailableMaps(UKismetSystemLibrary::GetProjectDirectory(),false,true);

				for (int32 MapIndex = 0; MapIndex < Maps.Num(); ++MapIndex)
				{
					mCookModel->AddSelectedCookMap(Maps[MapIndex]);
				}
			}
			else {
				mCookModel->ClearAllMap();
			}

		}
	}

	TSharedRef<ITableRow> HandleMapListViewGenerateRow(TSharedPtr<FString> InItem, const TSharedRef<STableViewBase>& OwnerTable);
	void RefreshMapList();
private:

	/** Holds the map list. */
	TArray<TSharedPtr<FString> > MapList;

	/** Holds the map list view. */
	TSharedPtr<SListView<TSharedPtr<FString> > > MapListView;

	TSharedPtr<FHotPatcherCookModel> mCookModel;
};

