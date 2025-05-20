//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum of a string
unsigned long calculate_checksum(const char *str) {
    unsigned long checksum = 0;
    
    // Calculate checksum by summing the ASCII values of each character
    while (*str) {
        checksum += (unsigned char)(*str);
        str++;
    }

    return checksum;
}

// Function to display a friendly message
void display_message() {
    printf("****************************************\n");
    printf("           Welcome to the Checksum      \n");
    printf("             Calculator Program          \n");
    printf("  Here, we appreciate your effort in     \n");
    printf("         learning and coding!           \n");
    printf("****************************************\n\n");
}

int main() {
    display_message();
    
    // Allocate memory for the input string
    char *input_string = NULL;
    size_t length = 0;

    // Prompt the user for input
    printf("Please enter a string to calculate its checksum:\n");
    getline(&input_string, &length, stdin);
    
    // Remove newline character from input if present
    size_t input_len = strlen(input_string);
    if (input_len > 0 && input_string[input_len - 1] == '\n') {
        input_string[input_len - 1] = '\0';
    }

    // Calculate checksum
    unsigned long checksum = calculate_checksum(input_string);

    // Display the checksum result
    printf("The checksum for the string \"%s\" is: %lu\n", input_string, checksum);

    // Clean up dynamically allocated memory
    free(input_string);
    
    printf("\nThank you for using the Checksum Calculator!\n");
    printf("Keep coding and inspiring others!\n");
    return 0;
}