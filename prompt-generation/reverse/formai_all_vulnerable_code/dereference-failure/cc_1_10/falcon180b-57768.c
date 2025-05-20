//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 8

void encrypt(FILE* input, FILE* output) {
    char buffer[BLOCK_SIZE];
    int i = 0;

    while (fread(buffer, sizeof(char), BLOCK_SIZE, input)!= 0) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            buffer[j] ^= KEY[i % strlen(KEY)];
            i++;
        }
        fwrite(buffer, sizeof(char), BLOCK_SIZE, output);
    }
}

void decrypt(FILE* input, FILE* output) {
    char buffer[BLOCK_SIZE];
    int i = 0;

    while (fread(buffer, sizeof(char), BLOCK_SIZE, input)!= 0) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            buffer[j] ^= KEY[i % strlen(KEY)];
            i++;
        }
        fwrite(buffer, sizeof(char), BLOCK_SIZE, output);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s [encrypt|decrypt] input_file output_file\n", argv[0]);
        return 1;
    }

    char* operation = argv[1];
    FILE* input;
    FILE* output;

    if ((input = fopen(argv[2], "rb")) == NULL || (output = fopen(argv[3], "wb")) == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    if (strcmp(operation, "encrypt") == 0) {
        encrypt(input, output);
        printf("File encrypted successfully.\n");
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt(input, output);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid operation.\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    fclose(input);
    fclose(output);
    return 0;
}