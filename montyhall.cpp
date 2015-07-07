/*
	Author: Michael Garod
	Date Created: 7/7/15
	Description: Monty Hall simulator to calculate percentages based off of
		two strategies—staying with your door, or switching to the other.
	Usage: argv[1] is the integer number of doors to simulate
			argv[2] is the integer number of games you would like to simulate.
*/

#include <iostream>
using namespace std;

int make_choice(int num_doors);
bool stay_strategy(int num_doors);
bool switch_strategy(int num_doors);
int runGame(int strategy, int num_doors, int times);

int main(int argc, char* argv[])
{
	srand(time(NULL));
	const int DOORS = atoi(argv[1]);
	const int SIMULATIONS = atoi(argv[2]);

	runGame(1, DOORS, SIMULATIONS);
	runGame(2, DOORS, SIMULATIONS);

	return 0;
}

int make_choice(int num_doors)
{
	return rand() % num_doors;
}

bool stay_strategy(int num_doors)
{
	int car_door = make_choice(num_doors);
	int choice = make_choice(num_doors);

	// No need to simulate opening doors. If you pick the car door, you will
	// win since you'll stay. If you pick a goat, you will stay and lose.
	if (choice == car_door)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool switch_strategy(int num_doors)
{
	int car_door = make_choice(num_doors);
	int choice = make_choice(num_doors);

	// No need to simulate opening doors. If you pick the car door, you will
	// switch away. If you pick a goat door, all other goats will be revealed
	// and switching away will give you the car.
	if (choice == car_door)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int runGame(int strategy, int num_doors, int num_games)
{
	int num_wins = 0;

	if (strategy == 1)
	{
		for (int i = 0; i < num_games; i++)
		{
			if (stay_strategy(num_doors))
			{
				num_wins += 1;
			}
		}

	// Report results
	cout << "By the stay_strategy, you will win: " <<
		static_cast<double>(num_wins) / static_cast<double>(num_games) * 100 << "% of the time" << endl;

	}
	else if (strategy == 2)
	{
		for (int i = 0; i < num_games; i++)
		{
			if (switch_strategy(num_doors))
			{
				num_wins += 1;
			}
		}

	// Report results
	cout << "By the switch_strategy, you will win: " <<
		static_cast<double>(num_wins) / static_cast<double>(num_games) * 100 << "% of the time" << endl;		
	}
	else
	{
		cout << "Invalid entry for strategy!" << endl;
	}

	return num_wins;
}
