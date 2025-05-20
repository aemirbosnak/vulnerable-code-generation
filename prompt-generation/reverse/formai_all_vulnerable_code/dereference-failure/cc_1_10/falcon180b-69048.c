//Falcon-180B DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

// Function to handle errors
void error_handler(char* msg) {
    printf("ERROR: %s\n", msg);
    exit(EXIT_FAILURE);
}

// Function to read input from user
char* read_input(char* prompt) {
    char input[MAX_LEN];
    printf("%s", prompt);
    fgets(input, MAX_LEN, stdin);
    return strdup(input);
}

// Function to validate input
int is_valid_input(char* input) {
    int len = strlen(input);
    if (len == 0) {
        error_handler("Input cannot be empty");
    }
    return 1;
}

// Function to reverse a string
char* reverse_string(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    int i, j;
    for (i = 0, j = len - 1; i < len; i++, j--) {
        reversed[i] = str[j];
    }
    reversed[len] = '\0';
    return reversed;
}

// Main function
int main() {
    char* input;
    input = read_input("Enter a string: ");
    if (!is_valid_input(input)) {
        return 1;
    }
    char* reversed = reverse_string(input);
    printf("Reversed string: %s\n", reversed);
    free(reversed);
    free(input);
    return 0;
}