//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <math.h>

// Define the maximum length of the input string.
#define MAX_STRING_LENGTH 1024

// Define the number of bytes in a checksum.
#define CHECKSUM_SIZE 4

// Get the checksum of a string.

void getChecksum(char *string, unsigned int *checksum) {
    // Initialize the checksum to zero.
    *checksum = 0;

    // Iterate over the string.
    for (int i = 0; i < strlen(string); i++) {
        // Get the character at the current index.
        char character = string[i];

        // Add the ASCII value of the character to the checksum.
        *checksum += character;
    }

    // Take the modulo of the checksum by 256 to get the final checksum.
    *checksum %= 256;
}

// Calculate the complement of a checksum.
void getChecksumComplement(unsigned int *checksum) {
    // Take the one's complement of the checksum.
    *checksum = ~*checksum;

    // Add one to the checksum to get the two's complement.
    *checksum++;
}

// Print the checksum as a hex string.
void printChecksum(unsigned int *checksum) {
    // Convert the checksum to a hex string.
    char hexString[CHECKSUM_SIZE * 2 + 1];
    sprintf(hexString, "%02X", *checksum);

    // Print the hex string.
    printf("%s\n", hexString);
}

// Get the input string from the user.
char *getInputString() {
    // Allocate memory for the input string.
    char *string = malloc(MAX_STRING_LENGTH + 1);

    // Get the input string from the user.
    printf("Enter the string: ");
    fgets(string, MAX_STRING_LENGTH, stdin);

    // Return the input string.
    return string;
}

// Main function.
int main() {
    // Get the input string from the user.
    char *string = getInputString();

    // Get the checksum of the input string.
    unsigned int checksum;
    getChecksum(string, &checksum);

    // Calculate the complement of the checksum.
    getChecksumComplement(&checksum);

    // Print the checksum as a hex string.
    printChecksum(&checksum);

    // Free the memory allocated for the input string.
    free(string);

    return 0;
}