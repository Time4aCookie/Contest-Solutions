// Created by Rohan Tatikonda on 7/26/23.
#include "iostream"
#include "vector"
#pragma once

using namespace std;

bool isGood(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	if(nums[nums.size()-1] != nums.size()-1){
		return false;
	}
	for(int i = 0; i < nums.size()-1; ++i){
		if(i == nums.size()-2){
			if(nums[i] != i+1 || nums[i+1] != i+1){
				return false;
			}
		}
		if(nums[i] != i+1){
			return false;
		}
	}
	return true;
}
//
//int main(int argc, char* argv[]){
//	vector<int> input = {1,2,3,3};
//	bool k = isGood(input);
//	cout << boolalpha << isGood(input) << endl;
//}