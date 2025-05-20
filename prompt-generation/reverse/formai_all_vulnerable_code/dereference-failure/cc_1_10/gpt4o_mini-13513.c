//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

// Function to calculate the checksum of a file
unsigned long calculate_checksum(FILE *file) {
    unsigned long checksum = 0;
    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Read the file in chunks
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            checksum += buffer[i];
        }
    }

    // Check for errors
    if (ferror(file)) {
        perror("Error reading the file");
        return 0; // Return 0 on error
    }

    // Close the file
    fclose(file);
    return checksum;
}

// Function to display the checksum value
void display_checksum(const char *filename, unsigned long checksum) {
    printf("\n--- Checksum Calculator ---\n");
    printf("File: %s\n", filename);
    printf("Calculated Checksum: %lu\n", checksum);
    printf("---------------------------\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check for valid arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE; // Exit if wrong usage
    }

    // Open the file in read mode
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error opening the file");
        return EXIT_FAILURE; // Exit if file cannot be opened
    }

    // Calculate the checksum
    unsigned long checksum = calculate_checksum(file);

    // Display the checksum
    if (checksum != 0) {
        display_checksum(argv[1], checksum);
    } else {
        fprintf(stderr, "Checksum calculation failed.\n");
        return EXIT_FAILURE; // Error in checksum calculation
    }

    return EXIT_SUCCESS; // Successful completion
}