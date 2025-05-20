//Falcon-180B DATASET v1.0 Category: Error handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a string
#define MAX_LENGTH 100

// Function prototypes
void read_string(char *str);
void reverse_string(char *str);
void print_string(char *str);
void error_handler(char *message);

// Main function
int main() {
    char input_str[MAX_LENGTH];

    // Read a string from the user
    printf("Enter a string: ");
    read_string(input_str);

    // Reverse the string
    reverse_string(input_str);

    // Print the reversed string
    printf("Reversed string: %s\n", input_str);

    return 0;
}

// Function to read a string from the user
void read_string(char *str) {
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    // Remove the newline character at the end of the string
    str[strcspn(str, "\n")] = '\0';
}

// Function to reverse a string
void reverse_string(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

// Function to print a string
void print_string(char *str) {
    printf("%s\n", str);
}

// Function to handle errors
void error_handler(char *message) {
    printf("Error: %s\n", message);
    exit(1);
}