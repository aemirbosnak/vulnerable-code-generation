//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate simple checksum
unsigned char calculate_checksum(const char *data) {
    unsigned char checksum = 0;
    while (*data) {
        checksum ^= *data;  // XOR each byte into checksum
        data++;
    }
    return checksum;
}

// Function to read data from a file
char* read_file(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long len = ftell(file);
    rewind(file);

    char *buffer = (char*)malloc(len + 1);
    if (!buffer) {
        fprintf(stderr, "Error: Could not allocate memory\n");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, len, file);
    buffer[len] = '\0';  // Null-terminate the string
    fclose(file);
    return buffer;
}

// Function to print checksum
void print_checksum(const char *data, const char *filename) {
    unsigned char checksum = calculate_checksum(data);
    printf("Checksum for file '%s': %02X\n", filename, checksum);
}

// Function to write checksum to output file
void write_checksum_to_file(const char *filename, unsigned char checksum) {
    FILE *file = fopen("checksum_output.txt", "w");
    if (!file) {
        fprintf(stderr, "Error: Could not open output file\n");
        return;
    }
    fprintf(file, "Checksum for file '%s': %02X\n", filename, checksum);
    fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    char *data = read_file(filename);

    if (data) {
        print_checksum(data, filename);
        unsigned char checksum = calculate_checksum(data);
        write_checksum_to_file(filename, checksum);
        free(data);  // Freeing the allocated memory
    }

    return EXIT_SUCCESS;
}