/*
 * moveZeros.cpp
 *
 *  Created on: 2015年10月17日
 *      Author: Veyron
 */

/**
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.
**/

#include <iostream>
#include <vector>
#include <utility>
#include <sstream>

class Solution {
public:
	Solution(std::vector<int> num){
		v = num;
	}
	void moveZeros() {
		unsigned int cur = 0 , last = 0;
		while (cur < v.size()) {
			if (0 != v[cur]) {
				std::swap(v[cur], v[last]);
				++last;
			}
			++cur;
		}
	}
	void print() {
		std::ostringstream o;
		o<<"The array is:"<<std::endl;
		for (std::vector<int>::iterator it = v.begin(); it != v.end();
			++it) {
			o<<*it<<" ";
		}
		std::cout<<o.str()<<std::endl;
	}
private:
	std::vector<int> v;
};



int main( int argc, char *argv[])
{
	int test[] = {3,1,0,5,0,0,6,1,4,30,9};
	std::vector<int> vtest (test, test+sizeof(test) / sizeof(int));
	Solution a (vtest);
	a.print();
	a.moveZeros();
	a.print();
	return 0;
}



