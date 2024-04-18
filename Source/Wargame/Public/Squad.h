// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Squad.generated.h"


UCLASS()
class WARGAME_API ASquad : public AActor
{
	GENERATED_BODY()
	int int_test;
	//UStaticMeshComponent* cubik = nullptr;
	
	int squad[5][5][5]; //������ ���������� ������ ���������
	int battle_formation_start[5][5];//������ ���������� ������������� �� ������ ����
	int number_team;//����� �������
	int number_formation_self;//����� ���������

	int number_top_last_squad; //����� ������ ��������� �������
	int top_last_battle_formation[5][5]; //������ ���������� ������ ��������� �������
	

public:	
	// Sets default values for this actor's properties
	ASquad();
	//UFUNCTION (BlueprintPure, Categoty = "Wargame")
	//void f_bpcast ();
	UFUNCTION (BlueprintCallable, Category="Wargame")
	int f_test_int (int abc);
	UFUNCTION (BlueprintCallable, Category = "Wargame")
	int f_get_battle_formation (int squad, int x, int y);
	UFUNCTION (BlueprintCallable, Category = "Wargame")
	void f_top_last_squad (int squad); //���������� ������� ��������� ��� �������� � ��������� ���
	UFUNCTION (BlueprintCallable, Category = "Wargame")
	void f_loading_squad ();//������������ �� ���� ���������� ����������, ������� ���� �������� ����������� � ������� ���
	UFUNCTION (BlueprintCallable, Category = "Wargame")
	void f_number_squad_self (int team, int formation);
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void f_mutation ();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void f_test (FString abc);

	
	UFUNCTION (BlueprintCallable, Category = "Wargame")
	void set_squad (int number_squad, int x, int y, int tip);
};
