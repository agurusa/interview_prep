#include "../catch.hpp"

#include "linked_list.cpp"
#include "remove_dups.cpp"
#include "return_kth_to_last.cpp"
#include "delete_middle_node.cpp"

SCENARIO("An unsorted linked list is checked for duplicates"){
	WHEN("The linked list has duplicates"){
		THEN("The duplicates are removed, and the edited linked list is returned"){
			LinkedList input = std::vector<int>{1, 2, 3, 1, 4, 6, 5, 3, 7};
			REQUIRE(remove_dups(input) == LinkedList (std::vector<int>{1, 2, 3, 4, 6, 5, 7}));
		}
	}
	WHEN("The linked list has no duplicates"){
		THEN("The original linked list is returned"){
			LinkedList input = std::vector<int>{1, 2, 3, 4, 6, 5};
			REQUIRE(remove_dups(input) == input);
		}
	}
}

SCENARIO("Given a singly linked list, return the kth to last element"){
	WHEN("The linked list has less elements than k"){
		THEN("Return the head"){
			LinkedList input = std::vector<int>{1};
			// REQUIRE(kth_element(input, 4) ==  Node(1));
			REQUIRE(kth_element(input, 4) == input.node_at_i(0));
		}
	}
	std::vector<int> input_v = {1, 2, 3, 1, 4, 6, 5, 3, 7};
	LinkedList input(input_v);
	WHEN("The linked list has more than k nodes, with repeated nodes"){
		THEN("Return the kth from last element"){
			REQUIRE(kth_element(input, 1) == input.node_at_i((input_v.size() - 1) - 1));
		}
	}
	WHEN("k is 0"){
		THEN("The last element is returned"){
			REQUIRE(kth_element(input, 0) == input.node_at_i((input_v.size() - 1) - 0));
		}
	}
	WHEN("k is the length of the list"){
		THEN("The head is returned"){
			REQUIRE(kth_element(input, 8) == input.node_at_i((input_v.size() - 1) - 8));
		}
	}
}

SCENARIO("Given a singly linked list and a node in that list"){
	WHEN("The node exists in the linked list"){
		THEN("Return the linked list without that node"){
			LinkedList input = std::vector<int>{1, 2, 3, 1, 4, 6, 5, 3, 7};
			REQUIRE(remove_node(input, input.node_at_i(3)) == LinkedList(std::vector<int>{1,2,3,4,6,5,3,7}));
		}
	}
	WHEN("The node is the head of the linked list"){
		THEN("Remove the head node and update the linked list"){
			LinkedList input = std::vector<int>{1, 2, 3, 1, 4, 6, 5, 3, 7};
			REQUIRE(remove_node(input, input.node_at_i(0)) == LinkedList(std::vector<int>{2,3,1,4,6,5,3,7}));
		}
	}
	WHEN("The node is the last node of the linked list"){
		THEN("Remove the last node and update the tail"){
			LinkedList input = std::vector<int>{1, 2, 3, 1, 4, 6, 5, 3, 7};
			REQUIRE(remove_node(input, input.node_at_i(8)) == LinkedList(std::vector<int>{1,2,3,1,4,6,5,3}));
		}
	}
}
