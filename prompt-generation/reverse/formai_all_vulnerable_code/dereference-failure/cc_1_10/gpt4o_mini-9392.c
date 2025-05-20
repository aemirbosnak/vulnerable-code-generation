//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate checksum using simple byte-wise addition
unsigned int calculateChecksum(const char *data) {
    unsigned int checksum = 0;
    while (*data) {
        checksum += (unsigned char)(*data);
        data++;
    }
    return checksum;
}

// Function to read data from a file
char* readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);  // Move file pointer to the end of the file
    long length = ftell(file);  // Get the current file pointer position
    fseek(file, 0, SEEK_SET);    // Reset file pointer to the beginning

    char *data = malloc(length + 1);
    if (!data) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    
    fread(data, 1, length, file); // Read the data into buffer
    data[length] = '\0';           // Null-terminate the string
    fclose(file);                  // Close the file

    return data;
}

// Function to print the checksum in hexadecimal format
void printChecksum(unsigned int checksum) {
    printf("Checksum: 0x%X\n", checksum);
}

// Function to display usage information
void displayUsage(const char *programName) {
    printf("Usage: %s <filename>\n", programName);
    printf("Calculates and displays the checksum of a given file.\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    
    // Read the contents of the file
    char *data = readFile(filename);

    // Calculate the checksum
    unsigned int checksum = calculateChecksum(data);

    // Print the checksum
    printChecksum(checksum);

    // Clean up
    free(data);
    
    return EXIT_SUCCESS;
}