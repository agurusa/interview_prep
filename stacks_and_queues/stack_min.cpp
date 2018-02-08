const StackNode *min_node(const Stack stack){
	StackNode *min;
	StackNode *sn;
	if(stack.top != NULL){
		min = stack.top;
		sn = stack.top;
	}
	while(sn!= NULL){
		if(*sn < *min){
			min = sn;
		}
		sn = sn->next;
	}
	return min;
}