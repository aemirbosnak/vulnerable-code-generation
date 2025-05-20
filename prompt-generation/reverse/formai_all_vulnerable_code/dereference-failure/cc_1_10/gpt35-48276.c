//FormAI DATASET v1.0 Category: File Encyptor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        printf("Error opening input file!\n");
        exit(EXIT_FAILURE);
    }

    FILE *output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        printf("Error opening output file!\n");
        exit(EXIT_FAILURE);
    }

    // Generate key
    char key = 'a';

    // Get initial position
    long initial_position = ftell(input_fp);

    // Read file and encrypt
    char buffer[BUFFER_SIZE];
    size_t size = 0;
    while ((size = fread(buffer, sizeof(char), BUFFER_SIZE, input_fp)) > 0) {
        for (int i = 0; i < size; i++) {
            buffer[i] = buffer[i] ^ key;
        }
        fwrite(buffer, sizeof(char), size, output_fp);
    }

    // Set position back to initial
    fseek(input_fp, initial_position, SEEK_SET);

    // Verify decryption
    fseek(output_fp, 0, SEEK_SET);
    while ((size = fread(buffer, sizeof(char), BUFFER_SIZE, output_fp)) > 0) {
        for (int i = 0; i < size; i++) {
            buffer[i] = buffer[i] ^ key;
        }
        fwrite(buffer, sizeof(char), size, input_fp);        
    }

    // Close files
    fclose(input_fp);
    fclose(output_fp);

    printf("Encryption complete!\n");

    return 0;
}