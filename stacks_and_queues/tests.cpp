#include "../catch.hpp"

#include "stack.cpp"
#include "stack_min.cpp"

SCENARIO("Given a stack"){
	Stack s;
	s.push(new StackNode(4));
	s.push(new StackNode(8));
	StackNode *min = new StackNode(3);
	s.push(min);
	s.push(new StackNode(5));
	s.push(new StackNode(8));
	WHEN("The stack has already been built"){
		THEN("The minimum item in the stack is returned in O(1) time"){
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