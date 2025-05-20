//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function declarations
void clearInputBuffer();
char *getInputString();
char *sanitizeString(const char *input);
int isPalindrome(const char *str);

int main() {
    printf("Welcome to the Palindrome Checker!\n");
    printf("Enter a string to check if it's a palindrome:\n");

    char *inputString = getInputString();
    if (!inputString) {
        fprintf(stderr, "Error reading input. Exiting...\n");
        return EXIT_FAILURE;
    }

    char *sanitizedString = sanitizeString(inputString);
    if (!sanitizedString) {
        fprintf(stderr, "Error sanitizing input. Exiting...\n");
        free(inputString);
        return EXIT_FAILURE;
    }

    printf("Checking if '%s' is a palindrome...\n", sanitizedString);
    if (isPalindrome(sanitizedString)) {
        printf("The string '%s' is a palindrome!\n", inputString);
    } else {
        printf("The string '%s' is NOT a palindrome!\n", inputString);
    }

    free(inputString);
    free(sanitizedString);
    return EXIT_SUCCESS;
}

// Function to read input string from the user
char *getInputString() {
    size_t size = 256;
    char *str = (char *)malloc(size);

    if (!str) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }

    if (fgets(str, size, stdin) == NULL) {
        free(str);
        return NULL;
    }
    
    // Remove newline character if it exists
    str[strcspn(str, "\n")] = 0;
    return str;
}

// Function to sanitize the input string
char *sanitizeString(const char *input) {
    size_t length = strlen(input);
    char *sanitized = (char *)malloc(length + 1);
    if (!sanitized) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < length; i++) {
        if (isalnum((unsigned char)input[i])) { // Only alphanumeric characters
            sanitized[j++] = tolower((unsigned char)input[i]); // Convert to lowercase
        }
    }
    sanitized[j] = '\0'; // Null-terminate the string

    return sanitized;
}

// Function to check if a string is a palindrome
int isPalindrome(const char *str) {
    size_t left = 0;
    size_t right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}