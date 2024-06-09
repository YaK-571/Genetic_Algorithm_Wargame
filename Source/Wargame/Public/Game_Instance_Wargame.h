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
	int squad_start[width][depth]; //������ ���������� ��� ������ ������� ����. ����� ������������ ��� ��������� �����
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

	float coin_average; //������� �������� ������� ������� �� ���
	float start_coin[3]; //����� � ������ ��� ����
	float start_coin_average; //������� ���� �� ������ ��� ���
	bool stop = false; //���������� �� ��������� �����������
	int number_stop; // ����� �������� ����� ��������� �����������

	//������ ����� � ����� ���
	int new_peshota;
	int new_maschina;
	int new_BTR;
	int new_Tank;
	bool smena_stroja = 0;
	int unit_distribution = 0;

	int similarity_units[6]{ 1,-1,2,-2,3,-3 }; //������������ ��� ������������� ������ �� ������� �������� ������������ �� ��������������� ������
	

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

	UFUNCTION (BlueprintCallable, Category = "Wargame")
	void f_set_squad_start (int tip, int shirina, int glubina); //����� ���������� ����������
	
	UFUNCTION (BlueprintCallable, Category = "Wargame")
	void f_set_new_squad (int peshota, int maschina, int BTR, int Tank); //����� ���������� ����������



private:
	void f_mutation ();
	void f_test (FString abc);
	void f_test_int (int abc);
	void f_test_float (float abc);

	int f_search1 (int unit_tschislo, int unit_tip); //������ ���� ������. �����, ������� ��� ���� � �����, ������ �� ������ �������
	int f_search2 (int unit_tschislo, int unit_tip, int shodstvo); //������ ���� ������. ���������� ����� ������������� �� ������� ������ ������
	int f_search3 (int unit_tschislo, int unit_tip); //������ ���� ����������. ����������� ���������� �����
};
