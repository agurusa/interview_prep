#include "../catch.hpp"

#include "route_between_nodes.cpp"

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