//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 100

// Function prototypes
void to_lowercase(char *str);
void remove_non_alphanumeric(char *str);
bool is_palindrome(const char *str);

int main() {
    char input[MAX_LENGTH];

    printf("Welcome to the Palindrome Checker\n");
    printf("Enter a string (max %d characters): ", MAX_LENGTH - 1);
    fgets(input, sizeof(input), stdin);

    // Remove the newline character if it is present
    size_t len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    printf("You entered: %s\n", input);

    // Normalize string
    to_lowercase(input);
    remove_non_alphanumeric(input);

    // Check if the string is a palindrome
    if (is_palindrome(input)) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

// Function to remove non-alphanumeric characters from a string
void remove_non_alphanumeric(char *str) {
    char temp[MAX_LENGTH];
    int j = 0;

    for (int i = 0; str[i]; i++) {
        if (isalnum((unsigned char) str[i])) {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0'; // Null-terminate the new string
    strcpy(str, temp); // Copy back to the original string
}

// Function to check if the string is a palindrome
bool is_palindrome(const char *str) {
    size_t left = 0;
    size_t right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false; // Not a palindrome
        }
        left++;
        right--;
    }
    return true; // Is a palindrome
}