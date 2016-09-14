#include <iostream>

#include <string>

#include <algorithm>

using namespace std;

int main() {
	int n[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string r[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	int num = 0;
	scanf_s("%d", &num);

	string ret;
	while (num) {
		for (int i = 0; i < sizeof(n) / sizeof(n[0]); ++i) {
			int cur = num / n[i];
			if (cur > 0) {
				num = num - cur * n[i];
				while (cur--) {
					ret += r[i];
				}
				break;
			}
		}
	}

	printf("%s\n", ret.c_str());

	system("pause");
	return 0;
}