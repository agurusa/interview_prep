#include <iostream>
#include <vector>

class StackNode{
public:
	StackNode(int d){
		data = d;
	}
	int data;
	StackNode *next = NULL;
	// included for comparisons in tests.cpp
	friend bool operator == (const StackNode lhs, const StackNode rhs){
		return(lhs.data == rhs.data);
	}
	friend std::ostream& operator <<(std::ostream& os, const StackNode *sn){
		os << sn->data;
		return os;
	}
	friend std::ostream& operator <<(std::ostream& os, const StackNode& sn){
		os << sn.data;
		return os;
	}
	friend bool operator <(const StackNode lhs, const StackNode rhs){
		return(lhs.data < rhs.data);
	}
};

class Stack{
public:
	Stack(){

	}
	void pop(){
		if(top!=NULL){
			top = top->next;
		}
	};
	void push(StackNode *sn){
		StackNode *s = top;
		top = sn;
		if(s!= NULL){
			top->next = s;
		}
	};
	StackNode *peek(){return top;};
	bool isEmpty(){
		return true;
	}
	StackNode *top = NULL;
	//included for comparisons in tests.cpp
	friend bool operator == (const Stack lhs, const Stack rhs){
		StackNode *topLHS = lhs.top;
		StackNode *topRHS = rhs.top;
		while(topLHS != NULL && topRHS != NULL){
			if(topLHS != topRHS){
				return false;
			}
			else{
				topLHS = topLHS->next;
				topRHS = topRHS->next;
			}
		}
		if((topLHS == NULL && topRHS != NULL) || (topLHS!= NULL && topRHS == NULL)){
			return false;
		}
		return true;
	}
	friend std::ostream& operator << (std::ostream& os, Stack const& stack){
		StackNode *sn = stack.top;
		while(sn!= NULL){
			os << sn->data << " ";
			sn = sn->next;
		}
		return os;
	}
};