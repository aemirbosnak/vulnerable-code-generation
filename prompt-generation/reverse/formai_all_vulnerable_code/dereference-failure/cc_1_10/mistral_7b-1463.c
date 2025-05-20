//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

// Function to check if a given string is a palindrome
int is_palindrome(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        // If the characters do not match, return false
        if (str[start] != str[end])
            return 0;

        // Move start pointer towards end and end pointer towards start
        start++;
        end--;
    }

    // If we have reached the end of the string, it is a palindrome
    return 1;
}

// Function to check if a given character is alphanumeric
int is_alphanumeric(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        return 1;

    return 0;
}

// Function to check if a given string is a palindrome after removing spaces and converting to lowercase
int is_palindrome_safe(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    // Skip non-alphanumeric characters
    while (start <= end && !is_alphanumeric(str[start]))
        start++;

    while (end >= start && !is_alphanumeric(str[end]))
        end--;

    // If we have reached the end of the string without finding matching characters, it is a palindrome
    if (start > end)
        return 1;

    // Check if the characters match
    if (tolower(str[start]) != tolower(str[end]))
        return 0;

    // Move pointers towards middle
    start++;
    end--;

    // Recursively check the remaining part of the string
    return is_palindrome_safe(str + start) && is_palindrome_safe(str + end + 1);
}

// Main function to test the palindrome checker
int main(int argc, char **argv) {
    char input[MAX_LENGTH];

    // Check if the input is provided
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    // Copy the input string to a local variable
    strcpy(input, argv[1]);

    // Check if the given string is a palindrome
    if (is_palindrome_safe(input))
        printf("%s is a palindrome.\n", input);
    else
        printf("%s is not a palindrome.\n", input);

    return 0;
}