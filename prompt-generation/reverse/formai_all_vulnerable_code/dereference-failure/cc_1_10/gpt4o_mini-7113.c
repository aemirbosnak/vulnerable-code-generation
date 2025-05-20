//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum of a string using a simple additive algorithm
unsigned long calculate_checksum(const char *data) {
    unsigned long checksum = 0;
    size_t length = strlen(data);

    for (size_t i = 0; i < length; i++) {
        checksum += data[i];
    }
    
    return checksum;
}

// Function to read a file and calculate its checksum
unsigned long checksum_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return 0;
    }

    unsigned long checksum = 0;
    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            checksum += buffer[i];
        }
    }

    if (ferror(file)) {
        perror("Error reading file");
    }

    fclose(file);
    return checksum;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string or filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (argc == 2) {
        // If there's only one argument, treat it as a string
        unsigned long checksum = calculate_checksum(argv[1]);
        printf("Checksum for string '%s': %lu\n", argv[1], checksum);
    } else {
        // If there are multiple arguments, treat them as filenames
        for (int i = 1; i < argc; i++) {
            unsigned long checksum = checksum_file(argv[i]);
            printf("Checksum for file '%s': %lu\n", argv[i], checksum);
        }
    }

    return EXIT_SUCCESS;
}