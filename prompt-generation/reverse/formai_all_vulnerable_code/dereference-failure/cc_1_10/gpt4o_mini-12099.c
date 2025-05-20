//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Function to calculate the checksum of a given string
uint32_t calculate_checksum(const char *data) {
    uint32_t checksum = 0;
    while (*data) {
        checksum += (uint32_t)(*data); // Add ASCII value of each character
        data++; // Move to the next character
    }
    return checksum; // Return the calculated checksum
}

// Function to print the usage instructions
void print_usage() {
    printf("Checksum Calculator\n");
    printf("====================\n");
    printf("Usage: checksum_calculator <string>\n");
    printf("Calculates the checksum of a string based on ASCII values.\n");
    printf("Example: checksum_calculator \"Hello, World!\"\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is passed
    if (argc != 2) {
        print_usage(); // Show usage instructions
        return EXIT_FAILURE; // Exit with failure status
    }

    const char *input_string = argv[1]; // Get the input string from arguments

    printf("Calculating checksum for the input string...\n");
    printf("Input String: \"%s\"\n", input_string);

    // Call the checksum calculation function
    uint32_t checksum = calculate_checksum(input_string);

    // Print the result with enthusiasm!
    printf("🎉 The calculated checksum is: %u 🎉\n", checksum);
    
    // Let's have some fun calculating the checksum in a loop with different strings!
    char *sample_strings[] = {
        "First String",
        "Second String!",
        "Checksum fun!",
        "C programming rocks!",
        "Energetic is the theme!",
        NULL // Sentinel value to mark the end of the array
    };

    for (int i = 0; sample_strings[i] != NULL; i++) {
        uint32_t sample_checksum = calculate_checksum(sample_strings[i]);
        printf("For the sample \"%s\", the checksum is: %u\n", sample_strings[i], sample_checksum);
    }

    printf("💡 Remember, the world of checksums can help ensure integrity in data handling! 💡\n");

    return EXIT_SUCCESS; // Exit with success status
}