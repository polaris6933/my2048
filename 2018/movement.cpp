#include "game_board.h"
#include <cmath>

Movement::Movement(int(*bPtr)[4]) 
	: board(bPtr), fake(true), width(1) {}

void Movement::move(char type) {
	switch (type) {
	case 'w': moveUp(); return;
	case 's': moveDown(); return;
	case 'a': moveLeft(); return;
	case 'd': moveRight(); return;
	default: return;
	}
}

void Movement::setFakeStat(bool stat) {
	fake = stat;
}

bool Movement::getFakeStat() {
	return fake;
}

void Movement::incrWidth() {
	width++;
}

int Movement::getWidth() const {
	return width;
}

void Movement::moveUp() {
	for (int i = 1; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j]) {
				int t = i;
				bool add = board[t][j] == board[t - 1][j];
				while ((!board[t - 1][j] || add) && t > 0) {
					board[t - 1][j] += board[t][j];
					board[t][j] = 0;
					fake = false;
					if (add) {
						if ((int)log10(board[t - 1][j]) + 1 > width) {
							incrWidth();
						}
						break;
					}
					t--;
				}
			}
		}
	}
}

void Movement::moveDown() {
	for (int i = 3; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j]) {
				int t = i;
				bool add = board[t][j] == board[t + 1][j];
				while ((!board[t + 1][j] || add) && t < 3) {
					board[t + 1][j] += board[t][j];
					board[t][j] = 0;
					fake = false;
					if (add) {
						if ((int)log10(board[t + 1][j]) + 1 > width) {
							incrWidth();
						}
						break;
					}
					t++;
				}
			}
		}
	}
}

void Movement::moveLeft() {
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (board[i][j]) {
				int t = j;
				bool add = board[i][t] == board[i][t - 1];
				while ((!board[i][t - 1] || add) && t > 0) {
					board[i][t - 1] += board[i][t];
					board[i][t] = 0;
					fake = false;
					if (add) {
						if ((int)log10(board[i][t - 1]) + 1 > width) {
							incrWidth();
						}
						break;
					}
					t--;
				}
			}
		}
	}
}

void Movement::moveRight() {
	for (int i = 0; i < 4; i++) {
		for (int j = 2; j >= 0; j--) {
			if (board[i][j]) {
				int t = j;
				bool add = board[i][t] == board[i][t + 1];
				while ((!board[i][t + 1] || add) && t < 3) {
					board[i][t + 1] += board[i][t];
					board[i][t] = 0;
					fake = false;
					if (add) { 
						if ((int)log10(board[i][t + 1]) + 1 > width) {
							incrWidth();
						}
						break; 
					}
					t++;
				}
			}
		}
	}
}