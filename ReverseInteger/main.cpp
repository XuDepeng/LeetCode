#include <cstdlib>
#include <cstdio>

#include <iostream>

int reverse(int x) {
	int res = 0;
	while (x) {
		if (abs(res) > INT_MAX / 10) {
			return 0;
		}

		int rem = x % 10;
		res = res * 10 + rem;
		x /= 10;
	}

	return res;
}

int main() {
	int num = 0;
	std::cin >> num;

	int res = reverse(num);
	printf("%d\n", res);

	system("pause");
	return EXIT_SUCCESS;
}