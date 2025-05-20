//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY_SIZE 256

void xor_key(unsigned char *data, unsigned char *key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        data[i] ^= key[i % KEY_SIZE];
    }
}

void read_file(const char *filename, unsigned char *buffer, int *length) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    *length = ftell(file);
    rewind(file);
    fread(buffer, 1, *length, file);
    fclose(file);
}

void write_file(const char *filename, unsigned char *buffer, int length) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    fwrite(buffer, 1, length, file);
    fclose(file);
}

void generate_key(unsigned char *key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    unsigned char *input_buffer = NULL;
    unsigned char *output_buffer = NULL;
    int input_length = 0;
    int output_length = 0;

    read_file(argv[1], input_buffer, &input_length);

    unsigned char key[KEY_SIZE];
    generate_key(key);

    output_buffer = malloc(input_length);
    xor_key(output_buffer, key);
    xor_key(input_buffer, key);

    memcpy(output_buffer, input_buffer, input_length);

    write_file(argv[2], output_buffer, input_length);

    free(output_buffer);
    free(input_buffer);

    return 0;
}