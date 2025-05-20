//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a string
#define MAX_STRING_LENGTH 100

// Define the number of strings to be processed
#define NUM_STRINGS 5

// Define the array of strings to be processed
char *strings[] = {
    "The quick brown fox jumps over the lazy dog",
    "The rain in Spain falls mainly on the plain",
    "One fish, two fish, red fish, blue fish",
    "In the town of Springfield, where dreams come true",
    "May the force be with you"
};

// Define the function to reverse a string
char *reverse_string(char *str)
{
    // Get the length of the string
    int length = strlen(str);

    // Create a new string to store the reversed string
    char *reversed_string = malloc(length + 1);

    // Reverse the string
    for (int i = 0; i < length; i++)
    {
        reversed_string[i] = str[length - i - 1];
    }

    // Add the null terminator to the end of the string
    reversed_string[length] = '\0';

    // Return the reversed string
    return reversed_string;
}

// Define the function to print a string in a box
void print_string_in_box(char *str)
{
    // Get the length of the string
    int length = strlen(str);

    // Print the top of the box
    printf("+");
    for (int i = 0; i < length + 2; i++)
    {
        printf("-");
    }
    printf("+\n");

    // Print the sides of the box
    printf("| ");
    printf("%s", str);
    printf(" |\n");

    // Print the bottom of the box
    printf("+");
    for (int i = 0; i < length + 2; i++)
    {
        printf("-");
    }
    printf("+\n");
}

// Define the main function
int main()
{
    // Print a header
    printf("C String Manipulation Examples\n");
    printf("===========================\n\n");

    // Loop through the array of strings
    for (int i = 0; i < NUM_STRINGS; i++)
    {
        // Print the original string
        printf("Original string:\n");
        printf("%s\n\n", strings[i]);

        // Reverse the string
        char *reversed_string = reverse_string(strings[i]);

        // Print the reversed string
        printf("Reversed string:\n");
        printf("%s\n\n", reversed_string);

        // Print the string in a box
        printf("String in a box:\n");
        print_string_in_box(strings[i]);
        printf("\n\n");

        // Free the memory allocated for the reversed string
        free(reversed_string);
    }

    // Return 0 to indicate successful execution
    return 0;
}