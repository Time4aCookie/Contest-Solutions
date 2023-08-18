// Created by Rohan Tatikonda on 7/3/23.
#include "iostream"
#include "vector"
#include "cmath"
using namespace std;

bool isPrime(int n){
	if(n == 2 || n == 3 || n == 5 ){
		return true;
	}
	if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0){
		return false;
	}
	for(int j = 6; j <= sqrt(n)+1; j+=6){
		if (n % (j+1) == 0 || n % (j-1) == 0){
			return false;
		}
	}
	return true;
}

vector<vector<int>> findPrimePairs(int n){
	vector<vector<int>> ans;
	for(int i = 2; i <= n/2; ++i){
		if(isPrime(i) && isPrime(n-i)){
			ans.push_back({i,n-i});
		}
	}
	return ans;
}

ostream& operator<<(ostream& os,const vector<vector<int>>& input){
	os << "{";
	for(int i = 0; i < input.size(); ++i){
		os << "[";
		for(int j = 0; j < input[i].size(); ++j){
			if(j == input[i].size()-1){
				os << input[i][j];
			}
			else {
				os << input[i][j] << " ";
			}
		}
		if(i == input.size()-1){
			os << "]";
			cout << "}";
			return os;
		}
		os << "], ";
	}
	os << "}";
	return os;
}

//int main(int argc, char* argv[]){
//	cout << findPrimePairs(27)<< endl;
//}