//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum
unsigned long calculate_checksum(const char *data) {
    unsigned long checksum = 0;
    size_t length = strlen(data);
    
    for (size_t i = 0; i < length; i++) {
        checksum += data[i]; // Add ASCII values of each character
    }
    return checksum;
}

// Function to read a file and calculate its checksum
unsigned long checksum_from_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return 0;
    }
    
    unsigned long checksum = 0;
    char buffer[1024];
    size_t bytesRead;

    // Read the file in chunks
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            checksum += buffer[i]; // Add to checksum
        }
    }
    
    fclose(file);
    return checksum;
}

// Function to display the checksum in a formatted manner
void display_checksum(const char *data, unsigned long checksum) {
    printf("Data: \"%s\"\n", data);
    printf("Checksum: %lu\n", checksum);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <option> <input>\n", argv[0]);
        fprintf(stderr, "Options:\n");
        fprintf(stderr, "  -s : Calculate checksum from string argument\n");
        fprintf(stderr, "  -f : Calculate checksum from file\n");
        return EXIT_FAILURE;
    }
    
    unsigned long checksum = 0;

    // Inspecting the options given as input
    if (strcmp(argv[1], "-s") == 0) {
        checksum = calculate_checksum(argv[2]);
        display_checksum(argv[2], checksum);
    } else if (strcmp(argv[1], "-f") == 0) {
        checksum = checksum_from_file(argv[2]);
        if (checksum != 0) {
            printf("Checksum for file '%s': %lu\n", argv[2], checksum);
        }
    } else {
        fprintf(stderr, "Invalid option. Use -s for string or -f for file.\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}