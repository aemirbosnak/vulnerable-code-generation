//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Linus Torvalds style, baby!

// Define a macro to swap two elements of a type
#define SWAP(a, b) do { typeof(a) tmp = (a); (a) = (b); (b) = tmp; } while (0)

// Define a function to reverse a string
static void reverse(char *str, size_t len)
{
	for (size_t i = 0; i < len / 2; i++)
		SWAP(str[i], str[len - i - 1]);
}

// Define a function to check if a string is a palindrome
static bool is_palindrome(const char *str)
{
	size_t len = strlen(str);
	for (size_t i = 0; i < len / 2; i++)
		if (str[i] != str[len - i - 1])
			return false;
	return true;
}

// Define a main function
int main(int argc, char *argv[])
{
	// Get the input string from the user
	char *input = NULL;
	size_t len = 0;
	getline(&input, &len, stdin);

	// Remove trailing newline character
	if (input[len - 1] == '\n')
		input[len - 1] = '\0';

	// Check if the string is a palindrome
	bool palindrome = is_palindrome(input);

	// Print the result
	if (palindrome)
		printf("The string %s is a palindrome.\n", input);
	else
		printf("The string %s is not a palindrome.\n", input);

	// Free the input string
	free(input);

	return 0;
}