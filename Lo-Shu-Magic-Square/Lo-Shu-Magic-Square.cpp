// Jacob Hardman
// Comp Sci 1
// Professor Jennifer Bailey
// 11/16/19

#include <iostream>
#include <string>

using namespace std;

bool isMagicSquare(int userLoShuSquare[][3]) {
	bool squareChecksOut = true;
	int sum = 0, magicSum = 0;

	//Checking the horizontals
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 3; j++) {
			magicSum += userLoShuSquare[i][j];
		}
	}

	for (int i = 1; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			sum += userLoShuSquare[i][j];
		}
	}

	if (sum != magicSum) { squareChecksOut = false; }

	sum = 0;

	for (int i = 2; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			sum += userLoShuSquare[i][j];
		}
	}

	if (sum != magicSum) { squareChecksOut = false; }

	sum = 0;

	//Checking the verticals
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			sum += userLoShuSquare[i][j];
		}
	}

	if (sum != magicSum) { squareChecksOut = false; }

	sum = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < 2; j++) {
			sum += userLoShuSquare[i][j];
		}
	}

	if (sum != magicSum) { squareChecksOut = false; }

	sum = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 2; j < 3; j++) {
			sum += userLoShuSquare[i][j];
		}
	}

	if (sum != magicSum) { squareChecksOut = false; }

	sum = 0;

	//Checking the diagonals
	sum = userLoShuSquare[0][0] + userLoShuSquare[1][1] + userLoShuSquare[2][2];
	if (sum != magicSum) { squareChecksOut = false; }
	sum = 0;

	sum = userLoShuSquare[0][2] + userLoShuSquare[1][1] + userLoShuSquare[2][0];
	if (sum != magicSum) { squareChecksOut = false; }

	return squareChecksOut;
}

int main()
{
	int notLoShuSquare[3][3] = { {10, 2, 3}, {4, 15, 6}, {7, 8, -8} };
	int isLoShuSquare[3][3] = { {4, 9, 2}, {3, 5, 7}, {8, 1, 6} };
	string userInput;

	bool isRunning = true;
	while (isRunning) {
		int userLoShuSquare[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
		int enteredNums[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << notLoShuSquare[i][j] << " ";
			}
			cout << endl;
		}
		cout << "This is not a Lo Shu Magic Square." << endl;

		cout << endl;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << isLoShuSquare[i][j] << " ";
			}
			cout << endl;
		}
		cout << "This is a Lo Shu Magic Square." << endl;

		cout << endl;

		//Getting the user's Lo Shu Square
		cout << "Please enter 9 unique number between 1 and 9." << endl;
		int counter = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				bool goodInput = false;
				while (!goodInput) {
					bool badInput = false;
					cout << "Number " << counter + 1 << ": ";
					cin >> userLoShuSquare[i][j];

					for (int k = 0; k < 9; k++) {
						if (userLoShuSquare[i][j] < 1 || userLoShuSquare[i][j] > 9) {
							cout << "Please enter a number between 1 and 9." << endl;
							badInput = true;
							break;
						}

						if (userLoShuSquare[i][j] == enteredNums[k]) {
							cout << "Please enter a unique number." << endl;
							badInput = true;
							break;
						}
					}

					if (badInput == false) {
						enteredNums[counter] = userLoShuSquare[i][j];
						counter++;
						goodInput = true;
					}
				}
			}
		}

		bool isLoShu = isMagicSquare(userLoShuSquare);

		cout << endl;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << userLoShuSquare[i][j] << " ";
			}
			cout << endl;
		}
		isLoShu ? cout << "You entered a Lo Shu Magic Square." << endl : cout << "You did not enter a Lo Shu Magic Square." << endl;

		cout << endl;

		bool userConfirm = false;
		while (userConfirm == false) {
			cout << "Would you like to run the program again? (Y/N): ";
			cin >> userInput;

			if (userInput == "Y" || userInput == "y") {
				userConfirm = true;
			}
			else if (userInput == "N" || userInput == "n") {
				userConfirm = true;
				isRunning = false;
			}
			else {
				cout << "Please enter a valid selection." << endl;
			}
		}
	}
}
