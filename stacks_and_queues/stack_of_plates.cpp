#include <vector>
#include <map>

class SetOfStacks{
public:
	std::vector<Stack> set_of_stacks = {};
	Stack* get_last_stack(){
		if(set_of_stacks.size() <= 0){
			// this means that there will always be at least one stack ready to go in the set of stacks.
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

	void pop(){
		Stack* last_stack;
		last_stack = get_last_stack();
		if(last_stack->isEmpty()){
			set_of_stacks.erase(set_of_stacks.end()-1);
			// last_stack->delete();
			last_stack = get_last_stack();
		}
		last_stack->pop();
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