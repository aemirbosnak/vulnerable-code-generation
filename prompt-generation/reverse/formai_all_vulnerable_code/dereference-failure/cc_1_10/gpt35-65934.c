//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 16
#define CHUNK_SIZE 1024

typedef unsigned char byte;

void encrypt(FILE* inputFile, FILE* outputFile, char* key) {
    byte chunk[CHUNK_SIZE];
    byte keystream[CHUNK_SIZE];
    byte tempKey[MAX_KEY_SIZE];
    size_t keyIndex, i, j, bytesRead;
    
    // Initialize key variables
    keyIndex = 0;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        tempKey[i] = key[keyIndex];
        keyIndex++;
        if (keyIndex >= strlen(key)) {
            keyIndex = 0;
        }
    }
    memcpy(keystream, tempKey, MAX_KEY_SIZE);
    
    // Process input file in 1KB chunks
    while ((bytesRead = fread(chunk, 1, CHUNK_SIZE, inputFile)) > 0) {
        // Generate keystream for this chunk
        for (i = 0; i < bytesRead; i++) {
            keystream[i] ^= chunk[i];
        }
        
        // Perform XOR encryption
        for (j = 0; j < bytesRead; j++) {
            chunk[j] ^= keystream[j];
        }
        
        // Write encrypted chunk to output file
        fwrite(chunk, 1, bytesRead, outputFile);
    }
    
    // Clean up
    memset(chunk, 0, CHUNK_SIZE);
    memset(keystream, 0, CHUNK_SIZE);
    memset(tempKey, 0, MAX_KEY_SIZE);
}

int main(int argc, char** argv) {
    FILE* inputFile;
    FILE* outputFile;
    char key[MAX_KEY_SIZE];
    
    if (argc != 4) {
        fprintf(stderr, "Usage: %s input-file output-file encryption-key\n", argv[0]);
        return 1;
    }
    
    // Open input and output files
    if ((inputFile = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        return 1;
    }
    
    if ((outputFile = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }
    
    // Copy encryption key
    if (strlen(argv[3]) > MAX_KEY_SIZE) {
        fprintf(stderr, "Error: encryption key too long (max %d)\n", MAX_KEY_SIZE);
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }
    
    strncpy(key, argv[3], MAX_KEY_SIZE);
    
    // Encrypt input file and write to output file
    encrypt(inputFile, outputFile, key);
    
    // Clean up
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}