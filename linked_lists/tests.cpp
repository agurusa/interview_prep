#include "../catch.hpp"

#include "linked_list.cpp"
#include "remove_dups.cpp"
#include "return_kth_to_last.cpp"

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
			REQUIRE(kth_element(input, 4) ==  Node(1));
		}
	}
	LinkedList input = std::vector<int>{1, 2, 3, 1, 4, 6, 5, 3, 7};
	WHEN("The linked list has more than k nodes, with repeated nodes"){
		THEN("Return the kth from last element"){
			REQUIRE(kth_element(input, 1) == Node(3));
		}
	}
	WHEN("k is 0"){
		THEN("The last element is returned"){
			REQUIRE(kth_element(input, 0) == Node(7));
		}
	}
	WHEN("k is the length of the list"){
		THEN("The head is returned"){
			REQUIRE(kth_element(input, 8) == Node(1));
		}
	}
}
