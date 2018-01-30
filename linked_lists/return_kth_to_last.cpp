// returns the kth to last element in a singly linked list

Node *kth_element(const LinkedList list, int k){
	Node *slow_pointer = list.head;
	Node *fast_pointer = list.head;
	for(int i = 0; i < k; i++){
		fast_pointer = fast_pointer->next;
		if(fast_pointer == NULL){
			// return Node(slow_pointer->data);
			return slow_pointer;
		}
	}
	while(fast_pointer!= NULL){
		fast_pointer = fast_pointer->next;
		if(fast_pointer == NULL){
			break;
		}
		slow_pointer = slow_pointer->next;
	}
	// return Node(slow_pointer->data);
	return slow_pointer;
}