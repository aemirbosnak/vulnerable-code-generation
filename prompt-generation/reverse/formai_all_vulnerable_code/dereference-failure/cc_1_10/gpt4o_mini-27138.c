//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate checksum
unsigned long long compute_checksum(const char *data, size_t length) {
    unsigned long long checksum = 0;
    for (size_t i = 0; i < length; ++i) {
        checksum += (unsigned char)data[i];
    }
    return checksum;
}

// Function to print the checksum in hexadecimal format
void print_checksum(unsigned long long checksum) {
    printf("Checksum (Hex): %llx\n", checksum);
}

// Function to read data from a file
char* read_file(const char *filename, size_t *out_length) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    fseek(file, 0, SEEK_END);
    *out_length = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *buffer = malloc(*out_length + 1);
    if (!buffer) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    
    fread(buffer, 1, *out_length, file);
    buffer[*out_length] = '\0'; // Null-terminate
    fclose(file);
    return buffer;
}

// Main function
int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    size_t data_length = 0;
    char *data = read_file(argv[1], &data_length); // Read data from file
    
    unsigned long long checksum = compute_checksum(data, data_length); // Calculate checksum
    print_checksum(checksum); // Output the checksum
    
    free(data); // Clean up
    return 0;
}