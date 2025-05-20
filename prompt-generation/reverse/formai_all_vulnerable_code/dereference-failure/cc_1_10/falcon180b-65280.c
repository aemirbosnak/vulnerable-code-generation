//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_FILE_SIZE 1000000

typedef struct {
    char key[MAX_KEY_SIZE];
    FILE *file;
} FileEncryptor;

void generate_key(char *key, int key_size) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < key_size; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
}

void encrypt_file(FileEncryptor *encryptor) {
    char buffer[1024];
    char *key = encryptor->key;
    char *input_file = "input.txt";
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen("output.enc", "wb");

    if (input == NULL || output == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int key_index = 0;
    while (fread(buffer, 1, sizeof(buffer), input) > 0) {
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] ^= key[key_index];
            key_index = (key_index + 1) % strlen(key);
        }
        fwrite(buffer, 1, strlen(buffer), output);
    }

    fclose(input);
    fclose(output);
}

int main() {
    char input_file[] = "input.txt";
    char output_file[] = "output.enc";
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    FileEncryptor encryptor;
    generate_key(encryptor.key, MAX_KEY_SIZE);
    encryptor.file = input;

    encrypt_file(&encryptor);

    fclose(input);
    fclose(output);
    return 0;
}