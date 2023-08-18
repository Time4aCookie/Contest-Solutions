// Created by Rohan Tatikonda on 7/3/23.
#include "iostream"
#include "vector"
#include "cmath"
using namespace std;

int alternatingSubarray(vector<int>& nums){
	if(nums.size() <= 1){
		return 0;
	}
	bool nextLarger = true;
	int count = 0;
	int maxCount = 0;
	for(int i = 1; i < nums.size(); ++i){
		if(nextLarger && nums[i] == nums[i-1]+1){
			count++;
			nextLarger = false;
			continue;
		}
		if(!nextLarger && nums[i] == nums[i-1]-1){
			count++;
			nextLarger = true;
			continue;
		}
		else{
			nextLarger = true;
			if(count > 0){
				count++;
				i--;
			}
			if(count > maxCount){
				maxCount = count;
				count = 0;
			}
			count = 0;
		}
	}
	if(count != 0 && count+1 > maxCount){
		maxCount = count+1;
	}
	if(maxCount == 0){
		return -1;
	}
	return maxCount;
}

int optimalAlternatingSubarray(vector<int>& nums){
	int ans = 0;
	for(int i = 0; i < nums.size()-1; ++i){
		if(nums[i] + 1 == nums[i+1]){
			for(int j = i; j < nums.size()-1; ++j){
				if(nums[j] - nums[j+1] == pow(-1,j-i+1)){
					ans = max(ans,j-i+2);
				}
				else{
					i = j-1;
					break;
				}
			}
		}
	}
	if(ans == 0){
		return -1;
	}
	return ans;
}

//int main(int argc, char* argv[]){
//	vector<int> test = {2,3,4,3,4};
//	int k = optimalAlternatingSubarray(test);
//	cout << k << endl;
//}