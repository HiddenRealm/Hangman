/// Hangman Game.
/// This is for assignment 1 of software programing.
/// This code should simulate my interpretation of the classic hangman game.

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

//Difining Functions
void Words(char _wordo[], int Dif);
void Draw(int num_guess);
int Game(int Dif, int score);
void Instructions();
int Difficulty(int Dif);
int Menu(int choice, int score);
int End(bool outcome, int score, int Dif);

int main()
{
	//Difining important variables
	int Dif = 1, choice = 0, score = 0;

	//Main executable loop
	while (true)
	{
		system("cls");

		//Title
		std::cout << " 00   00                                000      000                     " << std::endl;
		std::cout << " 00   00   0000   0000     00 000000000 0000    0000   0000   0000     00" << std::endl;
		std::cout << " 00   00  00  00  00 00    00 00        00 00  00 00  00  00  00 00    00" << std::endl;
		std::cout << " 0000000  00  00  00  00   00 00        00  0000  00  00  00  00  00   00"<< std::endl;
		std::cout << " 0000000 00000000 00   00  00 00        00   00   00 00000000 00   00  00" << std::endl;
		std::cout << " 00   00 00    00 00    00 00 00   0000 00        00 00    00 00    00 00" << std::endl;
		std::cout << " 00   00 00    00 00     0000 00    00  00        00 00    00 00     0000" << std::endl;
		std::cout << " 00   00 00    00 00       00 00000000  00        00 00    00 00       00" << std::endl;
		
		//Calls open the menu
		choice = Menu(choice, score);

		//Runs the function called by the menu
		switch (choice)
		{
		case 1: score = Game(Dif, score);
			break;
		case 2: Instructions();
			break;
		case 3: Dif = Difficulty(Dif);
			break;
		case 4: return 0;
			break;
		}
	}

	return 0;

}

int Menu(int choice, int score)
{
	//Outputs menu and currect score
	while (true)
	{
		std::cout << "\n===============================================" << std::endl;
		std::cout << "1 - Play Game: Score " << score << std::endl;
		std::cout << "2 - Instructions" << std::endl;
		std::cout << "3 - Difficulty" << std::endl;
		std::cout << "4 - Exit" << std::endl;
		std::cout << "===============================================" << std::endl;
		std::cin >> choice;

		//Makes sure it doesnt return nonsense
		if (choice > 0 && choice <= 4)
		{
			return choice;
		}
	}
}

int Game(int Dif, int score)
{
	system("cls");

	//Defining more variables
	int  num_guess = 6, length = 0, t = 0;
 	bool outcome = false, guessed = false;
	char secretWord[50] = { 0 };
	char wordsoFar[13] = { 0 };
	char tries[26] = { 0 };
	char guess;

	//Gets the secretword, length of it and draws the first stages of gallows
	Words(&secretWord[0], Dif);
	length = strlen(secretWord);
	Draw(num_guess);

	//Sets the array to be the same length as the secretword filled with * and the rest to stay NULL
for (int i = 0; i < length; i++)
	{
		wordsoFar[i] = '*';
	}

	//Main game loop
	do
	{
		//Tests to see if to play the game or if it has been won/lost.
		if (num_guess < 1)
		{
			outcome = false;
			std::cout << "The word was " << secretWord << "." << std::endl;
			Sleep(2000);
			score = End(outcome, score, Dif);
			return score;
		}
		else if (guessed == true)
		{
			outcome = true;
			score = End(outcome, score, Dif);
			return score;
		}
		else
		{
			bool correct = false;

			//Displays what letters you have tried and lives left
			std::cout << "You have tried " << tries << "." <<  std::endl;
			std::cout << "You have " << num_guess << " lives left." << std::endl;

			//Displays the the word as you know it
			for (int i = 0; i < length; i++)
			{
				std::cout << wordsoFar[i];
			}
			
			std::cout << std::endl << "\nGuess? ";
			std::cin >> guess;

			//Adds your guess to the tries array and moves the array to the next slot.
			tries[t] = guess;
			t++;

			//Checks to see if the letter guessed matchs any from the secretword
			for (int i = 0; i < length; i++)
			{
				if (guess == secretWord[i])
				{
					//Adds the letter guessed to the correct space in the word as you know it
					wordsoFar[i] = guess;
					//Redraws the gallows (allowing everything else to be redrawn in the correct places)
					Draw(num_guess);
					correct = true;
					guessed = true;

					//Test to see if all of the word as you know it matchs the secretword
					for (int i = 0; i < (length + 1); i++)
					{
						if (wordsoFar[i] == secretWord[i])
						{

						}
						else
						{
							//If any are wrong it changes guessed to false.
							guessed = false;
						}
					}
				}
			}

			//Checks to see if you got the letter correct.
			if (correct == false)
			{
				num_guess = num_guess - 1;
				Draw(num_guess);
			}
		}


	} while (true);
	return 0;
}

