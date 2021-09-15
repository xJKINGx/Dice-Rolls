#include <iostream>
#include <string>
#include <conio.h>
#include <algorithm>

void rollDice();
int returnSixes(int arr[], int size);
void findPairs(int arr[], int size);

int main() {
	std::srand(time(0));
	rollDice();
}

void rollDice() {
	int diceValues[5]{};

	for (int i = 0; i < sizeof(diceValues) / sizeof(diceValues[0]); i++) {
		
		diceValues[i] = std::rand() % 6 + 1;
		std::cout << diceValues[i] << " ";
	}

	std::cout << std::endl;

	std::cout << "Would you like to hold a number? (Y/N): ";
	std::string holdInp{};
	int holdPos{};
	getline(std::cin, holdInp);

	if (holdInp == "Y") {
		std::cout << "Select the position with the value you want to hold: ";
		std::cin >> holdPos;
		holdPos--;
		bool loopHold = true;
		while (loopHold) {
			std::cout << "This is the new group:" << std::endl;
			for (int i = 0; i < sizeof(diceValues) / sizeof(diceValues[0]); i++) {
				if (i != holdPos) {
					diceValues[i] = std::rand() % 6 + 1;
				}
				std::cout << diceValues[i] << " ";
			}
			std::cout << std::endl;
			std::cout << "Press h to stop holding, press any other key to continue." << std::endl;
			char ch = _getch();
			if (ch == 'h') {
				loopHold = false;
			}
		}
	}
	std::cout << "The number of sixes is " << returnSixes(diceValues, 5) << std::endl;
	findPairs(diceValues, 5);
}

int returnSixes(int arr[], int size) {
	int sixAmount{};

	for (int i = 0; i < size; i++) {
		if (arr[i] == 6) {
			sixAmount++;
		}
	}

	return sixAmount;
}

void findPairs(int arr[], int size) {
	std::sort(arr, arr + size);
	
	for (int i = 0; i < size; i++) {
		int firstNum = i;
		int secondNum = i + 1;

		if (arr[firstNum] == arr[secondNum]) {
			//Found Pair
			std::cout << "Found a pair! There is a pair of " << arr[firstNum] << "s!";
			break;
		}
	}
}