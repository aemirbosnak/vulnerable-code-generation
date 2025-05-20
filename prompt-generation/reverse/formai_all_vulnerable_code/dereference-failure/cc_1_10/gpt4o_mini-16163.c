//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to clean the string: remove non-alphanumeric characters and convert to lowercase
char* clean_string(const char* str) {
    int len = strlen(str);
    char* cleaned = malloc(len + 1); // Allocate memory for the cleaned string
    if (!cleaned) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) { // Check if character is alphanumeric
            cleaned[j++] = tolower(str[i]); // Convert to lowercase and store
        }
    }
    cleaned[j] = '\0'; // Null terminate the cleaned string
    return cleaned;
}

// Function to check if the cleaned string is a palindrome
int is_palindrome(const char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

// Function to free allocated memory for the cleaned string
void free_cleaned_string(char* cleaned) {
    free(cleaned);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* input = argv[1];
    char* cleaned = clean_string(input); // Clean the input string

    printf("Original String: %s\n", input);
    printf("Cleaned String: %s\n", cleaned);

    // Check and print if the cleaned string is a palindrome
    if (is_palindrome(cleaned)) {
        printf("Result: '%s' is a palindrome.\n", cleaned);
    } else {
        printf("Result: '%s' is not a palindrome.\n", cleaned);
    }

    free_cleaned_string(cleaned); // Free memory before exiting
    return EXIT_SUCCESS;
}