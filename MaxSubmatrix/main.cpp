#include <iostream>

#include <vector>
#include <string>

#include <algorithm>

using namespace std;

int sum(vector<vector<int>>& m, int p, int q, int r, int s) {
	int ret = 0;

	for (int i = p; i <= q; ++i) {
		for (int j = r; j <= s; j++) {
			ret += m[i][j];
		}
	}

	return ret;
}

int find_max_submatrix(vector<vector<int>>& m, int& p, int& q, int& r, int& s) {
	int ret = 0;
	int p_cpy = 0, q_cpy = 0, r_cpy = 0, s_cpy = 0;

	for (p = 0; p < m.size(); ++p) {
		for (q = p; q < m.size(); ++q) {
			for (r = 0; r < m[0].size(); r++) {
				for (s = r; s < m[0].size(); s++) {
					if (sum(m, p, q, r, s) > ret) {
						ret = sum(m, p, q, r, s);
						p_cpy = p;
						q_cpy = q;
						r_cpy = r;
						s_cpy = s;
					}
				}
			}
		}
	}

	p = p_cpy;
	q = q_cpy;
	r = r_cpy;
	s = s_cpy;
	return ret;
}

int main() {
	int m = 0, n = 0;
	cin >> n >> m;

	vector<vector<int>> mat;
	mat.resize(n);
	for (int i = 0; i < mat.size(); i++) {
		mat[i].assign(m, 0);
	}

	int val = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; ++j) {
			cin >> val;
			mat[i][j] = val;
		}
	}

	int p = 0, q = 0, r = 0, s = 0;
	find_max_submatrix(mat, p, q, r, s);

	printf("p=%d q=%d r=%d s=%d\n", p + 1, q + 1, r + 1, s + 1);

	system("pause");
	return 0;
}