#include <cstdlib>
#include <cstdio>

class Solution {
public:
	int divide(int dividend, int divisor) {
		int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
		long long res = 0, m = abs((long long)dividend), n = abs((long long)divisor);
		while (m >= n) {
			long long t = n, i = 1;
			while (t << 1 < m) {
				t <<= 1;
				i <<= 1;
			}
			m -= t;
			res += i;
		}

		res *= sign;
		return res > INT_MAX ? INT_MAX : res;;
	}
};

int main(int argc, char** argv) {
	int dividend, divisor;
	scanf_s("%d %d", &dividend, &divisor);

	Solution sl;
	int ret = sl.divide(dividend, divisor);

	return EXIT_SUCCESS;
}