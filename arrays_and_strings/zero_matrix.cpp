#include <iostream>
#include <vector>
#include <array>
#include <map>

// this is accounting for multiple 0s in the matrix.
std::vector<std::vector<int>> zero_matrix(std::vector<std::vector<int>> input){
	std::vector<std::vector<int>> zeroed_m(input.size());
	std::map<int, int> row_map= {};
	std::map<int, int> column_map = {};
	for(int i = 0; i < input.size(); i++){
		for(int j = 0; j < input[i].size(); j++){
			int comaprison_val = input[i][j];
			if(comaprison_val == 0){
				row_map[j] = 1;
				column_map[i] = 1;
			}
		}
	}

	for(int a = 0; a < input.size(); a++){
		zeroed_m[a] = std::vector<int>(input[a].size());
		for(int b = 0; b < input[a].size(); b++){
			if(row_map[b] || column_map[a]){
				zeroed_m[a][b] = 0;
			}
			else{
				zeroed_m[a][b] = input[a][b];
			}
		}
	}
	return zeroed_m;
}

// this accounts for one zero in the matrix.
std::vector<std::vector<int>> zero_m(std::vector<std::vector<int>> input){
	std::vector<std::vector<int>> return_v(input.size());

	int skip_j = INT_MAX;
	for(int i = 0; i < input.size(); i++){
		return_v[i]= std::vector<int>(input[i].size());
		for(int j = 0; j < input[i].size(); j++){
			if(j!= skip_j){			
				if(input[i][j] == 0){
					skip_j = j;
					for(int b = 0; b <= i; b++){
						return_v[b][j] = 0;
					}
					for(int a = 0; a < input[i].size(); a++){
						return_v[i][a] = 0;
					}
					break;
				}
				else{
					return_v[i][j] = input[i][j];
				}
			}
			else{
				return_v[i][j] = 0;
			}
		}
	}
	return return_v;
}