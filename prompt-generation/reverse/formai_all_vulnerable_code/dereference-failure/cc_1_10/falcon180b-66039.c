//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "secret_key"
#define BLOCK_SIZE 16

void encrypt(char *input_file, char *output_file) {
    FILE *input, *output;
    char input_buffer[BLOCK_SIZE], output_buffer[BLOCK_SIZE + 1];
    int input_size, output_size;

    input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        exit(1);
    }

    while ((input_size = fread(input_buffer, 1, BLOCK_SIZE, input)) > 0) {
        for (int i = 0; i < input_size; i++) {
            input_buffer[i] ^= KEY[i % strlen(KEY)];
        }
        fwrite(input_buffer, 1, input_size, output);
    }

    fclose(input);
    fclose(output);
}

void decrypt(char *input_file, char *output_file) {
    FILE *input, *output;
    char input_buffer[BLOCK_SIZE], output_buffer[BLOCK_SIZE + 1];
    int input_size, output_size;

    input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        exit(1);
    }

    while ((input_size = fread(input_buffer, 1, BLOCK_SIZE, input)) > 0) {
        for (int i = 0; i < input_size; i++) {
            input_buffer[i] ^= KEY[i % strlen(KEY)];
        }
        fwrite(input_buffer, 1, input_size, output);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage: %s [encrypt|decrypt] input_file output_file\n", argv[0]);
        return 1;
    }

    char *mode = argv[1];
    char *input_file = argv[2];
    char *output_file = argv[3];

    if (strcmp(mode, "encrypt") == 0) {
        encrypt(input_file, output_file);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt(input_file, output_file);
    } else {
        printf("Invalid mode.\n");
        return 1;
    }

    return 0;
}