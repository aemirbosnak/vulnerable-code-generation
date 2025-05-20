//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16 // Length of the encryption key
#define BLOCK_SIZE 8 // Size of each block of data to be encrypted

int generate_key(char* key) {
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a'; // Generate a random lowercase letter
    }
    return 0;
}

void encrypt(char* input_file, char* output_file, char* key) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char buffer[BLOCK_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, BLOCK_SIZE, input)) > 0) {
        int j;
        for (j = 0; j < bytes_read; j++) {
            buffer[j] ^= key[j % KEY_LENGTH]; // XOR each byte with a corresponding byte from the key
        }
        fwrite(buffer, 1, bytes_read, output);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key_file\n", argv[0]);
        return 1;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];
    char* key_file = argv[3];

    char key[KEY_LENGTH];
    generate_key(key);

    FILE* key_stream = fopen(key_file, "wb");
    if (key_stream == NULL) {
        printf("Error: Could not open key file.\n");
        return 1;
    }

    fwrite(key, 1, KEY_LENGTH, key_stream);
    fclose(key_stream);

    encrypt(input_file, output_file, key);

    return 0;
}