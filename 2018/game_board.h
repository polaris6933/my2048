#pragma once

#include "movement.h"

class GameBoard {

private:
	int board[4][4];
	Movement curMove;

private:
	GameBoard();
	GameBoard(const GameBoard& src) = delete;
	void operator=(const GameBoard& src) = delete;
	~GameBoard() {}

public:
	static GameBoard& getInstance();

	void play();

private:
	void print() const;
	void setPos(int, int, int);
	void getMove();
	void generateRandom();
};