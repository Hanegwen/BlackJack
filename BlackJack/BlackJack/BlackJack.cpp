// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <list>
#include <string>
#include <random>

struct cards
{
	std::string name;
	int value;
};
class Deck
{
public:
	cards ace;
	cards two;
	std::list<cards> cardList = {ace, ace, ace, ace, two, two, two, two};

	int returnCardValue()
	{
		std::random_device rd;     // only used once to initialise (seed) engine
		std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
		//std::uniform_int_distribution<int> uni(0, cardList.size); // guaranteed unbiased

		//int random_integer = uni(rng);


		//cardList.remove(random_integer);
		//return cardList[random_integer].value;
		return 21; //There for testing
	}
};

class GamePlayer
{
public:
	bool isAi = false;
	bool hasBusted = false;
	bool hold;
	int turnValue = 0;
	std::string name = "Player";


	void PlayTurn(Deck deck)
	{
		hasBusted = false;
		std::cout << "Your Up Card is " << std::endl;
		std::cout << "Your Down Card is" << std::endl;
		std::cout << "Your total is currently" << std::endl;
		if (!isAi)
		{
			std::cout << "Type Hold or Hit" << std::endl;;
			std::string input;
			std::cin >> input;
			
			if (input == "Hold")
			{
				Hold(deck);
			}
			else if (input == "Hit")
			{
				Hit(deck);
			}
			else
			{
				std::cout << "Not Reconized Command" << std::endl;

			}
		}

	}


protected:
	int units = 200;

	void Hold(Deck deck)
	{
		std::cout << "The Player Chose Hold" << std::endl;
		hold = true;
	}

	void Hit(Deck deck)
	{
		//turnValue += 21;
		turnValue += deck.returnCardValue();
		std::cout << "The Player Chose Hit" << std::endl;

		std::cout << "The New Turn Amount is " << turnValue << std::endl;
		if (turnValue > 21)
		{
			Bust();
		}
		
	}

	void Bust()
	{
		std::cout << name << " has busted this hand" << std::endl;
		hasBusted = true;
		units -= 10;
	}
};

class AI: public GamePlayer
{
public:
	
	AI(int holdAmount, bool Ai, std::string myName)
	{
		holdThreashold = holdAmount;
		isAi = Ai;
		name = myName;
	}

	void AITurn(Deck deck)
	{
		do
		{
			std::cout << "AI Turn Brain" << std::endl;

			if (turnValue + holdThreashold < 21)
			{
				Hit(deck);
			}
			else
			{
				Hold(deck);
			}
		} while (hasBusted == false && hold == false);
		std::cout << name << "'s turn is over" << std::endl;
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
	std::cout << "Welcome to Black Jack" << std::endl;

	AI ai1(2, true, "AIOne");
	AI ai2(3, true, "AITwo");
	AI ai3(5, true, "AIThree");
	Player player;

	std::list<AI> AIPlayers = {ai1,ai2,ai3};

	do
	{
		if (player.hasBusted == false)
		{
			std::cout << "Turn: " + player.name << std::endl;
			player.PlayTurn(gameDeck);
		}
		for(AI players: AIPlayers)
		{
			std::cout << "Turn: " + players.name << std::endl;
			players.AITurn(gameDeck);

		}
		

	} while (AIPlayers.size() > 0 );
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
