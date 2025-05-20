//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse a string and extract its length
int parseStringLength(char* str) {
    int length = 0;
    while (*str) {
        length++;
        str++;
    }
    return length;
}

// Function to print the parsed string length
void printStringLength(int length) {
    printf("The length of the string is: %d\n", length);
}

// Function to parse a string and extract its characters
char* parseStringChars(char* str, int length) {
    char* result = (char*)malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        result[i] = str[i];
    }
    return result;
}

// Function to print the parsed string characters
void printStringChars(char* str) {
    printf("The characters in the string are: %s\n", str);
}

int main() {
    // Prompt the user to enter a string
    char* input = (char*)malloc(256 * sizeof(char));
    printf("Enter a string: ");
    fgets(input, 255, stdin);

    // Parse the string and extract its length
    int length = parseStringLength(input);

    // Print the parsed string length
    printStringLength(length);

    // Parse the string and extract its characters
    char* characters = parseStringChars(input, length);

    // Print the parsed string characters
    printStringChars(characters);

    // Free the memory allocated for the input string and its characters
    free(input);
    free(characters);

    return 0;
}