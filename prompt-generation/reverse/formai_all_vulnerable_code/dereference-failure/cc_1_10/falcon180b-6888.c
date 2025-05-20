//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1); // Allocate memory for the reversed string

    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i]; // Copy the characters in reverse order
    }
    reversed[length] = '\0'; // Add null terminator to the end of the reversed string

    // Print the reversed string
    printf("Reversed string: %s\n", reversed);

    // Free the memory allocated for the reversed string
    free(reversed);
}

// A function to check if a string is a palindrome
int isPalindrome(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1); // Allocate memory for the reversed string

    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i]; // Copy the characters in reverse order
    }
    reversed[length] = '\0'; // Add null terminator to the end of the reversed string

    if (strcmp(str, reversed) == 0) {
        return 1; // The string is a palindrome
    } else {
        return 0; // The string is not a palindrome
    }
}

int main() {
    char* input = (char*)malloc(1000 * sizeof(char)); // Allocate memory for the input string
    printf("Enter a string: ");
    fgets(input, 1000, stdin); // Read the input string from the user

    reverseString(input); // Reverse the input string

    if (isPalindrome(input)) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    free(input); // Free the memory allocated for the input string

    return 0;
}