#include "game_board.h"
#include <iostream>
#include <conio.h>
#include <iomanip>

GameBoard::GameBoard() : curMove(board) {
	generateRandom();
	generateRandom();
}

GameBoard& GameBoard::getInstance() {
	static GameBoard theBoard;
	return theBoard;
}

void GameBoard::play() {
	while (true) {
		print();
		curMove.setFakeStat(true);
		getMove();
		if (!curMove.getFakeStat()) {
			generateRandom();
		}
		system("cls");
	}
}

void GameBoard::setPos(int y, int x, int val) {
	board[y][x] = val;
}

void GameBoard::getMove() {
	char t = getch();
	if (t == 'w' || t == 'a' || t == 's' || t == 'd') {
		curMove.move(t);
	}
} 

void GameBoard::print() const {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << '|';
			if (board[i][j]) {
				std::cout << std::setw(curMove.getWidth()) << board[i][j];
			}
			else {
				std::cout << std::setw(curMove.getWidth() + 1);
			}
		}
		std::cout << '|' << std::endl;
	}
	std::cout << std::endl;
}

void GameBoard::generateRandom() {

	srand(time(0));

	int posX, posY, val;

	do {
		posX = rand() % 4;
		posY = rand() % 4;
	} while (board[posY][posX]);

	val = (((rand() % 2) + 1) * 2);
	setPos(posY, posX, val);
}