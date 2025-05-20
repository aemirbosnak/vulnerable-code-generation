//FormAI DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "verysecretkey"

void xor_encrypt(char *input, char *output, char *key) {
    size_t input_length = strlen(input);
    size_t key_length = strlen(key);

    for (int i = 0; i < input_length; i++) {
        output[i] = input[i] ^ key[i % key_length];
    }
}

void encrypt_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: could not open file\n");
        return;
    }

    long file_size;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    char *buffer = malloc(file_size);
    fread(buffer, 1, file_size, file);
    fclose(file);

    char *encrypted_buffer = malloc(file_size);
    xor_encrypt(buffer, encrypted_buffer, KEY);

    file = fopen(filename, "wb");
    fwrite(encrypted_buffer, 1, file_size, file);
    fclose(file);

    free(buffer);
    free(encrypted_buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: no filename provided\n");
        return 1;
    }

    char *filename = argv[1];
    encrypt_file(filename);

    printf("File encrypted successfully!\n");
    return 0;
}