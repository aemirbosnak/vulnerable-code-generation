//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY "Enclave"
#define BLOCK_SIZE 8

void encrypt(FILE *input, FILE *output) {
    char buffer[BLOCK_SIZE];
    char keybuffer[BLOCK_SIZE];
    int i, j;

    for (i = 0; i < BLOCK_SIZE; i++) {
        keybuffer[i] = KEY[i % strlen(KEY)];
    }

    while (fread(buffer, sizeof(char), BLOCK_SIZE, input)!= 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] ^= keybuffer[i];
        }
        fwrite(buffer, sizeof(char), BLOCK_SIZE, output);
    }
}

void decrypt(FILE *input, FILE *output) {
    char buffer[BLOCK_SIZE];
    char keybuffer[BLOCK_SIZE];
    int i, j;

    for (i = 0; i < BLOCK_SIZE; i++) {
        keybuffer[i] = KEY[i % strlen(KEY)];
    }

    while (fread(buffer, sizeof(char), BLOCK_SIZE, input)!= 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] ^= keybuffer[i];
        }
        fwrite(buffer, sizeof(char), BLOCK_SIZE, output);
    }
}

int main(int argc, char *argv[]) {
    FILE *input, *output;
    char mode;
    time_t now;

    srand(time(&now));

    if (argc!= 4) {
        printf("Usage: %s [e|d] input_file output_file\n", argv[0]);
        return 1;
    }

    mode = argv[1][0];

    input = fopen(argv[2], "rb");
    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    output = fopen(argv[3], "wb");
    if (output == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input);
        return 1;
    }

    if (mode == 'e') {
        encrypt(input, output);
        printf("File encrypted successfully.\n");
    } else if (mode == 'd') {
        decrypt(input, output);
        printf("File decrypted successfully.\n");
    } else {
        printf("Error: Invalid mode.\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    fclose(input);
    fclose(output);
    return 0;
}