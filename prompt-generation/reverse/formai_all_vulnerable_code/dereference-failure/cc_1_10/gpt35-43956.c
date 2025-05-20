//FormAI DATASET v1.0 Category: File Encyptor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

void encrypt(char *input_filename, char *output_filename, char *key) {
    FILE *input_file = fopen(input_filename, "rb");
    FILE *output_file = fopen(output_filename, "wb");
    char block[BLOCK_SIZE];
    int key_len = strlen(key);
    int i, j;

    while(fread(block, 1, BLOCK_SIZE, input_file) == BLOCK_SIZE) { // Read input file in blocks
        for(i = 0; i < BLOCK_SIZE; i++) { // XOR each byte of block with key
            block[i] ^= key[i % key_len];
        }
        fwrite(block, 1, BLOCK_SIZE, output_file); // Write encrypted block to output file
    }

    // Check for any remaining bytes in input file
    int bytes_left = fread(block, 1, BLOCK_SIZE, input_file);
    if(bytes_left > 0) {
        for(i = 0; i < bytes_left; i++) { // XOR each byte of block with key
            block[i] ^= key[i % key_len];
        }
        fwrite(block, 1, bytes_left, output_file); // Write encrypted block to output file
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);
}

void decrypt(char *input_filename, char *output_filename, char *key) {
    FILE *input_file = fopen(input_filename, "rb");
    FILE *output_file = fopen(output_filename, "wb");
    char block[BLOCK_SIZE];
    int key_len = strlen(key);
    int i, j;

    while(fread(block, 1, BLOCK_SIZE, input_file) == BLOCK_SIZE) { // Read input file in blocks
        for(i = 0; i < BLOCK_SIZE; i++) { // XOR each byte of block with key
            block[i] ^= key[i % key_len];
        }
        fwrite(block, 1, BLOCK_SIZE, output_file); // Write decrypted block to output file
    }

    // Check for any remaining bytes in input file
    int bytes_left = fread(block, 1, BLOCK_SIZE, input_file);
    if(bytes_left > 0) {
        for(i = 0; i < bytes_left; i++) { // XOR each byte of block with key
            block[i] ^= key[i % key_len];
        }
        fwrite(block, 1, bytes_left, output_file); // Write decrypted block to output file
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if(argc != 5) { // Check for correct number of arguments
        printf("Usage: %s -e/-d input_file output_file key\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[2];
    char *output_filename = argv[3];
    char *key = argv[4];

    if(strcmp(argv[1], "-e") == 0) {
        encrypt(input_filename, output_filename, key); // Encrypt input file
        printf("File encrypted successfully\n");
    }
    else if(strcmp(argv[1], "-d") == 0) {
        decrypt(input_filename, output_filename, key); // Decrypt input file
        printf("File decrypted successfully\n");
    }
    else {
        printf("Invalid option: %s\n", argv[1]);
        return 1;
    }

    return 0;
}