//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Ignore non-alphanumeric characters
        while (left < right && !isalnum((unsigned char)str[left])) left++;
        while (left < right && !isalnum((unsigned char)str[right])) right--;

        if (str[left] != str[right]) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}

char *getInput() {
    char *input = NULL;
    size_t size = 0;

    printf("Enter a string to check for palindrome (or 'exit' to quit): ");
    getline(&input, &size, stdin);

    // Remove newline character if present
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    return input;
}

void freeMemory(char *str) {
    free(str);
}

int main() {
    printf("Welcome to the Palindrome Checker!\n");
    printf("This program checks if a given string is a palindrome.\n");

    while (1) {
        char *inputString = getInput();

        // Check for simple exit command
        if (strcmp(inputString, "exit") == 0) {
            freeMemory(inputString);
            printf("Exiting the Palindrome Checker. Goodbye!\n");
            break;
        }

        // To lower case for comparison
        toLowerCase(inputString);

        // Check if the string is a palindrome
        if (isPalindrome(inputString)) {
            printf("'%s' is a palindrome!\n", inputString);
        } else {
            printf("'%s' is not a palindrome.\n", inputString);
        }

        // Free the allocated memory
        freeMemory(inputString);
    }

    return 0;
}