//FormAI DATASET v1.0 Category: File Encyptor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt(char *file_path, char *key);
void decrypt(char *file_path, char *key);

int main(int argc, char *argv[]) {
    char *file_path = argv[2];
    char *key = argv[3];

    if (strcmp(argv[1], "-e") == 0) {
        encrypt(file_path, key);
        printf("File encrypted successfully.\n");
    } else if (strcmp(argv[1], "-d") == 0) {
        decrypt(file_path, key);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid argument. Please use either -e to encrypt or -d to decrypt.\n");
    }

    return 0;
}

void encrypt(char *file_path, char *key) {
    FILE *file_in, *file_out;
    char buffer[BUFFER_SIZE];
    int key_length = strlen(key);
    int i, j, b;

    file_in = fopen(file_path, "rb");
    if (file_in == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char *out_file_path = malloc(strlen(file_path) + 5);
    sprintf(out_file_path, "%s.enc", file_path);
    file_out = fopen(out_file_path, "wb");
    if (file_out == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    while ((b = fread(buffer, 1, BUFFER_SIZE, file_in)) > 0) {
        for (i = 0; i < b; i++) {
            buffer[i] = buffer[i] ^ key[i % key_length];
        }

        fwrite(buffer, 1, b, file_out);
    }

    fclose(file_in);
    fclose(file_out);
}

void decrypt(char *file_path, char *key) {
    FILE *file_in, *file_out;
    char buffer[BUFFER_SIZE];
    int key_length = strlen(key);
    int i, j, b;

    file_in = fopen(file_path, "rb");
    if (file_in == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char *out_file_path = malloc(strlen(file_path) + 5);
    strncpy(out_file_path, file_path, strlen(file_path) - 4);
    file_out = fopen(out_file_path, "wb");
    if (file_out == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    while ((b = fread(buffer, 1, BUFFER_SIZE, file_in)) > 0) {
        for (i = 0; i < b; i++) {
            buffer[i] = buffer[i] ^ key[i % key_length];
        }

        fwrite(buffer, 1, b, file_out);
    }

    fclose(file_in);
    fclose(file_out);
}