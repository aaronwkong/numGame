

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>

int getGuess(int count)
{
	while (1)//loop until user enters valid input
	{
		std::cout << "Guess #" << count << ": ";
		int guess;
		std::cin >> guess;

		if (std::cin.fail())//if user enters invalid input
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else //when user enters a valid input
		{
			std::cin.ignore(32767, '\n');
			return guess;
		}
	}
}


int main()
{
	std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));
	std::uniform_int_distribution<> die(1, 100);
	bool win = false;
	char play = 'y';
	int guess;
	int number;

	do
	{
		std::cout << "Let's play a game. I'm thinking of a number. "
			<< "You have 7 tries to guess what it is." << std::endl;
		number = die(mersenne); //generate a random number between 0 and 100

		for (int tries = 0; tries < 7 && win == false; tries++) //user gets 7 guesses
		{
			guess = getGuess(tries + 1);


			if (guess == number) //if user guesses the number correctly
			{
				std::cout << "Correct! You win!" << std::endl;
				win = true;
			}
			else if (guess > number)
				std::cout << "Your guess was too high." << std::endl;
			else if (guess < number)
				std::cout << "Your guess was too low." << std::endl;

		}
		if (win == false) //if user does not guess within 7 tries
		{
			std::cout << "Sorry, you lose. The correct number was " << number << "." <<
				std::endl;
		}

		do //ask user if they want to play again
		{
			std::cout << "Would you like to play again (y/n)?" << std::endl;
			std::cin >> play;
			win = false;
		} while (play != 'y' && play != 'n');


	} while (play == 'y');

	return 0;

}

