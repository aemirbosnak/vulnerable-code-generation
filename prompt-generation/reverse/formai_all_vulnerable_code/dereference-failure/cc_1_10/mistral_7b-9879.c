//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_SIZE (1024 * 1024)
#define KEY_SIZE 256

void generate_key(unsigned char *key) {
    for (size_t i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt_file(const char *input_file, const char *output_file, const unsigned char *key) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[FILE_SIZE];
    unsigned char encrypted_buffer[FILE_SIZE];

    srand(time(NULL));
    generate_key(key);

    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(unsigned char), FILE_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            encrypted_buffer[i] = buffer[i] ^ key[i % KEY_SIZE];
        }
        fwrite(encrypted_buffer, sizeof(unsigned char), bytes_read, output);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    encrypt_file(argv[1], argv[2], calloc(KEY_SIZE, sizeof(unsigned char)));
    free(calloc(KEY_SIZE, sizeof(unsigned char)));

    printf("File encrypted successfully.\n");
    return EXIT_SUCCESS;
}