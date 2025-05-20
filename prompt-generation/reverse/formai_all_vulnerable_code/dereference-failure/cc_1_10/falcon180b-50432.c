//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverse_string(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    int j = 0;

    // Reverse the string
    for (int i = len - 1; i >= 0; i--) {
        reversed[j++] = str[i];
    }

    // Set the null terminator
    reversed[j] = '\0';

    // Print the reversed string
    printf("Reversed string: %s\n", reversed);

    // Free the memory
    free(reversed);
}

int main() {
    char input_string[100];

    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", input_string);

    // Reverse the string
    reverse_string(input_string);

    // Convert string to uppercase
    char* uppercase_string = malloc(strlen(input_string) + 1);
    strcpy(uppercase_string, input_string);
    for (int i = 0; i < strlen(uppercase_string); i++) {
        uppercase_string[i] = toupper(uppercase_string[i]);
    }

    // Print the uppercase string
    printf("Uppercase string: %s\n", uppercase_string);

    // Free the memory
    free(uppercase_string);

    return 0;
}