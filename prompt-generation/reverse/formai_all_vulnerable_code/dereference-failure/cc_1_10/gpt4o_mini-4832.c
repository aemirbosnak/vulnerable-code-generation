//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void getInput(char *inputBuffer, size_t bufferSize);
char *cleanString(const char *input);
int isPalindrome(const char *str);
void toLowerCase(char *str);

// Main function
int main() {
    size_t bufferSize = 256;
    char *inputBuffer = malloc(bufferSize);
    
    if (inputBuffer == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    while (1) {
        printf("Enter a string to check if it's a palindrome (type 'exit' to quit):\n");
        getInput(inputBuffer, bufferSize);

        if (strcmp(inputBuffer, "exit") == 0) {
            break;
        }

        char *cleanedString = cleanString(inputBuffer);
        if (cleanedString == NULL) {
            fprintf(stderr, "Error cleaning the input string!\n");
            free(inputBuffer);
            return 1;
        }

        if (isPalindrome(cleanedString)) {
            printf("The string '%s' is a palindrome.\n", inputBuffer);
        } else {
            printf("The string '%s' is not a palindrome.\n", inputBuffer);
        }

        free(cleanedString);
    }

    free(inputBuffer);
    return 0;
}

// Function to get user input
void getInput(char *inputBuffer, size_t bufferSize) {
    if (fgets(inputBuffer, bufferSize, stdin) != NULL) {
        inputBuffer[strcspn(inputBuffer, "\n")] = 0; // Remove newline character
    }
}

// Function to clean the input string
char *cleanString(const char *input) {
    size_t length = strlen(input);
    char *cleanedString = malloc(length + 1);
    if (cleanedString == NULL) {
        return NULL;
    }
    
    int j = 0;
    for (size_t i = 0; i < length; i++) {
        char currentChar = input[i];
        if (isalnum(currentChar)) {
            cleanedString[j++] = tolower(currentChar); // Convert to lowercase and keep alphanumeric chars
        }
    }
    cleanedString[j] = '\0'; // Null-terminate the cleaned string

    return cleanedString;
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