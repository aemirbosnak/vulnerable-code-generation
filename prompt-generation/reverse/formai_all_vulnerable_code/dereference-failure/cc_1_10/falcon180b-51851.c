//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 64

// XOR encryption function
void xor_encrypt(char* input_file, char* output_file) {
    FILE *input, *output;
    char input_buffer[BLOCK_SIZE];
    char output_buffer[BLOCK_SIZE];
    char key_buffer[strlen(KEY)];
    int input_size, output_size;

    // Open input and output files
    input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }
    output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    // Read input file into memory
    input_size = fread(input_buffer, sizeof(char), BLOCK_SIZE, input);
    while (input_size > 0) {
        // XOR input buffer with key
        for (int i = 0; i < BLOCK_SIZE; i++) {
            input_buffer[i] ^= KEY[i % strlen(KEY)];
        }
        // Write encrypted buffer to output file
        output_size = fwrite(input_buffer, sizeof(char), BLOCK_SIZE, output);
        if (output_size!= BLOCK_SIZE) {
            printf("Error: could not write encrypted data to output file.\n");
            exit(1);
        }
        // Read next block of input data
        input_size = fread(input_buffer, sizeof(char), BLOCK_SIZE, input);
    }

    // Close input and output files
    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    // Call encryption function
    xor_encrypt(argv[1], argv[2]);

    return 0;
}