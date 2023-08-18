// Created by Rohan Tatikonda on 7/29/23.
#include "iostream"
#include "vector"

using namespace std;

int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
	int ans = 0;
	for(int i = 0; i < hours.size(); ++i){
		if(hours[i] >= target){
			ans++;
		}
	}
	return ans;
}

//int main(int argc, char* argv[]){
//
//}
