//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt/decrypt the data
void encryptDecrypt(char *data, const char *key) {
    size_t keyLength = strlen(key);
    for (size_t i = 0; i < strlen(data); i++) {
        data[i] ^= key[i % keyLength];
    }
}

// Function to read the file contents
char* readFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file for reading");
        return NULL;
    }
    
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *buffer = malloc(filesize + 1);
    if (!buffer) {
        perror("Could not allocate memory");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, filesize, file);
    buffer[filesize] = '\0'; // Null-terminate the string
    fclose(file);
    
    return buffer;
}

// Function to write the encrypted data to file
int writeFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return -1;
    }
    
    fwrite(data, sizeof(char), strlen(data), file);
    fclose(file);
    
    return 0;
}

// Main function to handle command line arguments and execute encryption
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }
    
    const char *inputFilename = argv[1];
    const char *outputFilename = argv[2];
    const char *key = argv[3];

    // Read file contents
    char *fileContents = readFile(inputFilename);
    if (!fileContents) {
        return 1;
    }

    // Encrypt the contents
    encryptDecrypt(fileContents, key);

    // Write encrypted contents to output file
    if (writeFile(outputFilename, fileContents) == -1) {
        free(fileContents);
        return 1;
    }

    printf("File encrypted successfully and saved as %s\n", outputFilename);
    
    // Free the allocated memory
    free(fileContents);
    
    return 0;
}