void Instructions()
{
	int instru = 0;
	system("cls");
	
	//Displayes Instructions >.>
	std::cout << "\n================================================================================" << std::endl;
	std::cout << "The whole point is to try to guess the word." << std::endl;
	std::cout << "You can have five incorrect guesses before you lose." << std::endl;
	std::cout << "You have to guess each letter at a time." << std::endl;
	std::cout << "Simply enter the lower case letters you want to guess and hit enter." << std::endl;
	std::cout << "Make sure to only use one letter at a time." << std::endl;
	std::cout << "There are three difficulties you can choose from, these change the word length." << std::endl;
	std::cout << "Simply input 1 to go back to the menu." << std::endl;
	std::cout << "\n================================================================================" << std::endl;
	std::cin >> instru;

	if (instru > 0 && instru <= 1)
	{
		system("cls");
		return;
	}
}

int Difficulty(int Dif)
{
	system("cls");
	int difficulty = 0;

	//Gets Difficulty >.>
	while (true)
	{
		std::cout << "\n==================" << std::endl;
		std::cout << "1 - Easy" << std::endl;
		std::cout << "2 - Medium" << std::endl;
		std::cout << "3 - Hard" << std::endl;
		std::cout << "==================" << std::endl;
		std::cin >> difficulty;

		if (difficulty > 0 && difficulty <= 3)
		{
			Dif = difficulty;
			system("cls");
			return Dif;
		}
	}

}

void Words(char _secretWord[], int Dif)
{
	//Picks a random number from 0-9
	srand(time(NULL));
	int random_num = 0;
	char secretWord[4] = { 0 };
	random_num = rand() % 9;

	//Checks what difficulty you are playing on, then chooses the word from the switch that matchs the random number
	while (true)
	{
		if (Dif == 1)
		{
			while (true)
			{
				switch (random_num)
				{
				case 0: strcpy(_secretWord, "dog");
					break;
				case 1: strcpy(_secretWord, "can");
					break;
				case 2: strcpy(_secretWord, "tin");
					break;
				case 3: strcpy(_secretWord, "mix");
					break;
				case 4: strcpy(_secretWord, "cup");
					break;
				case 5: strcpy(_secretWord, "bag");
					break;
				case 6: strcpy(_secretWord, "kid");
					break;
				case 7: strcpy(_secretWord, "sip");
					break;
				case 8: strcpy(_secretWord, "oil");
					break;
				case 9: strcpy(_secretWord, "ace");
					break;
				}
				return;
			}
		}
		else if (Dif == 2)
		{
			while (true)
			{
				switch (random_num)
				{
				case 0: strcpy(_secretWord, "pizza");
					break;
				case 1: strcpy(_secretWord, "puzzle");
					break;
				case 2: strcpy(_secretWord, "simple");
					break;
				case 3: strcpy(_secretWord, "pyjamas");
					break;
				case 4: strcpy(_secretWord, "jump");
					break;
				case 5: strcpy(_secretWord, "cozily");
					break;
				case 6: strcpy(_secretWord, "belief");
					break;
				case 7: strcpy(_secretWord, "invest");
					break;
				case 8: strcpy(_secretWord, "agree");
					break;
				case 9: strcpy(_secretWord, "ratio");
					break;
				}
				return;
			}
		}
		else
		{
			while ( true)
			{
				switch (random_num)
				{
				case 0: strcpy(_secretWord, "refrigerator");
					break;
				case 1: strcpy(_secretWord, "addition");
					break;
				case 2: strcpy(_secretWord, "commence");
					break;
				case 3: strcpy(_secretWord, "schedule");
					break;
				case 4: strcpy(_secretWord, "jackhammer");
					break;
				case 5: strcpy(_secretWord, "abomination");
					break;
				case 6: strcpy(_secretWord, "pleasantries");
					break;
				case 7: strcpy(_secretWord, "tumbleweeds");
					break;
				case 8: strcpy(_secretWord, "syllabicate");
					break;
				case 9: strcpy(_secretWord, "dictation");
					break;
				}
				return;
			}
		}
	}
}

