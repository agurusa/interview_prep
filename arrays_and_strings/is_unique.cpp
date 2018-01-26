#include <iostream>
#include <string>
#include <map>

//Determines if a string has all unique characters.
bool is_unique(std::string input){

	std::map<char, int> character_dict = {};
	for(int i = 0; i < input.size(); i++){
		char c = input[i];
		if(character_dict[c]){
			return false;
		}
		else{
			character_dict[c] = 1;
		}
	}
	return true;
}