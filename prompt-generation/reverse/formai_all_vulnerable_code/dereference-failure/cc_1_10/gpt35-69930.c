//FormAI DATASET v1.0 Category: File Encyptor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char* filename, char* key) {
    FILE* fp_read;
    FILE* fp_write;
    char* buffer;
    int key_len, buffer_len, i, j;
    char* encrypted_filename = malloc(strlen(filename) + 10);
    sprintf(encrypted_filename, "encrypted_%s", filename);
    fp_read = fopen(filename, "rb");
    fp_write = fopen(encrypted_filename, "wb");
    fseek(fp_read, 0, SEEK_END);
    buffer_len = ftell(fp_read);
    rewind(fp_read);
    buffer = malloc(buffer_len);
    fread(buffer, 1, buffer_len, fp_read);
    key_len = strlen(key);
    for (i = 0, j = 0; i < buffer_len; ++i, j = (j + 1) % key_len) {
        buffer[i] ^= key[j];
    }
    fwrite(buffer, 1, buffer_len, fp_write);
    fclose(fp_read);
    fclose(fp_write);
    free(buffer);
}

void decrypt(char* filename, char* key) {
    FILE* fp_read;
    FILE* fp_write;
    char* buffer;
    int key_len, buffer_len, i, j;
    char* decrypted_filename = malloc(strlen(filename) + 10);
    sprintf(decrypted_filename, "decrypted_%s", filename);
    fp_read = fopen(filename, "rb");
    fp_write = fopen(decrypted_filename, "wb");
    fseek(fp_read, 0, SEEK_END);
    buffer_len = ftell(fp_read);
    rewind(fp_read);
    buffer = malloc(buffer_len);
    fread(buffer, 1, buffer_len, fp_read);
    key_len = strlen(key);
    for (i = 0, j = 0; i < buffer_len; ++i, j = (j + 1) % key_len) {
        buffer[i] ^= key[j];
    }
    fwrite(buffer, 1, buffer_len, fp_write);
    fclose(fp_read);
    fclose(fp_write);
    free(buffer);
}

int main(int argc, char** argv) {
    char* filename;
    char* key;
    int len_key;
    if (argc != 4) {
        printf("Usage: %s [encrypt/decrypt] [filename] [key]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    filename = argv[2];
    if (!strstr(filename, ".c")) {
        printf("Error: You can only encrypt/decrypt .c files.\n");
        exit(EXIT_FAILURE);
    }
    key = argv[3];
    len_key = strlen(key);
    if (len_key < 8) {
        printf("Error: The key must be at least 8 characters long.\n");
        exit(EXIT_FAILURE);
    }
    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(filename, key);
        printf("The file %s has been encrypted.\n", filename);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(filename, key);
        printf("The file %s has been decrypted.\n", filename);
    } else {
        printf("Error: You must specify whether you want to encrypt or decrypt.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}