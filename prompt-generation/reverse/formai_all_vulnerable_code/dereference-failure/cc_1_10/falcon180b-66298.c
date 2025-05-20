//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    int j = 0;

    // Reverse the string
    for (int i = len - 1; i >= 0; i--) {
        reversed[j++] = str[i];
    }

    // Add null terminator
    reversed[j] = '\0';

    // Print the reversed string
    printf("Reversed string: %s\n", reversed);
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    int j = 0;

    // Reverse the string
    for (int i = len - 1; i >= 0; i--) {
        reversed[j++] = str[i];
    }

    // Add null terminator
    reversed[j] = '\0';

    // Compare the original and reversed strings
    if (strcmp(str, reversed) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to remove all vowels from a string
void removeVowels(char* str) {
    int len = strlen(str);
    char* vowels = "aeiouAEIOU";
    char* result = malloc(len + 1);
    int j = 0;

    // Remove vowels from the string
    for (int i = 0; i < len; i++) {
        if (strchr(vowels, str[i]) == NULL) {
            result[j++] = str[i];
        }
    }

    // Add null terminator
    result[j] = '\0';

    // Print the result
    printf("Result: %s\n", result);
}

int main() {
    char* str = "A man, a plan, a canal, Panama!";

    // Reverse the string
    reverseString(str);

    // Check if the string is a palindrome
    isPalindrome(str);

    // Remove all vowels from the string
    removeVowels(str);

    return 0;
}