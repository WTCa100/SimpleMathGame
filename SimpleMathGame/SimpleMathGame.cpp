#include<iostream>
#include<conio.h>
#include<ctime>
#include<string>

int16_t nDificult = 0;
bool bGameOn = true;
int nScore = 0;
void DificultSelection();
void Problems(uint16_t nDif);
bool bValidStrin(std::string sAns);
char sWhatAction(int nRandomInt);
void AskForNextAct();
void ShowPoint();

int main(void)
{
	srand(time(NULL));
	system("title Super Math Game! - By John \"WTCa100\" Bielawa");
	std::cout << "Hello and welcome to my first official C++ project!\n";
	std::cout << "The idea of this project is simple - the program will show you calculation and you will have to guess the right answer.\n";
	std::cout << "Every time the answer problem is shown you will get a shor period of time to calculate it.\n";
	std::cout << "Best of luck!\n";
	_getch();
	system("cls");
	printf("NOTICE: This version of the game will no longer be supported. If you want to try the new version you can find it here:\n");
	printf("https://github.com/WTCa100/SimpleMathGameV2");
	_getch();
	system("cls");
	while (bGameOn)
	{
		nScore = 0;
		nDificult = 0;
		DificultSelection();
		system("cls");
		Problems(nDificult);
		ShowPoint();
		AskForNextAct();
	}
}

void DificultSelection()
{
	do
	{
		std::string tmp = "";
		std::cout << "Choose your difficulty level:\n";
		std::cout << "1. Easy\n";
		std::cout << "2. Medium\n";
		std::cout << "3. Hard\n";
		std::cout << "4. Math Teacher\t -> \t Try it on SimpleMathGameV2!\n"; // 4th and 5th difficult option will be added in future
		std::cout << "5. Pure math PROfessor (chad)\t -> \t Try it on SimpleMathGameV2!\n";
		std::getline(std::cin, tmp);
		if ((int)tmp[0] < '0' || (int)tmp[0] > '5')
		{
			std::cout << "Please enter a valid number from 1 to 5!\n";
			_getch();
			system("cls");
		}
		else
		{

			nDificult = std::stoi(tmp);
		}
	} while (nDificult < 1 || nDificult > 5);
}

char sWhatAction(int nRandomInt)
{
	switch (nRandomInt)
	{
	case 1:
	{
		return '+';
		break;
	}
	case 2:
	{
		return '-';
		break;
	}
	case 3:
	{
		return '/';
		break;
	}
	case 4:
	{
		return '*';
		break;
	}
	}
}

void ShowPoint()
{
	printf("You scored %d points!", nScore);
	_getch();
	system("cls");
}

void AskForNextAct()
{
	std::string sOption = "";
	uint16_t unOption = 1;
	do {

		printf("Would you like to play again?\n");
		printf("1. Yes 2. No"); // Later on add HighScore that will save and sort the scores from min to max and then display only the top 10 ones
		printf("\nWarning! By selecting No option the game will close\n");
		std::getline(std::cin, sOption);
		if (sOption[0] != '1' && sOption[0] != '2')
		{
			printf("Invalid answer!");
			_getch();
			system("cls");
		}
		else
		{
			unOption = std::stoi(sOption);
		}
	} while (unOption != 1 && unOption != 2);
	if (unOption == 2) bGameOn = false;
	else system("cls");
}

bool bValidStrin(std::string sAns)
{
	for (int i = 0; i < sAns.size(); i++)
	{
		if (!(sAns[i] == '-' || isdigit(sAns[i])))
			return false;
	}
	return true;
}

