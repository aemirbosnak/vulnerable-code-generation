//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse_string(char *str) {
    int length = strlen(str);
    char *reversed = malloc(length + 1); // Allocate memory for the reversed string

    // Reverse the string
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];
    }
    reversed[length] = '\0'; // Add a null character to the end of the reversed string

    return reversed;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int length = strlen(str);

    // Compare the original string with its reverse
    for (int i = 0; i < length / 2; i++) {
        if (str[i]!= str[length - 1 - i]) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Palindrome
}

int main() {
    char input_string[100];

    // Prompt the user to enter a string
    printf("Enter a string: ");
    scanf("%s", input_string);

    // Reverse the input string
    char *reversed_string = reverse_string(input_string);

    // Check if the input string is a palindrome
    if (is_palindrome(input_string)) {
        printf("%s is a palindrome.\n", input_string);
    } else if (is_palindrome(reversed_string)) {
        printf("%s is a palindrome (reversed).\n", input_string);
    } else {
        printf("%s is not a palindrome.\n", input_string);
    }

    // Free the memory allocated for the reversed string
    free(reversed_string);

    return 0;
}