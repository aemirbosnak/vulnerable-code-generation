//FormAI DATASET v1.0 Category: File Encyptor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void encrypt_file(char *filename, char *key) {
    FILE *file = fopen(filename, "rb+");
    if (!file) {
        printf("Error: File '%s' not found!\n", filename);
        exit(-1);
    }

    int len = strlen(key);
    int key_sum = 0;
    for (int i = 0; i < len; i++) {
        key_sum += key[i];
    }

    unsigned int seed = key_sum * len;
    int file_size;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    char *buffer = malloc(sizeof(char) * file_size);
    fread(buffer, sizeof(char), file_size, file);

    for (int i = 0; i < file_size; i++) {
        srand(seed);
        buffer[i] = buffer[i] + random_number(1, 10);
        seed += buffer[i];
    }

    rewind(file);
    fwrite(buffer, sizeof(char), file_size, file);
    fclose(file);
    free(buffer);
}

void decrypt_file(char *filename, char *key) {
    FILE *file = fopen(filename, "rb+");
    if (!file) {
        printf("Error: File '%s' not found!\n", filename);
        exit(-1);
    }

    int len = strlen(key);
    int key_sum = 0;
    for (int i = 0; i < len; i++) {
        key_sum += key[i];
    }

    unsigned int seed = key_sum * len;
    int file_size;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    char *buffer = malloc(sizeof(char) * file_size);
    fread(buffer, sizeof(char), file_size, file);

    for (int i = 0; i < file_size; i++) {
        srand(seed);
        buffer[i] = buffer[i] - random_number(1, 10);
        seed += buffer[i];
    }

    rewind(file);
    fwrite(buffer, sizeof(char), file_size, file);
    fclose(file);
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s [encrypt/decrypt] [filename] [key]\n", argv[0]);
        exit(-1);
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        printf("Encrypting file '%s'...\n", argv[2]);
        encrypt_file(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        printf("Decrypting file '%s'...\n", argv[2]);
        decrypt_file(argv[2], argv[3]);
    } else {
        printf("Error: Invalid option '%s'!\n", argv[1]);
        exit(-1);
    }

    printf("Done!\n");
    return 0;
}