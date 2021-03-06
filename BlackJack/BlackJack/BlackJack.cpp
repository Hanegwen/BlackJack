// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <list>
#include <string>
#include <random>

class cards
{
public:
	std::string name;
	int value;
	cards(int myValue, std::string myName)
	{
		value = myValue;
		name = myName;
	}
	
};
class Deck
{
public:
	cards ace;// (11, "ace");
	cards two;// (2, "two");
	cards three;// (3, "three");
	cards four;// (4, "four");
	cards five;// (5, "five");
	cards six;// (6, "six");
	cards seven;// (7, "seven");
	cards eight;// (8, "eight");
	cards nine;// (9, "nine");
	cards ten;// (10, "ten");
	cards jack;// (10, "jack");
	cards queen;// (10, "queen");
	cards king;// (10, "king");
	std::list<cards> cardList = {ace, king, three, ace, 
		two, seven, two, two, 
		three, three, ace, three, 
		four, six, four , queen, 
		five, five, five, five, 
		six, ten, four, six, 
		two, seven, seven, king,
	eight, eight, eight, eight,
	nine, nine, nine, jack,
	ten, six, ten, ten,
	jack, nine, jack, queen,
	queen, four, jack, queen,
	seven, king, ace, king};

	std::list<cards> defaultList;
	/*Deck()
	{

	}*/

	int returnCardValue()
	{
		cards returnNum = cardList.pop_back;
		return returnNum.value;
		
	}
};

class GamePlayer
{
public:
	bool isAi = false;
	bool hasBusted = false;
	bool hold = false;
	int turnValue = 0;
	std::string name = "Player";


	void PlayTurn(Deck deck)
	{
		if (deck.cardList.size < 1)
		{
			deck.cardList = deck.defaultList;
		}
		hasBusted = false;

		upCard = deck.returnCardValue();
		downCard = deck.returnCardValue();

		turnValue += upCard + downCard;
		std::cout << "Your Up Card is " << upCard << std::endl;
		std::cout << "Your Down Card is " << downCard << std::endl;
		std::cout << "Your total is currently " << turnValue << std::endl;
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
	int upCard;
	int downCard;
	void Hold(Deck deck)
	{
		//hasBusted = true; //Just for Testing
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
		hasBusted = false;

		upCard = deck.returnCardValue();
		downCard = deck.returnCardValue();

		turnValue += upCard + downCard;
		std::cout << "Your Up Card is " << upCard << std::endl;
		std::cout << "Your Down Card is " << downCard << std::endl;
		std::cout << "Your total is currently " << turnValue << std::endl;
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
	gameDeck.defaultList = gameDeck.cardList;
	do
	{
		
		if (player.hasBusted == false)
		{
			std::cout << "Turn: " + player.name << std::endl;
			player.PlayTurn(gameDeck);
		}
		else
		{
			continue;
		}
		for(AI players: AIPlayers)
		{
			if (players.hasBusted == false)
			{
				if (players.hold == false)
				{
					std::cout << "Turn: " + players.name << std::endl;
					players.AITurn(gameDeck);
				}
			}

		}
		

	} while (AIPlayers.size() > 0 || (AIPlayers.size() > 1 && player.hasBusted));
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
