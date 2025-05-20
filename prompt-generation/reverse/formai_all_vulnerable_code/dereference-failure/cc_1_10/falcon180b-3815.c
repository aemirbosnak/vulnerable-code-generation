//Falcon-180B DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_SIZE 1000

// Function to reverse a string
void reverse_string(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);
    char* temp = str;
    char* new_str = reversed;

    // Reverse the string
    while (*temp!= '\0') {
        *new_str = *temp;
        temp++;
        new_str++;
    }

    // Add null terminator
    *new_str = '\0';

    // Copy the reversed string back to the original string
    strcpy(str, reversed);

    // Free the memory allocated for the reversed string
    free(reversed);
}

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);

    // Reverse the string
    strcpy(reversed, str);
    reverse_string(reversed);

    // Compare the original string with the reversed string
    int is_palindrome = 1;
    char* original = str;
    char* reversed_copy = reversed;

    while (*original!= '\0' && *reversed_copy!= '\0') {
        if (*original!= *reversed_copy) {
            is_palindrome = 0;
            break;
        }
        original++;
        reversed_copy++;
    }

    free(reversed);
    return is_palindrome;
}

int main() {
    char input[MAX_SIZE];

    // Get input from user
    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Check if input is a palindrome
    if (is_palindrome(input)) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    return 0;
}