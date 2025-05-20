//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the hash of a string using a recursive approach
unsigned long long hash_recursive(char *str, int len) {
    // Base case: If the string is empty, return 0
    if (len == 0) {
        return 0;
    }

    // Recursive case: Calculate the hash of the remaining string and combine it with the hash of the first character
    return (hash_recursive(str + 1, len - 1) * 31) + str[0];
}

// Function to calculate the hash of a string using a non-recursive approach
unsigned long long hash_non_recursive(char *str, int len) {
    unsigned long long hash = 0;

    for (int i = 0; i < len; i++) {
        hash = (hash * 31) + str[i];
    }

    return hash;
}

// Function to generate a random string of a given length
char *generate_random_string(int len) {
    char *str = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        str[i] = 'a' + rand() % 26;
    }

    str[len] = '\0';

    return str;
}

// Function to test the hash functions
void test_hash_functions(int num_tests) {
    for (int i = 0; i < num_tests; i++) {
        // Generate a random string of length 10
        char *str = generate_random_string(10);

        // Calculate the hash of the string using the recursive and non-recursive functions
        unsigned long long hash_recursive_result = hash_recursive(str, strlen(str));
        unsigned long long hash_non_recursive_result = hash_non_recursive(str, strlen(str));

        // Compare the results of the two functions
        if (hash_recursive_result != hash_non_recursive_result) {
            printf("Error: The hash functions produced different results for the string \"%s\".\n", str);
            printf("Recursive hash: %llu\n", hash_recursive_result);
            printf("Non-recursive hash: %llu\n", hash_non_recursive_result);
            return;
        }
    }

    printf("Success: The hash functions produced the same results for all %d tests.\n", num_tests);
}

int main(int argc, char **argv) {
    // Parse the command-line arguments
    if (argc != 2) {
        printf("Usage: %s <num_tests>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num_tests = atoi(argv[1]);

    // Test the hash functions
    test_hash_functions(num_tests);

    return EXIT_SUCCESS;
}