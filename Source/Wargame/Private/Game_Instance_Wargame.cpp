// Fill out your copyright notice in the Description page of Project Settings.


#include "Game_Instance_Wargame.h"
#include <fstream>

#include <iostream>
#include <string>
#include <random>
#include <iostream>
#include <iomanip>


void UGame_Instance_Wargame::f_save (int number, int type, int x, int y)
{
	save_squad[number][x][y] = type;

}

void UGame_Instance_Wargame::f_set_squad_start (int tip, int shirina, int glubina)
{
	squad_start[glubina][shirina] = tip;


}

void UGame_Instance_Wargame::f_start ()
{
	number_battle = number_battle + 1;
	//���� ��� ������, ��...
	if (number_battle == 1)
	{
		/*
		squad_start[0][0] = 1;
		squad_start[0][1] = 1;
		squad_start[0][3] = 2;
		squad_start[0][4] = 2;
		squad_start[2][0] = 4;
		squad_start[2][1] = 4;
		squad_start[2][2] = 4;
		squad_start[2][3] = 4;
		squad_start[2][4] = 4;
		squad_start[3][0] = 3;
		squad_start[3][2] = 3;
		squad_start[3][4] = 3;*/

		//������ ��������� ����������
		/*squad_start[0][0] = 1;
		squad_start[0][2] = 1;
		squad_start[0][4] = 1;
		squad_start[1][1] = 2;
		squad_start[1][3] = 2;
		squad_start[2][2] = 3;
		*/
		/*
		squad_start[0][0] = 1;
		squad_start[0][1] = 4;
		squad_start[0][2] = 1;
		squad_start[0][3] = 4;
		squad_start[0][4] = 1;
		squad_start[1][1] = 2;
		squad_start[1][3] = 2;
		*/
		
		//��������� ���������� ��� ���� ���������
		for (int i_squad = 0; i_squad < 5; i_squad++)
		{
		/*
			squad2[i_squad][0][0] = 1;
			squad2[i_squad][0][1] = 1;
			squad2[i_squad][0][3] = 2;
			squad2[i_squad][0][4] = 2;
			squad2[i_squad][2][0] = 4;
			squad2[i_squad][2][1] = 4;
			squad2[i_squad][2][2] = 4;
			squad2[i_squad][2][3] = 4;
			squad2[i_squad][2][4] = 4;
			squad2[i_squad][3][0] = 3;
			squad2[i_squad][3][2] = 3;
			squad2[i_squad][3][4] = 3;
		*/
			for (int x = 0; x < width; x++)
			{
				for (int y = 0; y < depth; y++)
				{
					squad[i_squad][x][y] = squad_start[x][y];
					squad2[i_squad][x][y] = squad_start[x][y];
				}
			}

		}
	}

	else
	{
		//���� ��� �� ������, ��
		//��������� �������� ����������� ���������� �� ����������� ���
		for (int number = 0; number <= 1; number++)
		{
			for (int x = 0; x < width; x++)
			{
				for (int y = 0; y < depth; y++)
				{
					squad[number][x][y] = save_squad[number][x][y];
				}
			}
		}

		if (stop == false)
		{
			f_mutation ();
		}
	}
}

int UGame_Instance_Wargame::f_get_squad (int number_squad, int x, int y)
{
	return squad[number_squad][x][y];
}
int UGame_Instance_Wargame::f_get_squad2 (int number, int x, int y)
{
	return squad2[number][x][y];
}

void UGame_Instance_Wargame::f_set_top_squad (int index, int number)
{
	top_number[index] = number;

	for (int x=0; x< width;x++)
	{
		for (int y = 0; y < depth; y++)
		{
			save_squad[index][x][y] = squad[number][x][y];
		}
	}
}

