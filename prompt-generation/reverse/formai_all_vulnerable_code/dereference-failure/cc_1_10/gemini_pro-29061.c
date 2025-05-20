//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_STRING_LENGTH 1024

// Define the initial value of the checksum
#define INITIAL_CHECKSUM_VALUE 0

// Calculate the checksum of a string
unsigned int calculate_checksum(const char *string)
{
    // Initialize the checksum to the initial value
    unsigned int checksum = INITIAL_CHECKSUM_VALUE;

    // Iterate over the characters in the string
    for (int i = 0; i < strlen(string); i++)
    {
        // Add the ASCII value of the character to the checksum
        checksum += string[i];
    }

    // Return the checksum
    return checksum;
}

// Print the checksum of a string
void print_checksum(const char *string)
{
    // Calculate the checksum of the string
    unsigned int checksum = calculate_checksum(string);

    // Print the checksum
    printf("The checksum of the string '%s' is %u\n", string, checksum);
}

// Get the input string from the user
char *get_input_string()
{
    // Allocate memory for the input string
    char *input_string = malloc(MAX_STRING_LENGTH);

    // Get the input string from the user
    printf("Enter a string: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);

    // Return the input string
    return input_string;
}

// Free the memory allocated for the input string
void free_input_string(char *input_string)
{
    // Free the memory allocated for the input string
    free(input_string);
}

// Main function
int main()
{
    // Get the input string from the user
    char *input_string = get_input_string();

    // Print the checksum of the input string
    print_checksum(input_string);

    // Free the memory allocated for the input string
    free_input_string(input_string);

    // Return 0 to indicate success
    return 0;
}