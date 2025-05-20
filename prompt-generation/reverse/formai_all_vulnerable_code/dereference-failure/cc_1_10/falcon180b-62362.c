//Falcon-180B DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of strings that can be stored
#define MAX_STRINGS 100

// Define the structure for each string
typedef struct {
    char *str;
    int len;
} STRING;

// Define the global array of strings
STRING strings[MAX_STRINGS];

// Define the current number of strings
int num_strings = 0;

// Define the function to add a string to the array
void add_string(char *str) {
    // Check if there is space in the array
    if (num_strings >= MAX_STRINGS) {
        printf("Error: Cannot add more strings.\n");
        return;
    }
    // Allocate memory for the new string
    strings[num_strings].str = malloc(strlen(str) + 1);
    // Copy the string to the allocated memory
    strcpy(strings[num_strings].str, str);
    // Set the length of the string
    strings[num_strings].len = strlen(str);
    // Increment the number of strings
    num_strings++;
}

// Define the function to print all the strings in the array
void print_strings() {
    printf("Strings:\n");
    for (int i = 0; i < num_strings; i++) {
        printf("%d: %s\n", i, strings[i].str);
    }
}

// Define the main function
int main() {
    // Add some strings to the array
    add_string("Hello");
    add_string("World");
    add_string("C Programming");
    add_string("Memory Management");
    // Print the strings in the array
    print_strings();
    // Free the memory allocated for the strings
    for (int i = 0; i < num_strings; i++) {
        free(strings[i].str);
    }
    // Set the number of strings to zero
    num_strings = 0;
    // Print the strings in the array again (should be empty)
    print_strings();
    return 0;
}