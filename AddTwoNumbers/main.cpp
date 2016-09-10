#include <cstdio>
#include <cstdlib>

#include <iostream>

#include <string>
#include <vector>
#include <sstream>

#include "list.h"

List<int> add_two_num_list(List<int>& lhs, List<int>& rhs) {
	int len_l = lhs.size();
	int len_r = rhs.size();

	if (len_r > len_l) { 
		// std::swap(rhs, lhs);
		for (int i = len_l; i < len_r; ++i) {
			rhs.push_back(0);
		}
	}

	List<int> ret;

	int accum = 0;
	for (int i = 0; i < rhs.size();++i) {
		int temp = lhs.at(i) + rhs.at(i) + accum;
		accum = 0;
		ret.push_back(temp % 10);
		accum += temp / 10;
	}

	if (accum>0){
		ret.push_back(accum);
	}

	return ret;
}

List<int> add_two_num_simple(List<int>& lhs, List<int>& rhs) {	
	int int_lhs = 0, int_rhs = 0;
	int base = 1;
	for (List<int>::iterator iter = lhs.begin(); iter != lhs.end(); iter++) {
		int_lhs += *iter*base;
		base *= 10;
	}

	base = 1;
	for (List<int>::iterator iter = rhs.begin(); iter != rhs.end(); iter++) {
		int_rhs += *iter*base;
		base *= 10;
	}

	int sum = int_lhs + int_rhs;
	List<int> ret;

	while (sum) {
		int tmp = sum % 10;
		ret.push_back(tmp);
		sum /= 10;
	}

	return ret;
}

int main() {
	printf("numbers:");
	std::string str;
	std::getline(std::cin, str);

	
	List<int> lhs, rhs;

	std::stringstream ss;
	ss.str(str);
	std::string sub_str;
	while (ss >> sub_str) {
		lhs.push_back(atoi(sub_str.c_str()));
	}

	printf("numbers:");
	std::getline(std::cin, str);
	ss.clear();
	ss.str(str);
	while (ss >> sub_str) {
		rhs.push_back(atoi(sub_str.c_str()));
	}

	// replace with other methods
	List<int> ret = add_two_num_simple (lhs, rhs);
	for (auto iter = ret.begin(); iter != ret.end(); ++iter) {
		printf("%d ", *iter);
	}

	ret.clear();
	system("pause");
}