#pragma once


class Movement {
private:
	int(*board)[4];
	bool fake;
	int width;

public:
	Movement() {}
	Movement(int(*bPtr)[4]);

	void move(char type);

	void setFakeStat(bool stat);
	bool getFakeStat();

	int getWidth() const;

private:
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	
	void incrWidth();
};