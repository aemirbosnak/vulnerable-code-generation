//FormAI DATASET v1.0 Category: Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform XOR encryption
void XOR_encrypt(char* input_file_path, char* key) {
    FILE* input_file = fopen(input_file_path, "rb");

    if (!input_file) {
        printf("Could not open input file %s", input_file_path);
        exit(1);
    }

    // Open output file for writing encrypted data
    char* output_file_path = "output.bin";
    FILE* output_file = fopen(output_file_path, "wb");

    if (!output_file) {
        printf("Could not open output file %s", output_file_path);
        exit(1);
    }

    // Calculate length of key and input file
    size_t key_len = strlen(key);
    fseek(input_file, 0, SEEK_END);
    size_t input_len = ftell(input_file);
    rewind(input_file);

    char* key_stream = (char*)malloc(input_len);

    if (!key_stream) {
        printf("Failed to allocate memory");
        exit(1);
    }

    // Generate key stream
    for (size_t i = 0; i < input_len; i++) {
        key_stream[i] = key[i % key_len];
    }

    // Encrypt input file and write to output file
    char ch;
    size_t i = 0;
    while (fread(&ch, sizeof(char), 1, input_file) == 1) {
        ch ^= key_stream[i++];
        fwrite(&ch, sizeof(char), 1, output_file);
    }

    free(key_stream);
    fclose(input_file);
    fclose(output_file);
}

int main() {
    char* input_file_path = "input.txt";
    char* key = "mySecretKey123";

    XOR_encrypt(input_file_path, key);

    printf("Encryption successful!");
    return 0;
}