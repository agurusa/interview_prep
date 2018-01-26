#include <string>
#include <iostream>
#include <map>

//returns the input string as a set of characters with the amount of time that 
//character exists within a group. For example, aabcccaa will return a2b1c3a2
std::string compress(std::string input){
	std::string return_string;
	char previous_c = tolower(input[0]);
	int count = 1;
	for(int i = 1; i < input.size(); i++){
		char c = tolower(input[i]);
		if(c == previous_c){
			count++;
		}
		else{
			return_string+= previous_c + std::to_string(count);
			count = 1;
		}
		previous_c = c;
	}
	return_string += previous_c + std::to_string(count);
	return return_string;
}