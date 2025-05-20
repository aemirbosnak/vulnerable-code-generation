//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Function to compute a simple checksum
uint32_t calculate_checksum(const char *data, size_t length) {
    uint32_t checksum = 0;
    for (size_t i = 0; i < length; i++) {
        checksum += (uint8_t)data[i];
    }
    return checksum;
}

// Function to read a file and return its content and length
char *read_file(const char *filename, size_t *length) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    *length = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc(*length + 1);
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, *length, file);
    buffer[*length] = '\0'; // Null-terminate the string

    fclose(file);
    return buffer;
}

// Function to display the checksum result
void display_checksum(const char *filename, uint32_t checksum) {
    printf("Checksum for file '%s': 0x%08X\n", filename, checksum);
}

// Main function to read a file and calculate its checksum
int main(int argc, char *argv[]) {
    // Check for valid number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t length;
    char *data = read_file(argv[1], &length);
    if (!data) {
        // An error occurred while reading the file
        return EXIT_FAILURE;
    }

    // Calculate the checksum of the data
    uint32_t checksum = calculate_checksum(data, length);
    
    // Display the checksum
    display_checksum(argv[1], checksum);
    
    // Clean up allocated memory
    free(data);

    return EXIT_SUCCESS;
}