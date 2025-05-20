//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define virus signature database
const char *virus_signatures[] = {
    "EICAR-STANDARD-ANTIVIRUS-TEST-FILE",
    "W32.Stuxnet",
    "W32.Conficker",
    "W32.Blaster",
    "W32.Sasser"
};

// Define maximum number of virus signatures
#define MAX_SIGNATURES 5

// Function to scan a file for viruses
int scan_file(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    // Read the file contents into a buffer
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = malloc(file_size);
    fread(buffer, file_size, 1, file);
    fclose(file);

    // Search for virus signatures in the buffer
    for (int i = 0; i < MAX_SIGNATURES; i++) {
        if (strstr(buffer, virus_signatures[i]) != NULL) {
            printf("Virus detected: %s\n", virus_signatures[i]);
            free(buffer);
            return 1;
        }
    }

    // No virus detected
    printf("No virus detected\n");
    free(buffer);
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if a filename was provided
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Scan the file for viruses
    int result = scan_file(argv[1]);

    // Exit with the appropriate status code
    return result;
}