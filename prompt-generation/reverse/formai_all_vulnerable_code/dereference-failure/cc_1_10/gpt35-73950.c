//FormAI DATASET v1.0 Category: File Encyptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_KEY_LENGTH 1000

void encryptFile(char *filename, char *key);
void decryptFile(char *filename, char *key);
int getFileSize(FILE *file);

int main() {

    char filename[MAX_FILENAME_LENGTH];
    char key[MAX_KEY_LENGTH];
    int choice;

    printf("Enter the filename to encrypt/decrypt: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    strtok(filename, "\n");

    printf("Enter the encryption/decryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    strtok(key, "\n");

    printf("Choose an option:\n");
    printf("1. Encrypt file\n");
    printf("2. Decrypt file\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encryptFile(filename, key);
            break;
        
        case 2:
            decryptFile(filename, key);
            break;

        default:
            printf("Invalid option\n");
            exit(0);
    }
}

void encryptFile(char *filename, char *key) {

    FILE *input_file;
    FILE *output_file;

    input_file = fopen(filename, "rb");
    output_file = fopen("encrypted.bin", "wb");

    if (input_file == NULL) {
        printf("Cannot open input file\n");
        exit(0);
    }

    if (output_file == NULL) {
        printf("Cannot create encrypted file\n");
        exit(0);
    }

    int size = getFileSize(input_file);
    int key_size = strlen(key);

    fseek(input_file, 0, SEEK_SET);

    int i, j;
    for (i = 0, j = 0; i < size; ++i, ++j) {
        if (j == key_size) j = 0;
        char input_char = fgetc(input_file);
        char key_char = key[j];
        char encrypted_char = input_char ^ key_char;
        fputc(encrypted_char, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File successfully encrypted!\n");
}

void decryptFile(char *filename, char *key) {

    FILE *input_file;
    FILE *output_file;

    input_file = fopen(filename, "rb");
    output_file = fopen("decrypted.bin", "wb");

    if (input_file == NULL) {
        printf("Cannot open input file\n");
        exit(0);
    }

    if (output_file == NULL) {
        printf("Cannot create decrypted file\n");
        exit(0);
    }

    int size = getFileSize(input_file);
    int key_size = strlen(key);

    fseek(input_file, 0, SEEK_SET);

    int i, j;
    for (i = 0, j = 0; i < size; ++i, ++j) {
        if (j == key_size) j = 0;
        char input_char = fgetc(input_file);
        char key_char = key[j];
        char decrypted_char = input_char ^ key_char;
        fputc(decrypted_char, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File successfully decrypted!\n");
}

int getFileSize(FILE *file) {

    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    return size;
}