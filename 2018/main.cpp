#include "game_board.h"
#include <iostream>
#include <iomanip>

int maxLen(int(*arr)[3]);

int main() {

	GameBoard::getInstance().play();
	return 7;

	int arr[3][3] = { { 32,   3,    4 },
					  {  4, 643,   23 },
					  {  4,  23,  100 } };

	int w = maxLen(arr);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << '|' << std::setw(w) << arr[i][j];
		}
		std::cout << '|' << std::endl;
	}
	std::cout << std::endl;

	return 0;
}

int maxLen(int(*arr)[3]) {
	int max = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int curLen = log10(arr[i][j]) + 1;
			if (curLen > max)
				max = curLen;
		}
	}
	return max;
}