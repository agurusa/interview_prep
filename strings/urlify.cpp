#include <iostream>
#include <string>
#include <map>

//For a given string, replace all the empty spaces with %20. Assume that the true value of the final string is given in char_count
std::string urlify(std::string input, int char_count){
	std::string return_string;
	for(int i = 0 ; i < char_count; i++){
		if(input[i] == ' '){
			return_string += "%20";
		}
		else{
			return_string += input[i];
		}
	}
	return return_string;
}