//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

// Function to check if a string is a palindrome
bool is_palindrome(char* str) {
    int length = strlen(str);
    char* reversed = malloc(MAX_LENGTH * sizeof(char));

    // Reverse the string
    int i = 0;
    int j = length - 1;
    while (i < j) {
        reversed[i++] = tolower(str[j--]);
    }
    reversed[i] = '\0';

    // Compare the original and reversed strings
    bool is_palindrome = true;
    for (int k = 0; k < length; k++) {
        if (str[k]!= reversed[k]) {
            is_palindrome = false;
            break;
        }
    }

    free(reversed);
    return is_palindrome;
}

int main() {
    char input[MAX_LENGTH];

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove the newline character
    input[strcspn(input, "\n")] = '\0';

    // Check if the string is a palindrome
    if (is_palindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}