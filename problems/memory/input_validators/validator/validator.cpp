#include "validator.h"

#include <cstring>
#include <string>

void run() {
	int n = Int(4, 100);
	int k = Int(2, n - 1);
	int cards[100];
	memset(cards, 0, sizeof(cards));
	for (int i = 0; i < k; ++i) {
		int c = Int(0, n / 2);
		cards[c]++;
		if (cards[c] > 2) die("Too many of card " + to_string(c));
	}
	Endl();
	Eof();
}
