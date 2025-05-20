//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_FILE_SIZE 10000

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    int shift;
} encryption_t;

int generate_key(char *key, int key_size) {
    int i;
    for (i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
    return 0;
}

void encrypt_string(char *input, encryption_t *encryption) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            input[i] = (input[i] - 'a' + encryption->shift) % 26 + 'a';
        }
    }
}

void encrypt_file(encryption_t *encryption, FILE *input_file, FILE *output_file) {
    char buffer[MAX_FILE_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, input_file)) > 0) {
        encrypt_string(buffer, encryption);
        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s input_file output_file key_size key\n", argv[0]);
        return 1;
    }
    int key_size = atoi(argv[3]);
    encryption_t encryption;
    generate_key(argv[4], key_size);
    encryption.key_size = key_size;
    encryption.shift = 0;
    for (int i = 0; i < key_size; i++) {
        encryption.shift += argv[4][i] - 'a';
    }
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file\n");
        fclose(input_file);
        return 1;
    }
    encrypt_file(&encryption, input_file, output_file);
    fclose(input_file);
    fclose(output_file);
    return 0;
}