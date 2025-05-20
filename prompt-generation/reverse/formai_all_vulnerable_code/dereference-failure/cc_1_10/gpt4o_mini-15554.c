//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function to encrypt a character using a simple XOR cipher
char xor_encrypt_decrypt(char ch, char key) {
    return ch ^ key; // XOR of character and key
}

// Function to encrypt or decrypt a file
void process_file(const char *filename, char key) {
    FILE *file = fopen(filename, "rb+");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s: %s\n", filename, strerror(errno));
        return;
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(filesize);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
        fclose(file);
        return;
    }

    size_t read = fread(buffer, 1, filesize, file);
    if (read != filesize) {
        fprintf(stderr, "Failed to read file: %s\n", strerror(errno));
        free(buffer);
        fclose(file);
        return;
    }

    // Process each character using the XOR cipher
    for (long i = 0; i < filesize; i++) {
        buffer[i] = xor_encrypt_decrypt(buffer[i], key);
    }

    // Seek back to the start of the file and write the modified content
    fseek(file, 0, SEEK_SET);
    size_t written = fwrite(buffer, 1, filesize, file);
    if (written != filesize) {
        fprintf(stderr, "Failed to write to file: %s\n", strerror(errno));
    }

    // Cleanup
    free(buffer);
    fclose(file);
    printf("File \"%s\" processed successfully!\n", filename);
}

// Main function to handle arguments and call the processing function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    char key = argv[2][0]; // Use the first character of the second argument as key

    process_file(filename, key);

    return EXIT_SUCCESS;
}