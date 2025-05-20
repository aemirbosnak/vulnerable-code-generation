//FormAI DATASET v1.0 Category: File Encyptor ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(FILE*, FILE*, char*);
void decrypt(FILE*, FILE*, char*);

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s [encrypt/decrypt] [input_file] [output_file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* key = "futuristic123!"; // Encryption key

    FILE* input = fopen(argv[2], "rb"); // Input file
    if (input == NULL) {
        printf("Failed to open input file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    FILE* output = fopen(argv[3], "wb"); // Output file
    if (output == NULL) {
        printf("Failed to open output file %s\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(input, output, key);
        printf("Encryption complete\n");
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(input, output, key);
        printf("Decryption complete\n");
    } else {
        printf("Invalid operation %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    fclose(input);
    fclose(output);

    return 0;
}

void encrypt(FILE* input, FILE* output, char* key) {
    int key_length = strlen(key);
    int input_byte, key_byte_index = 0;

    while ((input_byte = fgetc(input)) != EOF) {
        fputc(input_byte ^ key[key_byte_index], output); // XOR operation
        key_byte_index = (key_byte_index + 1) % key_length; // Move to next key byte
    }
}

void decrypt(FILE* input, FILE* output, char* key) {
    encrypt(input, output, key); // Decryption is just encryption with same key
}