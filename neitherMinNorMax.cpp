// Created by Rohan Tatikonda on 7/29/23.
#include "iostream"
#include "vector"

using namespace std;

int findNonMinOrMax(vector<int>& nums){
	sort(nums.begin(), nums.end());
	int a = nums[0];
	int b= nums[nums.size()-1];
	for(int i = 1; i < nums.size()-1; ++i){
		if(nums[i] > a && nums[i] < b){
			return nums[i];
		}
	}
	return -1;
}

int optimalFindNonMinOrMax(vector<int>& nums){
	if(nums.size() < 3){
		return -1;
	}
	int min = 101, max = 0;

	for(int i = 0; i < nums.size(); ++i){
		if(nums[i] < min && nums[i] != max){
			min = nums[i];
		}
		if(nums[i] > max && nums[i] != min){
			max = nums[i];
		}
		if(i > 1 && nums[i] > min && nums[i] < max){
			return nums[i];
		}
	}
	return -1;
}

//int main(int argc, char* argv[]){
//	vector<int> input = {3,2,1,4};
//	int k = optimalFindNonMinOrMax(input);
//	cout << k << endl;
//}