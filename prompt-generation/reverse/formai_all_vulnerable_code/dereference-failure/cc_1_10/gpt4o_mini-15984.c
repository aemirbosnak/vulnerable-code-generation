//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the details of a checksum calculation
typedef struct {
    char *filename;
    unsigned long checksum;
} ChecksumCalculator;

// Function prototypes
ChecksumCalculator* create_calculator(const char *filename);
void calculate_checksum(ChecksumCalculator *calc);
void display_result(ChecksumCalculator *calc);
void cleanup_calculator(ChecksumCalculator *calc);
unsigned long simple_checksum(const char *buffer, size_t length);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ChecksumCalculator *calculator = create_calculator(argv[1]);
    calculate_checksum(calculator);
    display_result(calculator);
    cleanup_calculator(calculator);

    return EXIT_SUCCESS;
}

// Function to create a new checksum calculator
ChecksumCalculator* create_calculator(const char *filename) {
    ChecksumCalculator *calc = malloc(sizeof(ChecksumCalculator));
    if (!calc) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    calc->filename = strdup(filename);
    calc->checksum = 0;
    return calc;
}

// Function to calculate the checksum of the file
void calculate_checksum(ChecksumCalculator *calc) {
    FILE *file = fopen(calc->filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", calc->filename);
        cleanup_calculator(calc);
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        calc->checksum += simple_checksum(buffer, bytesRead);
    }

    fclose(file);
}

// Function to display the result of the checksum
void display_result(ChecksumCalculator *calc) {
    printf("Checksum for file '%s': %lu\n", calc->filename, calc->checksum);
}

// Function to release resources
void cleanup_calculator(ChecksumCalculator *calc) {
    free(calc->filename);
    free(calc);
}

// Function to compute a simple checksum (e.g., sum of byte values)
unsigned long simple_checksum(const char *buffer, size_t length) {
    unsigned long sum = 0;
    for (size_t i = 0; i < length; i++) {
        sum += (unsigned char)buffer[i];
    }
    return sum;
}