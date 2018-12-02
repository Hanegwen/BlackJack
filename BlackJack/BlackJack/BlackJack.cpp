// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <list>
#include <string>

struct cards
{
	std::string name;
	int value;
};
class Deck
{
	std::list<cards> = {};
};

class GamePlayer
{
public:
	bool isAi = false;
	bool hasBusted;
	int finalRanking;

	void PlayTurn(Deck deck)
	{
		
		if (!isAi)
		{
			std::cout << "Type Hold or Hit";
			std::string input;
			std::cin >> input;
			
			if (input == "Hold")
			{

			}
			else if (input == "Hit")
			{

			}
			else
			{
				std::cout << "Not Reconized Command";

			}
		}
	}

private:
	int units = 200;

	void Hold()
	{

	}

	void Hit()
	{

	}
};

class AI: public GamePlayer
{
public:
	
	AI(int holdAmount, bool Ai)
	{
		holdThreashold = holdAmount;
		isAi = Ai;
	}
private:
	int holdThreashold;
};

class Player : public GamePlayer
{
public:


private:

};


int main()
{
	Deck gameDeck;
    std::cout << "Welcome to Black Jack"; 

	AI ai1(2, true);
	AI ai2(3, true);
	AI ai3(5, true);
	Player player;

	std::list<GamePlayer> gamePlayers = {ai1,ai2,ai3,player};

	player.PlayTurn(gameDeck);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
