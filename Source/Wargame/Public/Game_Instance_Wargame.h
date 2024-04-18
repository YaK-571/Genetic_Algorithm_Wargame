// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Game_Instance_Wargame.generated.h"



/**
 * 
 */
UCLASS()
class WARGAME_API UGame_Instance_Wargame : public UGameInstance
{
	GENERATED_BODY()
	
public:
	
	const static int width = 5; //������ ����������
	const static int depth = 5;//������� ����������
	const static int size_army = 5; //���������� ������� � �������
	const static int size_matrix = width * depth; //������ ��������� �������
	int squad[size_army][width][depth]; //������ ���������� ������ �����
	int squad2[size_army][width][depth]; //������ ���������� ������� �����
	int squad_start[width][depth]; //������ ���������� ��� ������ ������� ����
	int number_battle = 0; //����� ��������
	int top_number[2]; // ������ �������� ����������� �������������
	int save_squad[2][width][depth]; // �������� ����������� ����������

	int i_tip; //��� �����
	int random_x; //��������� ������� � ����� ��� �������
	int random_y;
	int random_x2;
	int random_y2;
	float distance_unit[size_matrix];// ���������� ����� ������� � ������ ����������
	float distance; //��������� ����������



	UFUNCTION (BlueprintCallable, Category = "Wargame")
	void f_save (int number, int type, int x, int y);

	UFUNCTION (BlueprintCallable, Category = "Wargame")
	void f_start (); //�������� ���������� ����������

	UFUNCTION (BlueprintCallable, Category = "Wargame")
	int f_get_squad (int number_squad, int x, int y); //���������� ���������� ��� �� ����������� �������� �������-����������
	
	UFUNCTION (BlueprintCallable, Category = "Wargame")
	int f_get_squad2 (int number, int x, int y); //���������� ���������� ��� ������ �������. ��� �� �������������� � ������� ����������

	UFUNCTION (BlueprintCallable, Category = "Wargame")
	void f_set_top_squad (int index, int number); //��������� �������� �������� ����������� ���������
	
	UFUNCTION (BlueprintCallable, Category = "Wargame")
	void f_Excel (float abc1, float abc2, float abc3, float abc4, float abc5); // ���������� ������ � ������

	float f_distance (int index1, int index2); //������� ��������� ����������

private:
	void f_mutation ();
	void f_test (FString abc);
	void f_test_int (int abc);
	void f_test_float (float abc);
};
