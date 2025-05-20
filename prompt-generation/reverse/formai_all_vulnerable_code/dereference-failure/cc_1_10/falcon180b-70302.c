//Falcon-180B DATASET v1.0 Category: Recursive ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print a string in reverse order
void reverseString(char* str) {
    int length = strlen(str);
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}

// Recursive function to print a string in reverse order
void reverseStringRecursive(char* str, int start, int end) {
    if (start >= end) {
        return;
    }
    reverseStringRecursive(str, start + 1, end);
    printf("%c", str[start]);
}

// Function to generate a random string of specified length
char* generateRandomString(int length) {
    char* str = (char*) malloc(sizeof(char) * length + 1);
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[length] = '\0';
    return str;
}

int main() {
    // Generate a random string of length 10
    char* str = generateRandomString(10);

    // Print the original string
    printf("Original string: %s\n", str);

    // Print the string in reverse order using a loop
    printf("String in reverse order (using loop): ");
    reverseString(str);
    printf("\n");

    // Print the string in reverse order using recursion
    printf("String in reverse order (using recursion): ");
    reverseStringRecursive(str, 0, strlen(str) - 1);
    printf("\n");

    return 0;
}