#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <sstream>
#include <string>
#include <vector>
#include <map>

#include <algorithm>

void two_sum_traverse(int arr[], const int& size, const int& target) {
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (arr[i] == (target - arr[j])) {
				printf("index1=%d, index2=%d\n", i + 1, j + 1);
			}
		}
	}
}

void two_sum_sort(int arr[], const int& size, const int& target) {
	std::vector<int> arr_cpy(size);
	std::copy(arr, arr + size, arr_cpy.begin());

	std::sort(arr_cpy.begin(), arr_cpy.end());

	int l = 0, r = size - 1;

	while (l < r) {
		if ((arr[r] + arr_cpy[l]) == target) {
			int* l_ptr = std::find(arr, arr + size, arr[l]);
			int* r_ptr = std::find(arr, arr + size, arr[r]);

			int i = int(l_ptr - arr);
			int j = int(r_ptr - arr);

			printf("index1=%d, index2=%d\n", i + 1, j + 1);

			++l;
		}

		if ((arr_cpy[r] + arr_cpy[l]) > target) {
			--r;
		}

		if ((arr_cpy[r] + arr_cpy[l]) < target) {
			++l;
		}
	}

	arr_cpy.clear();
	arr_cpy.shrink_to_fit();
}

void two_sum_hash(int arr[], const int& size, const int& target) {
	std::map<int, int> m;
	for (int i = 0; i < size; ++i){
		if (m.find(target - arr[i]) != m.end())	{
			printf("index1=%d, index2=%d\n", m[target - arr[i]] + 1, i + 1);
		}
		m[arr[i]] = i;
	}

}

int main() {
	std::string str;
	printf("numbers:");
	std::getline(std::cin, str);

	std::stringstream ss;
	ss.str(str);
	
	std::string sub_str;
	std::vector<int> arr;

	while (std::getline(ss, sub_str, ',')) {
		arr.push_back(atoi(sub_str.c_str()));
	}

	printf("target:");
	int target = 0;
	scanf_s("%d", &target);

	// you can replace it with others 
	two_sum_hash(arr.data(), (int)arr.size(), target);

	arr.clear();
	arr.shrink_to_fit();


	system("pause");

	return EXIT_SUCCESS;
}