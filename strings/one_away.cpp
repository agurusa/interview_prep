#include <string>
#include <iostream>
#include <map>
#include <algorithm>


// Dyanamic and memoized determination of the minimum edits needed to get strings input1 and input2 to be the same.

std::vector<std::vector<int>> create_map(std::string input1, std::string input2){
	std::vector<std::vector<int>> edit_map(input1.size());
	for(int i = input1.size() - 1; i >=0 ; i--){
		edit_map[i] = std::vector<int>(input2.size());
		for(int j = input2.size() - 1; j >= 0; j--){
			if(j == input2.size() - 1 && i == input1.size() -1){
				if(input1[i] == input2[j]){
					edit_map[i][j] = 0;
				}
				else{
					edit_map[i][j] = 1;
				}
			}
			else if(j == input2.size() -1){
				if(input1[i] != input2[j]){
					edit_map[i][j] = edit_map[i + 1][j] + 1;
				}
				else{
					edit_map[i][j] = edit_map[i + 1][j];
				}
			}
			else if(i == input1.size() -1){
				if(input1[i] != input2[j]){
					edit_map[i][j] =  edit_map[i][j+1] + 1;
				}
				else{
					edit_map[i][j] = edit_map[i][j+1];
				}
			}
			else{
				int choice;
				int replace = edit_map[i+1][j+1];
				int remove = edit_map[i+1][j];
				int add = edit_map[i][j+1];
				choice = std::min(std::min(replace, remove), add);
				if(input1[i] != input2 [j]){
					edit_map[i][j] = choice + 1;
				}
				else{
					edit_map[i][j] = choice;
				}
			}
		}
	}
	return edit_map;
}

bool one_away(std::string input1, std::string input2){
	int min_edits = create_map(input1, input2)[0][0];
	if(min_edits <= 1){
		return true;
	}
	return false;
}

void print_map(std::vector<std::vector<int>> a_map){
	for(int a = 0; a < a_map.size(); a++){
		for(int b = 0; b < a_map[a].size(); b++){
			std::cout << a_map[a][b] << " ";
		}
		std::cout << "\n";
	}
}
