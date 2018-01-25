#include "../catch.hpp"

#include "is_unique.cpp"
#include "check_permutation.cpp"
#include "urlify.cpp"

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

SCENARIO("Two strings are tested to see if they are permutations", "[test_file]"){
	WHEN("The strings are permutations"){
		THEN("is_permutation returns true"){
			REQUIRE(is_permutation("cat", "tca") == true);
		}
	}
	WHEN("The strings are not permutations"){
		THEN("is_permutation returns false"){
			REQUIRE(is_permutation("cat", "dog") == false);
		}
	}
	WHEN("The strings are permutations with repeated letters"){
		THEN("is_permutation returns true"){
			REQUIRE(is_permutation("cca", "cac") == true);
		}
	}
}

SCENARIO("A string with spaces is returned with %20 in place of the spaces", "[test_file]"){
	WHEN("The string has no spaces"){
		THEN("The string is returned as is"){
			std::string input = "thishasnospaces";
			REQUIRE(urlify(input, 15) == input);			
		}
	}
	WHEN("The string has spaces"){
		THEN("The string is returned with %20 in its place"){
			std::string input = "Mr John Smith    ";
			REQUIRE(urlify(input, 13) == "Mr%20John%20Smith");
		}
	}
}