#include <iostream>
#include <vector>
// build the linked list
class Node{
	public:
	Node *next = NULL;
	int data;

	Node(int d){
		data = d;
	}
	//included for comparisons in tests.cpp
	friend bool operator == (const Node lhs, const Node rhs){
		return(lhs.data == rhs.data);
	}

	friend std::ostream& operator <<( std::ostream& os, const Node& node){
		os << node.data;
		return os;
	}
};

class LinkedList {
public:
	Node *head = NULL;

	LinkedList(std::vector<int> d = {}){
		for(int i = 0; i < d.size(); i++){
			appendToTail(d[i]);
		}
	}

	void appendToTail(int d){
		Node *end = new Node(d);
		Node *n = head;
		if(head == NULL){
			head = end;
		}
		else{		
			while(n->next != NULL){
				n = n->next;
			}
			n->next = end;
		}
	}
	void deleteNode(Node *node){
		Node *n = head;
		if(n->data == node->data){
			this->head = n->next;
			return;
		}
		else{
			while(n!=NULL){
				Node *nn = n->next;
				if(nn->data == node->data){
					n->next = n->next->next;
					return;
				}
				n = nn;
			}
			return;
		}
	}

	//included for comparisons in tests.cpp
	friend bool operator == (const LinkedList lhs, const LinkedList rhs){
		Node *nl = lhs.head;
		Node *nr = rhs.head;
		if(nl->data != nr->data){
			return false;
		}
		while(nl != NULL && nr!= NULL){
			Node *nln = nl->next;
			Node *nrn = nr->next;
			if(nln == NULL || nrn == NULL){
				if(nln == NULL && nrn == NULL){
					return true;
				}
				else{
					return false;
				}
			}
			else if(nln->data != nrn->data){
				return false;
			}
			else{
				nl = nl->next;
				nr = nr->next;
			}
		}
		return true;
	}

	friend std::ostream& operator <<( std::ostream& os, LinkedList const& list){
		Node *n = list.head;
		while(n!= NULL){
			os << n->data << " ";
			n = n->next;
		}
		return os;
	}
};