#include <iostream>
#include <string>
#include <map>

bool is_unique(std::string input){
	// when the input string has more than one character that repeats,
	// the string is not unique.
	// otherwise, the string is unique.
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