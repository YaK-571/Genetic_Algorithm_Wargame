// Fill out your copyright notice in the Description page of Project Settings.


#include "Squad.h"

// Sets default values
ASquad::ASquad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


// Called when the game starts or when spawned
void ASquad::BeginPlay ()
{
	Super::BeginPlay ();
	int_test = 10;

//	auto Owner = GetOwner ();
	//if (!ensure (Owner != nullptr)) { return; }
	//cubik = GetOwner ()->FindComponentByClass<UStaticMeshComponent> ();
	//UMeshComponent* cubik = GetOwner ()->FindComponentByClass<UMeshComponent> ();
	//—трочка, которую можно вывести должна выгл€дить так
	//FString A = FString(TEXT( "aaaaaaaaddddddddddddvvvvvvvv"));
	//f_test (A);
	
	/*///боевое построение на старте игры
	battle_formation_start[0][0]=2;
	battle_formation_start[0][2] = 2;
	battle_formation_start[0][4] = 2;
	battle_formation_start[1][1] = 1;
	battle_formation_start[1][3] = 1;
	battle_formation_start[3][2] = 3;

	//применить заданное построение ко всем отделени€м
	for (int i_squad = 0; i_squad < 5; i_squad++)
	{
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				squad[i_squad][x][y] = battle_formation_start[x][y];
			}
		}

	}*/
	
}

// Called every frame
void ASquad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	
}

void ASquad:: f_test (FString abc)
{
	GEngine->AddOnScreenDebugMessage (-1, 2, FColor::Red, abc);

}


int ASquad::f_test_int (int abc)
{
	GEngine->AddOnScreenDebugMessage (-1, 2, FColor::Red, FString::FromInt (abc));
	return abc;

}

int ASquad::f_get_battle_formation (int number, int x, int y)
{
	
	return squad[number][x][y];
};

void ASquad::f_top_last_squad (int number)
{
	number_top_last_squad = number;
	
	
	for (size_t x = 0; x < 5; x++)
	{
		for (size_t y = 0; y < 5; y++)
		{
			top_last_battle_formation[x][y] = squad[number][x][y];
		}
	}
	
}
	

void ASquad::f_loading_squad ()
{
	f_mutation ();
	
	for (size_t i_squad = 0; i_squad < 5; i_squad++)
	{
		for (size_t x = 0; x < 5; x++)
		{
			for (size_t y = 0; y < 5; y++)
			{
				squad[i_squad][x][y] = top_last_battle_formation[x][y];
			}
		}
	}

}

void ASquad::f_mutation ()
{
	
	int i_tip;
	int random_x;
	int random_y;
	int random_x2;
	int random_y2;
	int i_break;
	for (size_t i = 0; i < 3; i++)
	{
		i_break = 0;
		i_tip = 0;
		while (i_tip == 0)
		{
			random_x = FMath::RandRange (0, 4);
			random_y = FMath::RandRange (0, 4);
			i_tip = top_last_battle_formation[random_x][random_y];

			/*i_break++;
			if (i_break >= 100)
			{
				break;
			}*/
		}
		top_last_battle_formation[random_x][random_y] = 0;

		random_x2 = FMath::RandRange (0, 4);
		random_y2 = FMath::RandRange (0, 4);

		if (top_last_battle_formation[random_x2][random_y2] != 0)
		{
			top_last_battle_formation[random_x][random_y] = top_last_battle_formation[random_x2][random_y2];
		}
		top_last_battle_formation[random_x2][random_y2] = i_tip;
	}
		
}

void ASquad::f_number_squad_self (int team, int formation)
{
	number_team = team;
	number_formation_self = formation;
};

void ASquad::set_squad (int number_squad, int x, int y, int tip)
{
	squad[number_squad][x][y] = tip;
}