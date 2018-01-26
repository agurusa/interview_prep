#include "../catch.hpp"

#include "is_unique.cpp"
#include "check_permutation.cpp"
#include "urlify.cpp"
#include "palindrome_permutation.cpp"
#include "one_away.cpp"
#include "string_compression.cpp"
#include "zero_matrix.cpp"
#include "string_rotation.cpp"

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

SCENARIO("A string is checked to see if it is a permutation of a palindrome", "[test_file]"){
	WHEN("The string is a permutation of a palindrome"){
		THEN("is_palindrome() returns true"){
			std::string input = "Tact Coa";
			REQUIRE(is_palindrome(input) == true);
		}
	}
	WHEN("The string is not a permutation of a palindrome"){
		THEN("is_palindrome() returns false"){
			std::string input = "not a palindrome";
			REQUIRE(is_palindrome(input) == false);
		}
	}
	WHEN("The string is an odd number of characters palindrome"){
		THEN("is_palindrome() returns true"){
			std::string input = "tacdatc";
			REQUIRE(is_palindrome(input) == true);
		}
	}
}

SCENARIO("Two strings are checked to see if they are less than one edit away from each other", "[test_file]"){
	WHEN("The strings are more than one size apart"){
		THEN("one_away should return false"){
			std::string input1 = "test";
			std::string input2 = "test11";
			REQUIRE(one_away(input1,input2) == false);
			REQUIRE(one_away("pale", "bake") == false);
		}
	}
	WHEN("The strings are one size apart"){
		THEN("one_away should return true"){
			REQUIRE(one_away("pale","ple") == true);
			REQUIRE(one_away("pales", "pale") == true);
			REQUIRE(one_away("pale", "bale") == true);
		}
	}
}

SCENARIO("The string is compressed if necessary, and is not compressed if there are all unique letters"){
	WHEN("The string has both uppercase and lowercase letters"){
		THEN("compress() still returns the correct response"){
			REQUIRE(compress("AaBbcc") == "a2b2c2");
			REQUIRE(compress("AbCd") == "a1b1c1d1");
		}
	}
	WHEN("The string has duplicate letters"){
		THEN("compress() should return the number of letters next to the letter, and remove the duplicates"){
			REQUIRE(compress("aabccd") == "a2b1c2d1");
			REQUIRE(compress("abcd") == "a1b1c1d1");
		}
	}
	WHEN("The string has duplicate letters, but at different points of the string"){
		THEN("compress() should not combine all the duplicate letters, but instead keep them grouped"){
			REQUIRE(compress("aabcccccaaa") == "a2b1c5a3");
		}
	}
}

SCENARIO("Given an MXN matrix"){
	WHEN("an element in that matrix is 0"){
		THEN("it's entire row and column should be set to 0."){
			std::vector<std::vector<int>> input = {
				{1,1,1,1},
				{1,0,1,1},
				{1,1,1,1}
			};
			std::vector<std::vector<int>> return_vector = {
				{1,0,1,1},
				{0,0,0,0},
				{1,0,1,1}
			};
			REQUIRE(zero_matrix(input) == return_vector);
		}
	}
	WHEN("there are multiple elements in different rows that are 0"){
		THEN("both rows and columns should be set to 0"){
			std::vector<std::vector<int>> input = {
				{1,1,1,0},
				{1,0,1,1},
				{1,1,1,1}
			};
			std::vector<std::vector<int>> return_vector = {
				{0,0,0,0},
				{0,0,0,0},
				{1,0,1,0}
			};
			REQUIRE(zero_matrix(input) == return_vector);
		}
	}
	WHEN("there are multiple elements in the same row that are 0"){
		THEN("both columns and the singular row should be set to 0"){
			std::vector<std::vector<int>> input = {
				{1,1,1,1},
				{1,0,1,0},
				{1,1,1,1}
			};
			std::vector<std::vector<int>> return_vector= {
				{1,0,1,0},
				{0,0,0,0},
				{1,0,1,0}
			};
			REQUIRE(zero_matrix(input) == return_vector);
		}
	}
	WHEN("there are no elements that are 0"){
		THEN("return the original matrix."){
			std::vector<std::vector<int>> input = {
				{1,1,1,1},
				{1,2,1,1},
				{1,1,1,1}
			};
			REQUIRE(zero_matrix(input) == input);
		}
	}
}
SCENARIO("See if one word is a rotation of another"){
	WHEN("there are two strings that are permutations"){
		THEN("return true"){
			REQUIRE(isSubstring("waterbottle", "erbottlewat") == true);
			REQUIRE(isSubstring("waterbottle", "erwatbottle") == false);
			REQUIRE(isSubstring("waterbottle", "notthesame") == false);
		}
	}
}