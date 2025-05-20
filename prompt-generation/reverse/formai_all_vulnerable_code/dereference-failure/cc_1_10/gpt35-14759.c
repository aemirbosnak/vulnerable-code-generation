//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // 1MB

// Function to scan the given file for virus signatures
void scan_file(char* filename) {
    FILE* file_ptr = fopen(filename, "rb");

    // Check if file was opened successfully
    if (file_ptr == NULL) {
        printf("Unable to open file %s\n", filename);
        return;
    }

    // Read the contents of the file into memory
    unsigned char* file_data = malloc(MAX_FILE_SIZE);
    size_t file_size = fread(file_data, 1, MAX_FILE_SIZE, file_ptr);
    fclose(file_ptr);

    // Check if file was read successfully
    if (file_size == 0) {
        printf("Unable to read file %s\n", filename);
        return;
    }

    // Scan for virus signatures in the file
    unsigned char virus_signature[] = {0x4D, 0x5A}; // "MZ" in ASCII
    for (int i = 0; i < file_size - 1; i++) {
        if (memcmp(file_data + i, virus_signature, 2) == 0) {
            printf("Infected file detected: %s\n", filename);
            free(file_data);
            return;
        }
    }

    // Free the allocated memory
    free(file_data);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename> [filename2] [filename3] ...\n", argv[0]);
        return 1;
    }

    // Scan each file provided in the command line arguments
    for (int i = 1; i < argc; i++) {
        printf("Scanning file: %s\n", argv[i]);
        scan_file(argv[i]);
    }

    return 0;
}