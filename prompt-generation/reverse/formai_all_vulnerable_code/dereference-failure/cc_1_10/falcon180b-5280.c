//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }

    reversed[length] = '\0';
    printf("Reversed string: %s\n", reversed);
}

// Function to remove all vowels from a string
void removeVowels(char* str) {
    int length = strlen(str);
    char* vowels = "aeiouAEIOU";
    char* result = malloc(length + 1);

    int index = 0;
    for (int i = 0; i < length; i++) {
        if (strchr(vowels, str[i]) == NULL) {
            result[index++] = str[i];
        }
    }

    result[index] = '\0';
    printf("Result: %s\n", result);
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }

    reversed[length] = '\0';

    if (strcmp(str, reversed) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char* input;
    printf("Enter a string: ");
    scanf("%s", input);

    // Reverse the string
    reverseString(input);

    // Remove vowels from the string
    removeVowels(input);

    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}