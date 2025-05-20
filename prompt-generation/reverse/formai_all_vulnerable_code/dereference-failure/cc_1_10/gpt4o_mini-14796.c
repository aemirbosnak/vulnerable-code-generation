//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
unsigned long calculateChecksum(const char *data);
void readDataFromFile(const char *filename, char **data);
void writeChecksumToFile(const char *filename, unsigned long checksum);
void handleFileError(const char *filename);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *data = NULL;
    readDataFromFile(argv[1], &data);
    
    unsigned long checksum = calculateChecksum(data);
    writeChecksumToFile(argv[2], checksum);
    
    free(data);
    return EXIT_SUCCESS;
}

// Function to read data from a file
void readDataFromFile(const char *filename, char **data) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handleFileError(filename);
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    *data = (char *)malloc(length + 1);
    if (*data == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(*data, 1, length, file);
    (*data)[length] = '\0'; // Null terminate the string
    fclose(file);
}

// Function to handle file errors
void handleFileError(const char *filename) {
    perror(filename);
    exit(EXIT_FAILURE);
}

// Function to calculate the checksum
unsigned long calculateChecksum(const char *data) {
    unsigned long checksum = 0;
    for (size_t i = 0; data[i] != '\0'; i++) {
        checksum += (unsigned char)data[i]; // Summing up ASCII values
    }
    return checksum;
}

// Function to write the checksum to a file
void writeChecksumToFile(const char *filename, unsigned long checksum) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        handleFileError(filename);
    }

    fprintf(file, "Checksum: %lu\n", checksum);
    fclose(file);
}