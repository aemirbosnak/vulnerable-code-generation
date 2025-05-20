//FormAI DATASET v1.0 Category: File Synchronizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1024

// Function to synchronize two files
void syncFiles(FILE *src, FILE *dest) {
    char buffer[BUFSIZE];
    size_t bytes;

    // Loop through each block of the source file and write it to the destination file
    while ((bytes = fread(buffer, 1, BUFSIZE, src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    // Flush the buffer and close the files
    fflush(src);
    fflush(dest);
    fclose(src);
    fclose(dest);
}

int main(int argc, char *argv[]) {

    // Check command line arguments
    if (argc != 3) {
        printf("Usage: %s [source file] [destination file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Check if the source and destination files are the same
    if (strcmp(argv[1], argv[2]) == 0) {
        printf("Error: Source and destination file cannot be the same\n");
        exit(EXIT_FAILURE);
    }

    // Open the source and destination files for reading/writing
    FILE *srcFile = fopen(argv[1], "rb");
    if (srcFile == NULL) {
        printf("Error: Could not open source file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *destFile = fopen(argv[2], "wb");
    if (destFile == NULL) {
        printf("Error: Could not open destination file: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // Sync the files
    syncFiles(srcFile, destFile);

    printf("File synchronization complete\n");

    return 0;
}