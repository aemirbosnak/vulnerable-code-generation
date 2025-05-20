//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define KEY_LENGTH 32
#define BLOCK_SIZE 16

typedef struct {
    char key[KEY_LENGTH];
    int num_rounds;
} encryption_params;

void generate_key(char* key, int key_length) {
    time_t t;
    srand(time(&t));
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the file to encrypt: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    char* file_buffer = malloc(file_size);
    fread(file_buffer, file_size, 1, file);
    fclose(file);

    printf("Enter the encryption key: ");
    char key[KEY_LENGTH];
    scanf("%s", key);

    encryption_params params;
    generate_key(params.key, KEY_LENGTH);
    params.num_rounds = atoi(key);

    char encrypted_file_name[100];
    strcpy(encrypted_file_name, filename);
    strcat(encrypted_file_name, ".enc");

    FILE* encrypted_file = fopen(encrypted_file_name, "wb");
    if (encrypted_file == NULL) {
        printf("Error: Could not open encrypted file.\n");
        exit(1);
    }

    char* encrypted_buffer = malloc(file_size);

    for (int i = 0; i < file_size; i += BLOCK_SIZE) {
        int block_size = (i + BLOCK_SIZE > file_size)? file_size - i : BLOCK_SIZE;
        char block[BLOCK_SIZE];
        memcpy(block, file_buffer + i, block_size);

        for (int j = 0; j < params.num_rounds; j++) {
            for (int k = 0; k < block_size; k++) {
                block[k] = toupper(block[k]) ^ params.key[j % KEY_LENGTH];
            }
        }

        memcpy(encrypted_buffer + i, block, block_size);
    }

    fwrite(encrypted_buffer, file_size, 1, encrypted_file);
    fclose(encrypted_file);

    printf("File encrypted successfully.\n");

    return 0;
}