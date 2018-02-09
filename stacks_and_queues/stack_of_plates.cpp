#include <vector>
#include <map>

class SetOfStacks{
public:
	std::vector<Stack> set_of_stacks = {};
	Stack* get_last_stack(){
		if(set_of_stacks.size() <= 0){
			set_of_stacks.push_back(* new Stack());  
		}
		return &set_of_stacks.back();
	}
	void push(StackNode * sn){
		Stack* last_stack;
		last_stack = get_last_stack();
		if(last_stack->at_capacity()){
			last_stack = new Stack();
			set_of_stacks.push_back(*last_stack);
		}
		last_stack->push(sn);
		last_stack->capacity --;
	}
	int size(){
		return set_of_stacks.size();
	}

	// included for comparisons in tests.cpp
	friend bool operator ==(const SetOfStacks lhs, const SetOfStacks rhs){
		return(lhs.set_of_stacks == rhs.set_of_stacks);
	}
	friend std::ostream& operator << (std::ostream& os, const SetOfStacks& set){
		for(int i = 0; i < set.set_of_stacks.size(); i++){
			os << set.set_of_stacks[i].capacity << " ";		
		}
		return os;
	}

};