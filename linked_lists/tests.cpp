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
