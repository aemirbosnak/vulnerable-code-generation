//FormAI DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ENCRYPTION_KEY 0xA7

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];

    // Open the file
    FILE* file = fopen(filename, "r+");

    // Check if the file was opened successfully
    if (!file) {
        printf("Error opening file '%s'.\n", filename);
        return 1;
    }

    // Get the size of the file
    fseek(file, 0L, SEEK_END);
    long int filesize = ftell(file);
    fseek(file, 0L, SEEK_SET);

    // Read the file into memory
    char* buffer = malloc(filesize);
    fread(buffer, filesize, 1, file);

    // Encrypt the file
    srand(time(NULL));
    int encryption_key = rand() % 255;
    for (int i = 0; i < filesize; i++) {
        buffer[i] ^= encryption_key;
    }

    // Write the encrypted file back to disk
    fseek(file, 0L, SEEK_SET);
    fwrite(buffer, filesize, 1, file);

    // Clean up
    free(buffer);
    fclose(file);

    printf("File '%s' has been encrypted with key 0x%02X.\n", filename, encryption_key);

    return 0;
}