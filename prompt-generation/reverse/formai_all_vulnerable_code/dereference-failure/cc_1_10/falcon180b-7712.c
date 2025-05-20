//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "secret_key"
#define BLOCK_SIZE 8

void encrypt(FILE* input_file, FILE* output_file) {
    char input_buffer[BLOCK_SIZE];
    char output_buffer[BLOCK_SIZE + 1];
    int i, j;

    while (fread(input_buffer, sizeof(char), BLOCK_SIZE, input_file)!= 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            input_buffer[i] ^= KEY[i % strlen(KEY)];
        }
        output_buffer[0] = '\0';
        for (i = 0, j = strlen(input_buffer) - 1; i < j; i++, j--) {
            strncat(output_buffer, &input_buffer[i], 1);
            strncat(output_buffer, &input_buffer[j], 1);
        }
        fwrite(output_buffer, sizeof(char), strlen(output_buffer), output_file);
    }
}

void decrypt(FILE* input_file, FILE* output_file) {
    char input_buffer[BLOCK_SIZE];
    char output_buffer[BLOCK_SIZE + 1];
    int i, j;

    while (fread(input_buffer, sizeof(char), BLOCK_SIZE, input_file)!= 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            input_buffer[i] ^= KEY[i % strlen(KEY)];
        }
        output_buffer[0] = '\0';
        for (i = 0, j = strlen(input_buffer) - 1; i < j; i++, j--) {
            strncat(output_buffer, &input_buffer[i], 1);
            strncat(output_buffer, &input_buffer[j], 1);
        }
        fwrite(output_buffer, sizeof(char), strlen(output_buffer), output_file);
    }
}

int main(int argc, char* argv[]) {
    FILE* input_file;
    FILE* output_file;

    if (argc!= 4) {
        printf("Usage: %s [encrypt/decrypt] input_file output_file\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[2], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    output_file = fopen(argv[3], "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(input_file, output_file);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(input_file, output_file);
    } else {
        printf("Invalid operation.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}