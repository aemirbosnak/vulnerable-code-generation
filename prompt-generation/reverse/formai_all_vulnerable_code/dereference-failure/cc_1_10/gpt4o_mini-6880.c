//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_LENGTH 1024

// Function prototypes
uint32_t calculate_checksum(const char* data);
void print_usage(const char* program_name);
void read_from_file(const char* file_path, char* buffer, size_t buffer_size);
void read_from_stdin(char* buffer, size_t buffer_size);

// Main function
int main(int argc, char* argv[]) {
    char buffer[MAX_LENGTH];
    
    if (argc < 2) {
        fprintf(stderr, "Insufficient arguments provided.\n");
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    if (strcmp(argv[1], "-f") == 0) {
        if (argc != 3) {
            fprintf(stderr, "File path required after -f.\n");
            print_usage(argv[0]);
            return EXIT_FAILURE;
        }
        read_from_file(argv[2], buffer, MAX_LENGTH);
    } else if (strcmp(argv[1], "-i") == 0) {
        read_from_stdin(buffer, MAX_LENGTH);
    } else {
        fprintf(stderr, "Invalid option: %s\n", argv[1]);
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    uint32_t checksum = calculate_checksum(buffer);
    printf("Checksum: %u\n", checksum);
    return EXIT_SUCCESS;
}

// Function to calculate checksum
uint32_t calculate_checksum(const char* data) {
    uint32_t checksum = 0;
    size_t length = strlen(data);
    
    for (size_t i = 0; i < length; i++) {
        checksum += (uint8_t)data[i];  // Accumulate ASCII values
    }
    
    return checksum;
}

// Function to print usage instructions
void print_usage(const char* program_name) {
    printf("Usage: %s -f <file_path> | -i\n", program_name);
    printf("Options:\n");
    printf("  -f <file_path>    Read data from a file and calculate checksum.\n");
    printf("  -i                Read data from standard input and calculate checksum.\n");
}

// Function to read data from a file
void read_from_file(const char* file_path, char* buffer, size_t buffer_size) {
    FILE* file = fopen(file_path, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    size_t bytes_read = fread(buffer, sizeof(char), buffer_size - 1, file);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';  // Null-terminate the string
    } else {
        buffer[0] = '\0';  // Empty file
    }

    fclose(file);
}

// Function to read data from standard input
void read_from_stdin(char* buffer, size_t buffer_size) {
    printf("Enter data (Ctrl+D to finish):\n");
    if (fgets(buffer, buffer_size, stdin) == NULL) {
        buffer[0] = '\0';  // Empty input
    } else {
        // Stream all input until EOF
        size_t total_length = strlen(buffer);
        while (!feof(stdin) && total_length < buffer_size - 1) {
            fgets(buffer + total_length, buffer_size - total_length - 1, stdin);
            total_length += strlen(buffer + total_length);
        }
        buffer[total_length] = '\0';  // Null-terminate the string
    }
}