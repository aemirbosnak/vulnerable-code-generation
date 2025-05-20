//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

// Function to check if a string is a palindrome
bool is_palindrome(char *str) {
    int i, len = strlen(str);

    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }

    return true;
}

// Function to generate a random string
char *generate_random_string(int length) {
    char *str = malloc(length + 1);
    int i;

    for (i = 0; i < length; i++) {
        str[i] = 'a' + rand() % 26;
    }

    str[length] = '\0';

    return str;
}

// Function to test the palindrome checker
void test_palindrome_checker() {
    int i, num_tests = 100;
    char *str;
    bool is_palindrome_result;

    // Seed the random number generator
    srand(time(NULL));

    // Generate and test 100 random strings
    for (i = 0; i < num_tests; i++) {
        str = generate_random_string(rand() % MAX_STRING_LENGTH + 1);
        is_palindrome_result = is_palindrome(str);

        // Print the results
        printf("String: %s\n", str);
        printf("Is palindrome: %s\n", is_palindrome_result ? "Yes" : "No");
        printf("\n");

        // Free the memory allocated for the string
        free(str);
    }
}

// Main function
int main() {
    // Test the palindrome checker
    test_palindrome_checker();

    return 0;
}