#include <iostream>
#include <vector>
#include <map>

class Node{
public:
	Node(int d){data=d;}
	std::vector<Node*> children = {};
	int data;
	friend bool operator == (const Node lhs, const Node rhs){
		return(lhs.data == rhs.data);
	}
};

class Graph{
public:
	Graph(){}
	std::vector<Node*> nodes= {};
};

bool route_between_nodes(Graph *graph, Node *start, Node *end){

	// BREADTH FIRST SEARCH
	// USE A QUEUE
	if(start == end ){
		return true;
	}
	std::vector<Node*> nodes = {};
	std::vector<Node*> important_nodes = {};
	// start with the first node in the graph
	nodes.push_back(graph->nodes[0]);
	while(!nodes.empty()){
		//check the first node in the queue
		Node *first = nodes[0];
		// if first is the starting node, we need to check its children, then those children, then the other children to see if the ending node is there.
		if(first == start){
			// nodes.clear();
			for(int j = 0; j< first->children.size(); j++){
				important_nodes.push_back(first->children[j]);
			}
			while(!important_nodes.empty()){
				Node *f = important_nodes[0];
				if(f == end){
					return true;
				}
				else{				
					for(int x = 0; x < f->children.size(); x++){
						important_nodes.push_back(f->children[x]);
					}
					important_nodes.erase(important_nodes.begin());
				}
			}
			return false;
		}
		else{
			// put its children in the queue
			// if first is not the starting node, we still need to find the starting node.
			for(int i = 0; i < first->children.size(); i++){
				nodes.push_back(first->children[i]);
			}
			//dequeue the first node in the queue
			nodes.erase(nodes.begin());
		}
	}

	return false;
}