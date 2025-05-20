//FormAI DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Checking if the necessary arguments are provided
    if (argc < 3) {
        printf("Usage: %s <file_to_encrypt> <encryption_key>\n", argv[0]);
        return 1;
    }

    // Opening the file in read-only mode
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file '%s'\n", argv[1]);
        return 2;
    }

    // Calculating the length of the file
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    // Reading the contents of the file into a buffer
    char *buffer = (char *) malloc(file_size);
    fread(buffer, 1, file_size, fp);

    // Closing the file
    fclose(fp);

    // Extracting the encryption key from the command line arguments
    char *key = argv[2];
    int key_length = strlen(key);

    // Encrypting the contents of the buffer using the specified key
    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= key[i % key_length];
    }

    // Creating a new filename
    char *filename = (char *) malloc(strlen(argv[1]) + 5);
    strcpy(filename, argv[1]);
    strcat(filename, ".enc");

    // Saving the encrypted contents to the new file
    FILE *enc_file = fopen(filename, "w");
    fwrite(buffer, 1, file_size, enc_file);
    fclose(enc_file);

    // Cleaning up
    free(buffer);
    free(filename);

    // Finishing up
    printf("Encryption successful! Encrypted file saved as '%s'\n", filename);
    return 0;
}