//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize the virus signature database
const char *virus_signatures[] = {
    "EICAR_TEST_FILE",
    "W32.Nimda.A",
    "W32.Sober.C",
    "W32.Mydoom.A"
};

// Scan a file for viruses
int scan_file(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return -1;
    }

    // Read the file into a buffer
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        fclose(file);
        return -1;
    }

    fread(buffer, 1, file_size, file);
    fclose(file);

    // Scan the buffer for virus signatures
    for (int i = 0; i < sizeof(virus_signatures) / sizeof(char *); i++) {
        if (strstr(buffer, virus_signatures[i]) != NULL) {
            free(buffer);
            return 1;
        }
    }

    // No viruses found
    free(buffer);
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if a filename was provided
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    // Scan the file
    int result = scan_file(argv[1]);

    // Print the result
    if (result == 1) {
        printf("Virus found!\n");
    } else if (result == -1) {
        printf("Error: could not open file.\n");
    } else {
        printf("No viruses found.\n");
    }

    return 0;
}