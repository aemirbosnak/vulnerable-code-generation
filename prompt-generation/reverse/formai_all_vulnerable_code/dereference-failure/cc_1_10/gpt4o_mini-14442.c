//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to lower case
char* toLowerCase(const char* str) {
    size_t length = strlen(str);
    char* lowerStr = (char*)malloc(length + 1); // +1 for the null terminator
    if (!lowerStr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < length; i++) {
        lowerStr[i] = tolower((unsigned char)str[i]);
    }
    lowerStr[length] = '\0'; // Null-terminate the string
    return lowerStr;
}

// Function to remove non-alphanumeric characters from a string
char* removeNonAlphanumeric(const char* str) {
    size_t length = strlen(str);
    char* cleanedStr = (char*)malloc(length + 1); // +1 for the null terminator
    if (!cleanedStr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    size_t index = 0;
    for (size_t i = 0; i < length; i++) {
        if (isalnum((unsigned char)str[i])) {
            cleanedStr[index++] = str[i];
        }
    }
    cleanedStr[index] = '\0'; // Null-terminate the cleaned string
    return cleanedStr;
}

// Function to check if a string is a palindrome
int isPalindrome(const char* str) {
    size_t length = strlen(str);
    for (size_t i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

// Main function
int main() {
    char input[256]; // Buffer to hold user input
    printf("Welcome to the Palindrome Checker!\n");
    printf("Enter a phrase or word to check if it's a palindrome: ");
    
    // Get user input
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }
    
    // Remove the trailing newline character
    input[strcspn(input, "\n")] = 0;
    
    // Process the input
    char* lowerCaseInput = toLowerCase(input);
    char* cleanedInput = removeNonAlphanumeric(lowerCaseInput);
    
    // Check if the cleaned input is a palindrome
    if (isPalindrome(cleanedInput)) {
        printf("The input \"%s\" is a palindrome.\n", input);
    } else {
        printf("The input \"%s\" is not a palindrome.\n", input);
    }

    // Clean up dynamically allocated memory
    free(lowerCaseInput);
    free(cleanedInput);

    return 0;
}