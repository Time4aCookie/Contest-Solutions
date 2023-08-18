// Created by Rohan Tatikonda on 7/16/23.
#include "iostream"
#include "vector"
#include "string"
#include "cmath"
#pragma once
using namespace std;

int minimumBeautifulSubstrings(string s){
	int substrings = 0;
	int lengthCounter = 0;
	bool inIt = false;
	for(int i = 0; i < s.size(); ++i){
		if(inIt == false){
			if(s.substr(i,1) != "0"){
				inIt = true;
				continue;
			}
		}
		if(inIt == true){

		}
	}
}
bool binaryRep5(string n){
	int sum = 0;
	for(int i = 0; i < n.size(); ++i){
		if(n.substr(i,1) == "1"){
			sum += pow(2, n.size()-1-i);
		}
	}
	float log = log2(sum)/log2(5);
	return( ceil(log) == floor(log));
}


//int main(int argc, char* argv[]){
//
//}