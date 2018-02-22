#include "../catch.hpp"

#include "route_between_nodes.cpp"
#include "minimal_tree.cpp"

SCENARIO("Given a directed graph with two or more nodes, given two nodes"){
	// Graph test_graph();
	Graph *test_graph = new Graph();
	Node *node_0 = new Node(0);
	Node *node_1 = new Node(1);
	Node *node_2 = new Node(2);
	Node *node_3 = new Node(3);
	node_0->children.push_back(node_1);
	node_0->children.push_back(node_2);
	node_2->children.push_back(node_3);
	node_3->children.push_back(node_1);
	test_graph->nodes.push_back(node_0);
	test_graph->nodes.push_back(node_1);
	test_graph->nodes.push_back(node_2);
	test_graph->nodes.push_back(node_3);
	WHEN("There is no route between them"){
		THEN("Return false"){
			REQUIRE(route_between_nodes(test_graph, node_1, node_2) == false);
			REQUIRE(route_between_nodes(test_graph, node_1, node_0) == false);
			REQUIRE(route_between_nodes(test_graph, node_3, node_0) == false);
		}
	}
	WHEN("There is a route between them"){
		THEN("Return true"){
			REQUIRE(route_between_nodes(test_graph, node_0, node_1) == true);
			REQUIRE(route_between_nodes(test_graph, node_0, node_2) == true);
			REQUIRE(route_between_nodes(test_graph, node_2, node_1) == true);
			REQUIRE(route_between_nodes(test_graph, node_0, node_3) == true);
		}
	}
}

SCENARIO("Given a sorted (increasing order) array with unique integer elements"){
	WHEN("Each item is added into a tree"){
		THEN("The items are added to a binary search tree with minimal height"){
			std::vector<int> test_vector = {1, 2, 3, 4, 5, 6 , 7};
			Tree *test_tree = new Tree();
			for(int i = 0; i < test_vector.size(); i++){
				TreeNode *tn = new TreeNode(test_vector[i]);
				test_tree->Insert(tn);
			}
			TreeNode *t = new TreeNode(1);
			// REQUIRE(*minimal_tree(test_vector, 0, test_vector.size() - 1, test_tree) == *test_tree);
			REQUIRE(*minimal_binary_search_tree(test_vector, 0, test_vector.size() - 1, test_tree) == *t);
		}
	}
}