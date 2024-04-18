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
	
	const static int width = 5; //ширина построения
	const static int depth = 5;//глубина построения
	const static int size_army = 5; //количество отрядов у команды
	const static int size_matrix = width * depth; //размер элементов матрицы
	int squad[size_army][width][depth]; //боевое построение разных групп
	int squad2[size_army][width][depth]; //боевое построение команды врага
	int squad_start[width][depth]; //боевое построение при первом запуске игры
	int number_battle = 0; //номер итереции
	int top_number[2]; // номера наиболее эффективных подразделений
	int save_squad[2][width][depth]; // наиболее эффективные построения

	int i_tip; //тип юнита
	int random_x; //рандомные позиции в строю для мутаций
	int random_y;
	int random_x2;
	int random_y2;
	float distance_unit[size_matrix];// расстояние между юнитами в разных отделениях
	float distance; //евклидово расстояние



	UFUNCTION (BlueprintCallable, Category = "Wargame")
	void f_save (int number, int type, int x, int y);

	UFUNCTION (BlueprintCallable, Category = "Wargame")
	void f_start (); //передача построений отделениям

	UFUNCTION (BlueprintCallable, Category = "Wargame")
	int f_get_squad (int number_squad, int x, int y); //считывание построений для их последующей передачи акторам-отделениям
	
	UFUNCTION (BlueprintCallable, Category = "Wargame")
	int f_get_squad2 (int number, int x, int y); //считывание построения для второй команды. Оно не оптимизируется и остаётся неизменным

	UFUNCTION (BlueprintCallable, Category = "Wargame")
	void f_set_top_squad (int index, int number); //получение индексов наиболее эффективных отделений
	
	UFUNCTION (BlueprintCallable, Category = "Wargame")
	void f_Excel (float abc1, float abc2, float abc3, float abc4, float abc5); // сохранение данных в экселе

	float f_distance (int index1, int index2); //рассчёт евклидова расстояния

private:
	void f_mutation ();
	void f_test (FString abc);
	void f_test_int (int abc);
	void f_test_float (float abc);
};