void Draw(int num_guess)
{
	//Big switch to draw and redraw the gallows
	switch (num_guess)
	{
	case 1:
		{
			system("cls");

			std::cout << " _________    " << std::endl;
			std::cout << "|         |   " << std::endl;
			std::cout << "|         0   " << std::endl;
			std::cout << "|        /|\\ " << std::endl;
			std::cout << "|          \\ " << std::endl;
			std::cout << "|             " << std::endl;
			std::cout << "|_            " << std::endl;
		}
		break;
	case 2:
		{
			system("cls");

			std::cout << " _________    " << std::endl;
			std::cout << "|         |   " << std::endl;
			std::cout << "|         0   " << std::endl;
			std::cout << "|        /|\\ " << std::endl;
			std::cout << "|             " << std::endl;
			std::cout << "|             " << std::endl;
			std::cout << "|_            " << std::endl;
		}
		break;
	case 3:
		{
			system("cls");
			 
			std::cout << " _________    " << std::endl;
			std::cout << "|         |   " << std::endl;
			std::cout << "|         0   " << std::endl;
			std::cout << "|        /|   " << std::endl;
			std::cout << "|             " << std::endl;
			std::cout << "|             " << std::endl;
			std::cout << "|_            " << std::endl;
		}
		break;
	case 4:
		{
			system("cls");
		
			std::cout << " _________   " << std::endl;
			std::cout << "|         |  " << std::endl;
			std::cout << "|         0  " << std::endl;
			std::cout << "|         |  " << std::endl;
			std::cout << "|            " << std::endl;
			std::cout << "|            " << std::endl;
			std::cout << "|_           " << std::endl;
		}
	break;
	case 5:
		{
			system("cls");

			std::cout << " _________   " << std::endl;
			std::cout << "|         |  " << std::endl;
			std::cout << "|         0  " << std::endl;
			std::cout << "|            " << std::endl;
			std::cout << "|            " << std::endl;
			std::cout << "|            " << std::endl;
			std::cout << "|_           " << std::endl;
		}
	break;
	case 6:
		{
			system("cls");

			std::cout << " _________   " << std::endl;
			std::cout << "|         |  " << std::endl;
			std::cout << "|            " << std::endl;
			std::cout << "|            " << std::endl;
			std::cout << "|            " << std::endl;
			std::cout << "|            " << std::endl;
			std::cout << "|_           " << std::endl;
		}
	break;
	}
}

int End(bool outcome, int score, int Dif)
{
	//If statement to check if you have won or not.
	if (outcome == true)
	{
		system("cls");

		std::cout << "00      00                                       " << std::endl;
		std::cout << "00      00 00 00000000 00000000 00000000  0000000" << std::endl;
		std::cout << "00      00    00    00 00    00 00        00     " << std::endl;
		std::cout << "00  00  00 00 00    00 00    00 00        00     " << std::endl;
		std::cout << "00  00  00 00 00    00 00    00 0000      00     " << std::endl;
		std::cout << "00  00  00 00 00    00 00    00 00        00     " << std::endl;
		std::cout << "00  00  00 00 00    00 00    00 00        00     " << std::endl;
		std::cout << "0000000000 00 00    00 00    00 00000000  00     " << std::endl;

		//Seeing the difficulty you won on to award you more points
		if (Dif == 1)
		{
			score = score + 1;
		}
		else if (Dif == 2)
		{
			score = score + 2;
		}
		else if (Dif == 3)
		{
			score = score + 3;
		}

		Sleep(2000);
		return score;
	}
	else if (outcome == false)
	{
		system("cls");

		std::cout << "00                                        " << std::endl;
		std::cout << "00       00000000  0000000 0000000 0000000" << std::endl;
		std::cout << "00       00    00  00      00      00     " << std::endl;
		std::cout << "00       00    00  00      00      00     " << std::endl;
		std::cout << "00       00    00  0000000 0000    00     " << std::endl;
		std::cout << "00       00    00       00 00      00     " << std::endl;
		std::cout << "00       00    00       00 00      00     " << std::endl;
		std::cout << "00000000 00000000  0000000 0000000 00     " << std::endl;

		Sleep(2000);
		
		//Taking only 1 score away because im nice like that.
		if (score > 0)
		{
			score = score - 1;
		}

		return score;
	}
}