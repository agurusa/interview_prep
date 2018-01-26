#include <iostream>
#include <string>
#include <map>

// check if the string is a permutation of a palindrome (a word that is the same backwards as it is forwards)
bool is_palindrome(std::string input){
	std::map<char, int> character_dict = {};
	for(int i = 0; i < input.size(); i++){
		char c = tolower(input[i]);
		if(c == ' '){
			input.erase(input.begin() + i);
			i--;
		}
		else if(character_dict[c]){
			character_dict[c] --;
			if(character_dict[c] == 0){
				character_dict.erase(c);
			}
		}
		else{
			character_dict[c] = 1;
		}
	}
	if(input.size()%2 == 0){
		// the size of the input string is even, and the dictionary should be empty.
		return character_dict.empty();
	}
	else{
		// the size of the input string is odd, and the dictionary should have one entry.
		return (character_dict.size() == 1);
	}
}