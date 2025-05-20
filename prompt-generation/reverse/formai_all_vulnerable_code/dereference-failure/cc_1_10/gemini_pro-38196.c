//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Signature database
char *signatures[] = {
    "EICAR_TEST_FILE",
    "W32.Beagle.A",
    "W32.Netsky.B",
    "W32.Sobig.F",
    "W32.Mydoom.A"
};

// Scan a file for viruses
int scan_file(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    // Read the file contents into a buffer
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = malloc(filesize);
    fread(buffer, 1, filesize, file);
    fclose(file);

    // Scan the buffer for viruses
    for (int i = 0; i < sizeof(signatures) / sizeof(char *); i++) {
        if (strstr(buffer, signatures[i]) != NULL) {
            printf("Virus detected: %s\n", signatures[i]);
            free(buffer);
            return 1;
        }
    }

    // No viruses detected
    printf("No viruses detected\n");
    free(buffer);
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check for arguments
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Scan the file
    return scan_file(argv[1]);
}