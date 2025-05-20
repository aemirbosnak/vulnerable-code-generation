//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to check if a character is alphanumeric
int is_alnum(char c) {
    return (isalpha(c) || isdigit(c));
}

// Function to check if a string is palindrome
int is_palindrome(char *str) {
    int start = 0, end = strlen(str) - 1;
    while (start < end) {
        // If the characters don't match, or if we've reached the end of the string
        if (tolower(str[start]) != tolower(str[end])) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// Function to remove leading and trailing whitespaces from a string
void trim_whitespace(char *str) {
    int start = 0, end = strlen(str) - 1;
    while (isspace(str[start])) {
        start++;
    }
    while (isspace(str[end])) {
        end--;
    }
    if (start > end) {
        str[0] = '\0';
    } else {
        memmove(str, str + start, end - start + 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *input = malloc(MAX_LENGTH);
    strcpy(input, argv[1]);

    // Remove leading and trailing whitespaces
    trim_whitespace(input);

    // Check if the string is palindrome
    if (is_palindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }

    free(input);
    return 0;
}