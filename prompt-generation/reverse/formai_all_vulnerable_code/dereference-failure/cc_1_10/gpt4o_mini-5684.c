//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 1024

// Function to calculate the checksum of a file
uint32_t calculate_checksum(FILE *file) {
    uint32_t checksum = 0;
    uint8_t buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Read the file in chunks and update the checksum
    while ((bytesRead = fread(buffer, sizeof(uint8_t), BUFFER_SIZE, file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            checksum += buffer[i];
        }
    }

    if (ferror(file)) {
        perror("Failed to read the file");
        return 0; // Indicates an error condition
    }

    return checksum;
}

// Function to get the filename from user input
void get_filename(char *filename) {
    printf("Enter the filename to calculate its checksum: ");
    if (fgets(filename, MAX_FILENAME_LENGTH, stdin) == NULL) {
        perror("Error reading filename");
        exit(EXIT_FAILURE);
    }

    // Remove trailing newline character
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }
}

// Main function
int main(int argc, char *argv[]) {
    char filename[MAX_FILENAME_LENGTH];

    // Check if filename is passed as command-line argument
    if (argc > 1) {
        strncpy(filename, argv[1], MAX_FILENAME_LENGTH);
    } else {
        get_filename(filename);
    }

    // Open file for reading
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Could not open file '%s': %s\n", filename, strerror(errno));
        return EXIT_FAILURE;
    }

    // Calculate the checksum
    uint32_t checksum = calculate_checksum(file);

    // Close the file
    fclose(file);

    // Print the result
    printf("Checksum of file '%s': %u\n", filename, checksum);

    return EXIT_SUCCESS;
}