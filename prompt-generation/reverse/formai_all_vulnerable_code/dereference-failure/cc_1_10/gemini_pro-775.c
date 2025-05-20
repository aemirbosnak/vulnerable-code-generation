//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *signature;
} Virus;

// A database of known viruses
Virus viruses[] = {
    { "Virus A", "0001001010110100" },
    { "Virus B", "1010101100101010" },
    { "Virus C", "0100101010100101" }
};

int main() {
    // Get the file to be scanned
    char filename[256];
    printf("Enter the name of the file to be scanned: ");
    scanf("%s", filename);

    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return EXIT_FAILURE;
    }

    // Read the file into a buffer
    fseek(file, 0L, SEEK_END);
    long filesize = ftell(file);
    rewind(file);
    char *buffer = malloc(filesize);
    fread(buffer, 1, filesize, file);
    fclose(file);

    // Scan the file for viruses
    int found = 0;
    for (int i = 0; i < sizeof(viruses) / sizeof(Virus); i++) {
        char *signature = viruses[i].signature;
        int signature_len = strlen(signature);
        for (long j = 0; j < filesize - signature_len; j++) {
            if (memcmp(&buffer[j], signature, signature_len) == 0) {
                printf("Virus found: %s\n", viruses[i].name);
                found = 1;
                break;
            }
        }
    }

    // Print the results
    if (!found) {
        printf("No viruses found.\n");
    }

    // Clean up
    free(buffer);

    return EXIT_SUCCESS;
}