//FormAI DATASET v1.0 Category: File Encyptor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

void encrypt(char *file_name, char *key) {
    FILE *file = fopen(file_name, "rb+");
    int key_len = strlen(key);

    if (file == NULL) {
        printf("Unable to open file");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    char *buffer = (char *) malloc(sizeof(char) * MAX_FILE_SIZE);

    if (buffer == NULL) {
        printf("Unable to allocate memory for buffer");
        exit(1);
    }

    fread(buffer, file_size, 1, file);
    fclose(file);

    int i, j = 0, len = strlen(buffer);

    for (i = 0; i < len - 1; i++, j++) {
        if (j == key_len) {
            j = 0;
        }

        buffer[i] += key[j];
    }

    file = fopen(file_name, "wb+");
    fwrite(buffer, file_size, 1, file);
    fclose(file);

    free(buffer);
}

void decrypt(char *file_name, char *key) {
    FILE *file = fopen(file_name, "rb+");
    int key_len = strlen(key);

    if (file == NULL) {
        printf("Unable to open file");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    char *buffer = (char *) malloc(sizeof(char) * MAX_FILE_SIZE);

    if (buffer == NULL) {
        printf("Unable to allocate memory for buffer");
        exit(1);
    }

    fread(buffer, file_size, 1, file);
    fclose(file);

    int i, j = 0, len = strlen(buffer);

    for (i = 0; i < len - 1; i++, j++) {
        if (j == key_len) {
            j = 0;
        }

        buffer[i] -= key[j];
    }

    file = fopen(file_name, "wb+");
    fwrite(buffer, file_size, 1, file);
    fclose(file);

    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: program.exe <file name> <key> <encrypt/decrypt>\n");
        exit(1);
    }

    char *file_name = argv[1];
    char *key = argv[2];
    char *action = argv[3];

    if (strcmp(action, "encrypt") == 0) {
        encrypt(file_name, key);
        printf("File encrypted successfully!\n");
    } else if (strcmp(action, "decrypt") == 0) {
        decrypt(file_name, key);
        printf("File decrypted successfully!\n");
    } else {
        printf("Invalid action specified. Use 'encrypt' or 'decrypt'\n");
        exit(1);
    }

    return 0;
}