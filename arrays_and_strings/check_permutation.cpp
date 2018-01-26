#include <iostream>
#include <string>
#include <map>

// Given two strings, determines if one is a permutation of the other.
bool is_permutation(std::string input1, std::string input2){
	int size_of_1 = input1.size();
	int size_of_2 = input2.size();
	if(size_of_1!= size_of_2){
		return false;
	}
	else{
		std::map<char, int> character_dict= {};
		for(int i = 0; i < size_of_1; i++){
			char c = input1[i];
			if(character_dict[c]){
				character_dict[c]++;
			}
			else{
				character_dict[c] = 1;
			}
		}
		for(int j = 0; j < size_of_2; j++){
			char c = input2[j];
			if(!character_dict[c]){
				return false;
			}
			else{
				character_dict[c] --;
				if(character_dict[c] == 0){
					character_dict.erase(c);
				}
			}
		}
		if(!character_dict.empty()){
			return false;
		}
	}
	return true;
}