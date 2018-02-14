#include "../catch.hpp"

#include "stack.cpp"
#include "stack_min.cpp"
#include "stack_of_plates.cpp"

SCENARIO("Given a stack"){
	Stack s;
	s.push(new StackNode(4));
	s.push(new StackNode(8)); 
	StackNode *min = new StackNode(3);
 	s.push(min);
	s.push(new StackNode(5));
	s.push(new StackNode(8));
	WHEN("The stack has already been built"){
		THEN("The minimum item in the stack is returned"){
			REQUIRE(*min_node(s) == *min);
		}
	}
	WHEN("The minimum in the stack is the top item"){
		THEN("The minimum item in the stack is returned"){
			min = new StackNode(1);
			s.push(min);
			REQUIRE(*min_node(s) == *min);
		}
	}
	WHEN("The minimum in the stack is the bottom item"){
		THEN("The minimum item in the stack is returned"){
			StackNode*sn = s.top;
			while(sn!= NULL){
				s.pop();
				sn = s.top;
			}
			min = new StackNode(1);
			s.push(min);
			REQUIRE(*min_node(s) == *min);
		}
	}
}

SCENARIO("Given a set of plates that are represented as StackNodes, store all the plates in stacks."){
	SetOfStacks set;
	for(int i = 0; i < 30; i++){
		set.push(new StackNode(i));
	}
	WHEN("A stack is at capacity"){
		THEN("Create a new stack to hold the new plate"){
			REQUIRE(set.size() == 3);
		}
	}
	WHEN("StackNodes are popped off of the set of stacks"){
		THEN("Each node is popped off from the last stack in the set"){
			for(int i = 0; i < 10; i++){
				set.pop();
			}
			REQUIRE(set.size() == 2);
		}
	}
	WHEN("A stack has nothing in it"){
		THEN("It is deleted from the set"){
			int initial_size = set.size();
			for(int i = 0; i < (initial_size * 10); i++){
				set.pop();
			}
			REQUIRE(set.size() == 1);
		}
	}
}