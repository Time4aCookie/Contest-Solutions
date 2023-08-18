// Created by Rohan Tatikonda on 7/3/23.
#include "iostream"
#include "vector"
#include "cmath"
#include "unordered_map"
#include "set"
using namespace std;

vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo){
	for(int i = 0; i < moveFrom.size(); ++i){
		for(int j = 0; j < nums.size(); ++j){
			if(nums[j] == moveFrom[i]){
				nums[j] = moveTo[i];
			}
		}
	}
	vector<int> ans;
	for(int i = 0; i < nums.size(); ++i){
		if(find(ans.begin(), ans.end(), nums[i]) == ans.end()){
			ans.push_back(nums[i]);
		}
	}
	return ans;
}

vector<int> optimalRelocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
	//use map to store move from and we'll iterate through nums checking if anything matches
	unordered_map<int, int> moveFromMap;
	for (int i = 0; i < moveFrom.size(); ++i) {
		moveFromMap.insert(make_pair(moveFrom[i], i));
	}

	set<int> numSet;
	for (int i = 0; i < nums.size(); ++i) {
		numSet.insert(nums[i]);
	}
	set<int>::iterator itr = numSet.begin();
	while(itr != numSet.end()) {
		if (moveFromMap.find(*itr) != moveFromMap.end()) {
			auto currItr = itr;
			itr++;
			int index = moveFromMap.find(*currItr)->second;
			numSet.erase(currItr);
			numSet.insert(moveTo[index]);
			}
		else{
			itr++;
		}
		}
	nums.erase(nums.begin(), nums.end());
	copy(numSet.begin(), numSet.end(), back_inserter(nums));
	return nums;
}



ostream& operator<<(ostream& os, vector<int>& input){
	os << "[";
	for(int i = 0; i < input.size(); ++i){
		os << input[i] << ", ";
	}
	os << "]";
	return os;
}

//int main(int argc, char* argv[]){
//	vector<int> nums = {1,2,3,4,5};
//	vector<int> moveFrom = {1,3,5};
//	vector<int> moveTo = {10,10,10};
//	vector<int> ans = optimalRelocateMarbles(nums,moveFrom, moveTo);
//	cout << ans << endl;
//	return 0;
//}