#pragma once

template <typename T>

class myVector {
private:
	T* data;
	unsigned size;
	unsigned elCnt;

public:
	myVector() : size(8), elCnt(0) {
		data = new T[size];
	}
	~myVector() { delete[] data; }

private:
	void clearData() {
		delete[] data;
		size = 0;
		elCnt = 0;
	}
	void deepCopy(myVector& src) {
		this->clearData();
		this->data = new T[src.size];
		for (int i = 0; i < src.elCnt; i++) {
			// copy ??? 
		}
	}
};