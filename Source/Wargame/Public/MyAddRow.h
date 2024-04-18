// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyAddRow.generated.h"



/**
 * 
 */
UCLASS()
class WARGAME_API UMyAddRow : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION (BlueprintCallable, Category = "Wargame")
	void f_save_row_test (float abc);
};
