#include <iostream>
#include <string>
#include <map>


// check if input2 is a rotation of input1
bool isSubstring(std::string input1, std::string input2){
	std::string prefix="";
	std::string comparison_prefix="";
	if(input1.size() != input2.size()){
		return false;
	}
	else{
		char first_char = input2.front();
		char last_char = input1[input1.size() - 1];
		for(int i = 0; i < input1.size(); i++){
			if(input1[i] != first_char){
				prefix += input1[i];
			}
			else{
				break;
			}
		}
		// this actually won't work if the last character of input1 is the same as one of the characters in the 
		// rotated section.
		// TODO: fix this edge case.
		for(int j = input2.size()-1; j >=0; j--){
			std::cout << prefix << " ";
			if(input2[j] != last_char){
				if(prefix.size() < 1){
					return false;
				}
				else if(input2[j] == prefix[prefix.size() -1]){
					prefix.erase(prefix.size() - 1);
				}
				else{
					return false;
				}
			}
			else{
				break;
			}
		}
		if(prefix.size() != 0){
			return false;
		}
	return true;
	}
}