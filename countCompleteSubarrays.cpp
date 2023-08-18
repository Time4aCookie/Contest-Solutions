// Created by Rohan Tatikonda on 7/29/23.
#include "iostream"
#include "vector"
#include "unordered_set"

using namespace std;

int countCompleteSubarrays(vector<int>& nums) {
	unordered_set<int> diffNumbers;
	int ans = 0;
	for(int i = 0; i < nums.size(); ++i){
		diffNumbers.insert(nums[i]);
	}
	for(int i = 0; i < nums.size(); ++i){
		unordered_set<int> subStrings;
		for(int j = i; j < nums.size(); ++j){
			subStrings.insert(nums[j]);
			if(subStrings == diffNumbers){
				ans++;
			}
		}
	}
	return ans;
}

int main(int argc, char* argv[]){
	vector<int> input = {5,5,5,5};
	int k = countCompleteSubarrays(input);
	cout << k << endl;
}