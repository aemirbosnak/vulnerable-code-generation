//FormAI DATASET v1.0 Category: File Encyptor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 1024

void encrypt_file(char *filename, char *key);
void decrypt_file(char *filename, char *key);
void encode(char *buffer, char *key);
void decode(char *buffer, char *key);

int main(int argc, char *argv[]) {

    char filename[MAX_FILENAME_LENGTH], key[BUFFER_SIZE];
    int action;

    if(argc < 4) {
        printf("Usage: program_name <file_name> <key> <action>\n");
        printf("Action: 1 - Encrypt, 2 - Decrypt\n");
        return 1;
    }

    strcpy(filename, argv[1]);
    strcpy(key, argv[2]);
    action = atoi(argv[3]);

    switch(action) {
        case 1:
            printf("Encrypting file %s...\n", filename);
            encrypt_file(filename, key);
            printf("File encrypted successfully!\n");
            break;
        case 2:
            printf("Decrypting file %s...\n", filename);
            decrypt_file(filename, key);
            printf("File decrypted successfully!\n");
            break;
        default:
            printf("Invalid action specified!\n");
            return 2;
    }

    return 0;
}

void encrypt_file(char *filename, char *key) {
    FILE *input_file, *output_file;
    char buffer[BUFFER_SIZE];
    int read_bytes;

    input_file = fopen(filename, "rb");
    output_file = fopen(strcat(filename, ".enc"), "wb");

    while ((read_bytes = fread(buffer, sizeof(char), BUFFER_SIZE, input_file)) > 0) {
        encode(buffer, key);
        fwrite(buffer, sizeof(char), read_bytes, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void decrypt_file(char *filename, char *key) {
    FILE *input_file, *output_file;
    char buffer[BUFFER_SIZE];
    int read_bytes;

    input_file = fopen(filename, "rb");
    output_file = fopen(strcat(filename, ".dec"), "wb");

    while ((read_bytes = fread(buffer, sizeof(char), BUFFER_SIZE, input_file)) > 0) {
        decode(buffer, key);
        fwrite(buffer, sizeof(char), read_bytes, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void encode(char *buffer, char *key) {
    int key_len = strlen(key);
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = buffer[i] ^ key[i % key_len];
    }
}

void decode(char *buffer, char *key) {
    int key_len = strlen(key);
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = buffer[i] ^ key[i % key_len];
    }
}