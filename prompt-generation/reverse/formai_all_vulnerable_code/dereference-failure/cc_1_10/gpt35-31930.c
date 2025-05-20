//FormAI DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024 // Maximum buffer size

void encrypt(FILE *input_file, FILE *output_file, char *key); // Encryption function
void decrypt(FILE *input_file, FILE *output_file, char *key); // Decryption function

int main(int argc, char *argv[]) {

    // Check if enough arguments were given
    if(argc < 4) {
        printf("Usage: %s [encrypt|decrypt] [input_file] [output_file] [key]\n", argv[0]);
        return 1;
    }

    char *action = argv[1]; // Either "encrypt" or "decrypt"
    char *input_filename = argv[2]; // Input file name
    char *output_filename = argv[3]; // Output file name
    char *encryption_key = argv[4]; // Encryption key

    // Check if action is valid
    if(strcmp(action, "encrypt") != 0 && strcmp(action, "decrypt") != 0) {
        printf("Invalid action: %s\n", action);
        return 1;
    }

    // Open input file for reading
    FILE *input_file = fopen(input_filename, "rb");
    if(input_file == NULL) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    // Open output file for writing
    FILE *output_file = fopen(output_filename, "wb");
    if(output_file == NULL) {
        printf("Error: Could not open output file\n");
        return 1;
    }

    // Encrypt or decrypt depending on action
    if(strcmp(action, "encrypt") == 0) {
        encrypt(input_file, output_file, encryption_key);
    } else if(strcmp(action, "decrypt") == 0) {
        decrypt(input_file, output_file, encryption_key);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}

void encrypt(FILE *input_file, FILE *output_file, char *key) {
    unsigned char buffer[MAX_BUFFER_SIZE];
    size_t read_size;

    while((read_size = fread(buffer, 1, MAX_BUFFER_SIZE, input_file)) > 0) {
        for(size_t i = 0; i < read_size; i++) {
            buffer[i] = buffer[i] ^ key[i % strlen(key)];
        }
        fwrite(buffer, 1, read_size, output_file);
    }
}

void decrypt(FILE *input_file, FILE *output_file, char *key) {
    encrypt(input_file, output_file, key);
}