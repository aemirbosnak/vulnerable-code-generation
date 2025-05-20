//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Virus signature database
char *signatures[] = {
    "EICAR-STANDARD-ANTIVIRUS-TEST-FILE",
    "W95.CIH",
    "Melissa.A",
    "ILOVEYOU",
    "AnnaKournikova"
};

// Function to scan a file for viruses
int scan_file(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read the file into a buffer
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);
    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory for buffer");
        fclose(fp);
        return -1;
    }
    fread(buffer, file_size, 1, fp);
    fclose(fp);

    // Search the buffer for virus signatures
    for (int i = 0; i < sizeof(signatures) / sizeof(char *); i++) {
        if (strstr(buffer, signatures[i]) != NULL) {
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
        return 1;
    }

    // Scan the file for viruses
    int result = scan_file(argv[1]);

    // Print the results
    if (result == 1) {
        printf("Virus found in %s\n", argv[1]);
    } else if (result == -1) {
        printf("Error scanning file\n");
    } else {
        printf("No viruses found in %s\n", argv[1]);
    }

    return 0;
}