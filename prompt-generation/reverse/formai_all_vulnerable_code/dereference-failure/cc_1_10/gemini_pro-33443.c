//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Signature database
const char *signatures[] = {
    "EICAR_TEST_FILE",
    "CME_01",
    "PE_01",
    "PE_02",
    "MZ_01",
    "MZ_02"
};

// File scanning function
int scanFile(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    // Read the file into a buffer
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = malloc(filesize);
    fread(buffer, 1, filesize, file);
    fclose(file);

    // Scan the buffer for signatures
    for (int i = 0; i < sizeof(signatures) / sizeof(char *); i++) {
        if (strstr(buffer, signatures[i]) != NULL) {
            printf("File %s is infected with %s\n", filename, signatures[i]);
            free(buffer);
            return 0;
        }
    }

    // No signatures found
    printf("File %s is clean\n", filename);
    free(buffer);
    return 0;
}

int main(int argc, char *argv[]) {
    // Check if a filename was provided
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Scan the file
    return scanFile(argv[1]);
}