void UGame_Instance_Wargame::f_mutation ()
{
	//������ 2 ���������� �������� ������ ��, ��� � 2 �������� ����������� ���������� � ���
	// ��������� - ���������� � ������� �������
	for (int number = 2; number <= 4; number++)
	{
		//��������� ��� n-�� ����� ������ � ���������
		for (size_t i = 0; i < 4; i++)
		{

			i_tip = 0;
			while (i_tip == 0)
			{
				random_x = FMath::RandRange (0, 4);
				random_y = FMath::RandRange (0, 4);
				i_tip = squad[number][random_x][random_y];
				//������ ���������� ����� � ������� ��� ���
			}
			squad[number][random_x][random_y] = 0; //�������� �����, ������ ����� �����

			//������ ��������� �������, ���� ���� ����� �������
			random_x2 = FMath::RandRange (0, 4);
			random_y2 = FMath::RandRange (0, 4);

			//���� ��� ����� ������ ������ ������, �� �������� ��� �� ����� �������
			if (squad[number][random_x2][random_y2] != 0)
			{
				squad[number][random_x][random_y] = squad[number][random_x2][random_y2];
			}
			//������� ����� �� ��������� �����
			squad[number][random_x2][random_y2] = i_tip;
		}
	}
}

float UGame_Instance_Wargame::f_distance (int index1, int index2)
{
	distance = 0;
	int index = 0;
	
		for (size_t x = 0; x < width; x++)
		{
			for (size_t y = 0; y < depth; y++)
			{
				//����� ���������� ����� ������ �� ������
				distance_unit[index] = (squad[index1][x][y] - squad[index2][x][y]);
				distance_unit[index] = distance_unit[index] * distance_unit[index];
				distance = distance + distance_unit[index];
				//f_test_float (distance);
				index++;
			}
		}
		

	distance = sqrt (distance);
	
	return distance; //��������� ����������
}

void UGame_Instance_Wargame::f_test (FString abc)
{
	GEngine->AddOnScreenDebugMessage (-1, 2, FColor::Red, abc);

}


void UGame_Instance_Wargame::f_test_int (int abc)
{
	GEngine->AddOnScreenDebugMessage (-1, 2, FColor::Red, FString::FromInt (abc));
	

}

void UGame_Instance_Wargame::f_test_float (float abc)
{
	GEngine->AddOnScreenDebugMessage (-1, 2, FColor::Red, FString::SanitizeFloat (abc));
	
}


void UGame_Instance_Wargame::f_Excel (float abc1, float abc2, float abc3, float abc4, float abc5)
{
	coin_average = (abc1 + abc2 + abc3 + abc4 + abc5) / 5;
	if (number_battle <= 3)
	{ //������� �������� �������� ������ � ������ ����
		start_coin[number_battle - 1] = coin_average;
	}
	if (number_battle == 3)
	{
		start_coin_average = start_coin[0] + start_coin[1] + start_coin[2];
	}
	

	abc1 = int (abc1 * 100) / 100.0;//����������
	abc2 = int (abc2 * 100) / 100.0;//����������
	abc3 = int (abc3 * 100) / 100.0;//����������
	abc4 = int (abc4 * 100) / 100.0;//����������
	abc5 = int (abc5 * 100) / 100.0;//����������
	
	std::ofstream File;
	File.open ("C:\\Wargame\\Save1.csv", std::ios::app);
	if (File.is_open ())
	{

	}
	File << number_battle << "," << abc1 << "," << abc2 << "," << abc3 << "," << abc4 << "," << abc5 << std::endl;

	//���������� � ������ ������������� ������
	std::ofstream File2;
	
	File2.open ("C:\\Wargame\\Save2.csv", std::ios::app);
	if (File2.is_open ())
	{

	}
	File2 << number_battle << "," << abc1 << std::endl;
	File2 << number_battle << "," << abc2 << std::endl;
	File2 << number_battle << "," << abc3 << std::endl;
	File2 << number_battle << "," << abc4 << std::endl;
	File2 << number_battle << "," << abc5 << std::endl;

	if ((number_battle >= 3) && ((coin_average / start_coin_average) > 1.5))
	{
		//���� �������� ������� ������� ����������� ��������� ��, ������� ���� �� ������, �� �������� �����������
		stop = 1;
		number_stop++;
		File << "optimization is suspended" << std::endl; //����� �������������
		File2 << "optimization is suspended" << std::endl;
	}
	else if ((stop == 1)&&(number_stop < 3))
	{
		stop = 0;
		number_stop = 0;
		File << "The search continues" << std::endl; //����� ���������
		File2 << "The search continues" << std::endl;
	}
	if (number_stop >= 3)
	{
	File << "Optimization is over" << std::endl; //����������� ���������
	File2 << "Optimization is over" << std::endl;
	}
}

