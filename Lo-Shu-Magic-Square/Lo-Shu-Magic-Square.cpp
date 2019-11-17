// Jacob Hardman
// Comp Sci 1
// Professor Jennifer Bailey
// 11/16/19

#include <iostream>

using namespace std;

bool isMagicSquare(int isLoShuSquare[][3]) {
	bool squareChecksOut = true;
	int sum = 0, magicSum = 0;

	//Checking the horizontals
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 3; j++) {
			magicSum += isLoShuSquare[i][j];
		}
	}

	for (int i = 1; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			sum += isLoShuSquare[i][j];
		}
	}

	if (sum != magicSum) { squareChecksOut = false; }

	sum = 0;

	for (int i = 2; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			sum += isLoShuSquare[i][j];
		}
	}

	if (sum != magicSum) { squareChecksOut = false; }

	sum = 0;

	//Checking the verticals
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			sum += isLoShuSquare[i][j];
		}
	}

	if (sum != magicSum) { squareChecksOut = false; }

	sum = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < 2; j++) {
			sum += isLoShuSquare[i][j];
		}
	}

	if (sum != magicSum) { squareChecksOut = false; }

	sum = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 2; j < 3; j++) {
			sum += isLoShuSquare[i][j];
		}
	}

	if (sum != magicSum) { squareChecksOut = false; }

	sum = 0;

	//Checking the diagonals
	sum = isLoShuSquare[0][0] + isLoShuSquare[1][1] + isLoShuSquare[2][2];
	if (sum != magicSum) { squareChecksOut = false; }
	sum = 0;

	sum = isLoShuSquare[0][2] + isLoShuSquare[1][1] + isLoShuSquare[2][0];
	if (sum != magicSum) { squareChecksOut = false; }

	return squareChecksOut;
}

int main()
{
	int notLoShuSquare[3][3] = { {10, 2, 3}, {4, 15, 6}, {7, 8, -8} };
	int isLoShuSquare[3][3] = { {4, 9, 2}, {3, 5, 7}, {8, 1, 6} };

	bool isLoShu = isMagicSquare(isLoShuSquare);

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
	isLoShu ? cout << "This is a Lo Shu Magic Square." << endl : cout << "This is also not a Lo Shu Magic Square." << endl;
}
