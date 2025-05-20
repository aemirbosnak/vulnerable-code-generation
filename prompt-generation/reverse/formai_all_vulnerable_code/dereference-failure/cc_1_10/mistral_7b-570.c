//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY_SIZE 25

void encrypt(char *input, char *key) {
    int i, j;
    for (i = 0; input[i] != '\0'; i++) {
        j = i % KEY_SIZE;
        input[i] = input[i] ^ key[j];
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <key>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    char *input_buffer = malloc(KEY_SIZE);
    if (input_buffer == NULL) {
        perror("Error allocating memory");
        fclose(input_file);
        return 1;
    }

    char *key = argv[2];
    char *encrypted_buffer = malloc(KEY_SIZE);
    if (encrypted_buffer == NULL) {
        perror("Error allocating memory");
        free(input_buffer);
        fclose(input_file);
        return 1;
    }

    size_t bytes_read;
    while ((bytes_read = fread(input_buffer, 1, KEY_SIZE, input_file)) > 0) {
        encrypt(input_buffer, key);
        fwrite(input_buffer, 1, bytes_read, stdout);
    }

    fclose(input_file);
    free(input_buffer);
    free(key);
    free(encrypted_buffer);

    return 0;
}