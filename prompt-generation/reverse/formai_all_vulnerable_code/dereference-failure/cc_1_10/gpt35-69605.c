//FormAI DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define KEY_LEN 8
#define BUF_SIZE 1024

void encrypt(FILE* input, FILE* output, char* key) {
    char buf[BUF_SIZE];
    size_t key_len = strlen(key);
    size_t i = 0;

    while (!feof(input)) {
        size_t bytes_read = fread(buf, 1, BUF_SIZE, input);

        for (size_t j = 0; j < bytes_read; j++) {
            buf[j] ^= key[i];
            i = (i + 1) % key_len;
        }

        fwrite(buf, 1, bytes_read, output);
    }
}

int main(int argc, const char* argv[]) {
    char input_filename[MAX_FILENAME_LEN];
    char output_filename[MAX_FILENAME_LEN];
    char key[KEY_LEN + 1];

    if (argc != 4) {
        fprintf(stderr, "Usage: %s input_file output_file key\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strncpy(input_filename, argv[1], MAX_FILENAME_LEN);
    strncpy(output_filename, argv[2], MAX_FILENAME_LEN);
    strncpy(key, argv[3], KEY_LEN);
    key[KEY_LEN] = '\0';

    FILE* input = fopen(input_filename, "rb");
    FILE* output = fopen(output_filename, "wb");

    if (input == NULL) {
        perror("Could not open input file");
        exit(EXIT_FAILURE);
    }

    if (output == NULL) {
        perror("Could not open output file");
        exit(EXIT_FAILURE);
    }

    encrypt(input, output, key);

    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}