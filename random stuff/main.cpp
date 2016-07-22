
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void printBinary(int x);
bool checkCnt(int x);

int main() {

	int test = (1 << 16) - 1;

	int x;
	//cin >> x;
	x = test;

	printBinary(x);
	if (checkCnt(x)) {
		cout << "even count\n";
	}
	else {
		cout << "uneven count\n";
	}

	return 0;
}

void printBinary(int x) {
	for (unsigned mask = 1 << 31; mask > 0; mask >>= 1) {
		if (mask & x) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	cout << endl;
}

bool checkCnt(int x) {

	static unsigned mask = 1 << 31;
	static unsigned o_cnt = 0;
	static unsigned z_cnt = 0;

	if (!mask) {
		cout << "1: " << o_cnt << endl;
		cout << "0: " << z_cnt << endl;
		return o_cnt == z_cnt;
	}

	(mask & x) ? o_cnt++ : z_cnt++;
	mask >>= 1;
	checkCnt(x);
}