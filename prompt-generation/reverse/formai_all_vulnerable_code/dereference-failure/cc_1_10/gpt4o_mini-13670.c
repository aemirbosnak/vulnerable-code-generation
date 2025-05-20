//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ChecksumCalculator {
    uint32_t checksum;
    char file_path[MAX_BUFFER_SIZE];
} ChecksumCalculator;

uint32_t compute_checksum(const char *data, size_t length) {
    uint32_t checksum = 0;
    for (size_t i = 0; i < length; ++i) {
        checksum += (uint8_t)data[i]; 
    }
    return checksum;
}

void display_usage(const char *prog_name) {
    printf("Usage: %s <file_path>\n", prog_name);
    printf("Calculate the checksum of the given file\n");
}

int read_file(const char *file_path, char *buffer, size_t buffer_size) {
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    size_t bytes_read = fread(buffer, 1, buffer_size, file);
    fclose(file);
    return bytes_read;
}

void initialize_calculator(ChecksumCalculator *calc, const char *file_path) {
    calc->checksum = 0;
    strncpy(calc->file_path, file_path, MAX_BUFFER_SIZE - 1);
    calc->file_path[MAX_BUFFER_SIZE - 1] = '\0'; // Ensure null termination
}

void calculate_and_display_checksum(ChecksumCalculator *calc) {
    char buffer[MAX_BUFFER_SIZE];
    int bytes_read = read_file(calc->file_path, buffer, sizeof(buffer));

    if (bytes_read >= 0) {
        calc->checksum = compute_checksum(buffer, bytes_read);
        printf("Checksum for file '%s': 0x%X\n", calc->file_path, calc->checksum);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    ChecksumCalculator calculator;    
    initialize_calculator(&calculator, argv[1]);
    
    calculate_and_display_checksum(&calculator);

    return EXIT_SUCCESS;
}