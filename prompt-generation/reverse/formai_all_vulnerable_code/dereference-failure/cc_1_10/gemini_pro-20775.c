//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Signature database: an array of virus signatures
char *signatures[] = {
    "EICAR_TEST_FILE", // A harmless test virus
    "W95.CIH", // A destructive virus that infects the BIOS
    "Melissa.A", // A mass-mailing virus that infects Word documents
};

// Scan a file for viruses
int scan_file(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Read the file into a buffer
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    char *buffer = malloc(size);
    if (buffer == NULL) {
        perror("malloc");
        fclose(fp);
        return -1;
    }
    fread(buffer, size, 1, fp);
    fclose(fp);

    // Scan the buffer for signatures
    for (int i = 0; i < sizeof(signatures) / sizeof(char *); i++) {
        if (strstr(buffer, signatures[i]) != NULL) {
            // A virus has been found!
            printf("Virus detected: %s\n", signatures[i]);
            free(buffer);
            return -1;
        }
    }

    // No virus found
    free(buffer);
    return 0;
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    // Scan the file
    int result = scan_file(argv[1]);

    // Print the results
    if (result == -1) {
        printf("File is infected!\n");
    } else {
        printf("File is clean.\n");
    }

    return 0;
}