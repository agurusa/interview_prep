#include "../catch.hpp"

#include "is_unique.cpp"

SCENARIO("Strings can be tested for uniqueness", "[test_file]"){
	WHEN("The input is a unique string"){
		THEN("is_unique returns true"){
			REQUIRE(is_unique("abcd") == true);
		}
	}
	WHEN("The input is not a unique string"){
		THEN("is_unique returns false"){
			REQUIRE(is_unique("aabcd") == false);
		}
	}
	WHEN("The input is one letter long"){
		THEN("The string is unique"){
			REQUIRE(is_unique("a") == true);
		}
	}
}