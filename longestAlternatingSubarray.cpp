#include <iostream>
#include "vector"
using namespace std;

struct Solution{
	int longestAlternatingSubarray(vector<int>& nums, int threshold){
		int count = 0;
		int maxCount = 0;
		bool inIt = false;
		for(int i = 0; i < nums.size(); ++i){
			if(inIt == false){
				if(nums[i] % 2 == 0 && nums[i] <= threshold){
					inIt = true;
					count = 1;
				}
				continue;
			}
			if(inIt == true){
				if(nums[i] <= threshold && nums[i] % 2 != nums[i-1] % 2){
					count++;
				}
				else{
					if(count > maxCount){
						maxCount = count;
						count = 0;
					}
					inIt = false;
					i--;
				}
			}
		}
		if(count > maxCount){
			maxCount = count;
		}
		return maxCount;
	}
};

int optimalLongestAlternatingSubarray(vector<int>& nums, int threshold){
	int ans = 0;
	for(int i = 0; i < nums.size()-1;++i){
		if(nums[i] % 2 == 0 && nums[i] <= threshold){
			ans = max(ans, 1);
			for(int j = i; j < nums.size()-1; ++j){
				if(nums[j] <= threshold && nums[j+1] <= threshold && nums[j] % 2 != nums[j+1] % 2){
					ans = max(ans, j-i+2);
				}
				else{
					i =j;
					break;
				}
			}
		}
	}
	if(ans == 0 && nums[nums.size()-1] <= threshold && nums[nums.size()-1] % 2 == 0){
		ans+=1;
	}
	return ans;
}

//int main() {
//
//	vector<int> hi = {4,10,3};
//	int threshold = 10;
//	int k = optimalLongestAlternatingSubarray(hi,threshold);
//	cout << k << endl;
//	return 0;
//}
