//FormAI DATASET v1.0 Category: File Encyptor ; Style: safe
#include <stdio.h>
#define MAX_FILE_SIZE 100000
#define MAX_KEY_SIZE 100

void encrypt(char *input_filename, char *output_filename, char *key) {
    FILE *input_file, *output_file;
    char input_buffer[MAX_FILE_SIZE], output_buffer[MAX_FILE_SIZE];
    char key_buffer[MAX_KEY_SIZE];
    int input_size, key_size, i, j = 0;

    input_file = fopen(input_filename, "rb");
    output_file = fopen(output_filename, "wb");

    if (!input_file) {
        printf("Error: could not open input file.\n");
        return;
    }

    if (!output_file) {
        printf("Error: could not create output file.\n");
        return;
    }

    fseek(input_file, 0, SEEK_END);
    input_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    if (input_size >= MAX_FILE_SIZE) {
        printf("Error: input file size too large.\n");
        return;
    }

    key_size = strlen(key);

    if (key_size >= MAX_KEY_SIZE) {
        printf("Error: key size too large.\n");
        return;
    }

    fread(input_buffer, sizeof(char), input_size, input_file);

    for (i = 0; i < input_size; i++) {
        output_buffer[i] = input_buffer[i] ^ key[j];
        j = (j + 1) % key_size;
    }

    fwrite(output_buffer, sizeof(char), input_size, output_file);

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    encrypt(argv[1], argv[2], argv[3]);

    return 0;
}