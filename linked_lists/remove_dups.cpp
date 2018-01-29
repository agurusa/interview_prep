#include <map>


// remove duplicates from unordered linked list.
LinkedList remove_dups(LinkedList input){
	std::map<int, int> node_map = {};
	node_map[input.head->data] = 1;
	Node *n = input.head;
	while(n != NULL){
		Node *nn = n->next;
		if(nn == NULL){
			break;
		}
		else{		
			if(!node_map[nn->data]){
				node_map[nn->data] = 1;
			}
			else{
				n->next = nn->next;
			}
			n = n->next;
		}
	}
	return input;
}