void Problems(uint16_t nDif) {
	int nNumber1 = 0, nNumber2 = 0;
	srand(time(NULL));
	char cExercise;
	std::string sUserAnswer;

	switch (nDif)
	{
	case 1:
	{
		for (int i = 0; i < 10 * nDif; i++)
		{
			bool bIsCorrect = false;
			cExercise = ' ';
			int nAction = rand() % 4 + 1;
			cExercise = sWhatAction(nAction);
			// From difficult level 1 to 3 Number 1 should be devidable by number 2
			if (nAction == 3)
			{
				do
				{
					nNumber1 = rand() % 100 + 1;
					nNumber2 = rand() % 100 + 1;
					if (nNumber1 <= nNumber2)
					{
						nNumber1 = rand() % 100 + 1;
						nNumber2 = rand() % 100 + 1;

						if (nNumber1 % nNumber2 != 0 || nNumber1 == nNumber2)
						{
							nNumber2 = rand() % 100 + 1;
						}
					}
				} while (nNumber1 <= nNumber2 || nNumber1 % nNumber2 != 0);
			}
			else if (nAction == 4)
			{
				nNumber1 = rand() % 10 + 1;
				nNumber2 = rand() % 10 + 1;
			}
			else if(nAction == 1)
			{
				nNumber1 = rand() % 50 + 1;
				nNumber2 = rand() % 25 + 1;
			}
			else
			{
				nNumber1 = rand() % 50 + 51;
			}
			do
			{
				std::cout << "Problem " << i + 1 << "\t" << "Score: " << nScore << std::endl;
				printf_s("%d %c %d = ", nNumber1, cExercise, nNumber2);
				std::getline(std::cin, sUserAnswer);
				if (!bValidStrin(sUserAnswer) || sUserAnswer[0] == '\0')
				{
					std::cout << "Not a valid answer!" << std::endl;
					_getch();
					system("cls");
				}
				else
				{
					switch (nAction)
					{
					case 1: {
						if (std::stoi(sUserAnswer) == nNumber1 + nNumber2)
						{
							nScore += 10;
							bIsCorrect = true;
							
						}
					break;
					}
					case 2: {
						if (std::stoi(sUserAnswer) == nNumber1 - nNumber2)
						{
							nScore += 10;
							bIsCorrect = true;
						}
						break;
					}
					case 3: {
						if (std::stoi(sUserAnswer) == nNumber1 / nNumber2)
						{
							nScore += 10;
							bIsCorrect = true;
						}
						break;
					}
					case 4: {
						if (std::stoi(sUserAnswer) == nNumber1 * nNumber2)
						{
							nScore += 10;
							bIsCorrect = true;
						}
						break;
					}
					}	
				}
			} while (!bValidStrin(sUserAnswer) || sUserAnswer[0] == '\0');
			system("cls");
		}
		break;
	}
	case 2: {
		for (int i = 0; i < 10 * nDif; i++)
		{
			bool bIsCorrect = false;
			cExercise = ' ';
			int nAction = rand() % 4 + 1;
			cExercise = sWhatAction(nAction);
			switch (nAction)
			{
			case 3:
			{
				nNumber1 = rand() % 1000 + 1;
				do
				{
					nNumber2 = rand() % 100 + 1;
					if (nNumber2 == 1)
						nNumber2 = rand() % 100 + 1;
				} while (nNumber1 % nNumber2 != 0 || nNumber2 >= nNumber1);
				break;
			}
			case 4:
			{
				nNumber1 = rand() % 30 + 5;
				if (nNumber1 > 50)
				{
					nNumber2 = rand() % 25 + 5;
				}
				else
				{
					nNumber2 = rand()% 25 + 5;
				}
				break;
			}
			case 2:
			{
				nNumber1 = rand() % 100 + 50;
				nNumber2 = rand() % 100 + 50;
				break;
			}
			case 1:
			{
				nNumber1 = rand() % 100 + 50;
				nNumber2 = rand() % 100 + 50;
				break;
			}
			}
			do
			{
				std::cout << "Problem " << i + 1 << "\t" << "Score: " << nScore << std::endl;
				printf_s("%d %c %d = ", nNumber1, cExercise, nNumber2);
				std::getline(std::cin, sUserAnswer);
				if (!bValidStrin(sUserAnswer) || sUserAnswer[0] == '\0')
				{
					std::cout << "Not a valid answer!" << std::endl;
					_getch();
					system("cls");
				}
				else
				{
					switch (nAction)
					{
					case 1: {
						if (std::stoi(sUserAnswer) == nNumber1 + nNumber2)
						{
							nScore += 20;
							bIsCorrect = true;
							break;
						}
					}
					case 2: {
						if (std::stoi(sUserAnswer) == nNumber1 - nNumber2)
						{
							nScore += 20;
							bIsCorrect = true;
							break;
						}
					}
					case 3: {
						if (std::stoi(sUserAnswer) == nNumber1 / nNumber2)
						{
							nScore += 20;
							bIsCorrect = true;
							break;
						}
					}
					case 4: {
						if (std::stoi(sUserAnswer) == nNumber1 * nNumber2)
						{
							nScore += 20;
							bIsCorrect = true;
							break;
						}
					}
					}
				}
			} while (!bValidStrin(sUserAnswer) || sUserAnswer[0] == '\0');
			system("cls");
		}
		break;
	}
	case 3: {
		for (int i = 0; i < 10 * nDif; i++)
		{
			bool bIsCorrect = false;
			cExercise = ' ';
			int nAction = rand() % 4 + 1;
			cExercise = sWhatAction(nAction);
			switch (nAction)
			{
			case 3:
			{
				nNumber1 = rand() % 9000 + 1001; // From 0 to 8999 + 1001 so from 1001 to 10000
				do
				{
					nNumber2 = rand() % 100 + 1;
					if (nNumber2 == 1)
						nNumber2 = rand() % 100 + 1; // From 0 to 99 + 1 so from 1 to 100 
				} while (nNumber1 % nNumber2 != 0 || nNumber2 >= nNumber1);
				break;
			}
			case 4:
			{
				nNumber1 = rand() % 100 + 51;
				if (nNumber1 > 90)
				{
					nNumber2 = rand() % 50 + 1;
				}
				else
				{
					nNumber2 = rand() % 100 + 51;
				}
				break;
			}
			case 2:
			{
				nNumber1 = rand() % 9000 + 1000;
				nNumber2 = rand() % 9000 + 1000;
				break;
			}
			case 1:
			{
				nNumber1 = rand() % 9000 + 1000; // From 0 to 8999 + 1000 so from 1000 to 9999 
				nNumber2 = rand() % 9000 + 1000;
				break;
			}
			}
			do
			{
				std::cout << "Problem " << i + 1 << "\t" << "Score: " << nScore << std::endl;
				printf_s("%d %c %d = ", nNumber1, cExercise, nNumber2);
				std::getline(std::cin, sUserAnswer);
				if (!bValidStrin(sUserAnswer) || sUserAnswer[0] == '\0')
				{
					std::cout << "Not a valid answer!" << std::endl;
					_getch();
					system("cls");
				}
				else
				{
					switch (nAction)
					{
					case 1: {
						if (std::stoi(sUserAnswer) == nNumber1 + nNumber2)
						{
							nScore += 30;
							bIsCorrect = true;
						}
						break;
					}
					case 2: {
						if (std::stoi(sUserAnswer) == nNumber1 - nNumber2)
						{
							nScore += 30;
							bIsCorrect = true;
						}
						break;
					}
					case 3: {
						if (std::stoi(sUserAnswer) == nNumber1 / nNumber2)
						{
							nScore += 30;
							bIsCorrect = true;
						}
						break;
					}
					case 4: {
						if (std::stoi(sUserAnswer) == nNumber1 * nNumber2)
						{
							nScore += 30;
							bIsCorrect = true;
						}
						break;
					}
					}
				}
			} while (!bValidStrin(sUserAnswer) || sUserAnswer[0] == '\0');
			system("cls");
		}
		break;
	}
		  //TODO 2 hardest options - they are avilable in the new game in V2
	}
} 