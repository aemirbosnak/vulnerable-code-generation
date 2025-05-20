//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 10000000
#define KEY_SIZE 16

typedef struct {
    FILE* file;
    char* key;
    int file_size;
    int key_index;
} FileEncryptor;

void init_encryptor(FileEncryptor* encryptor, char* key) {
    encryptor->file = NULL;
    encryptor->key = key;
    encryptor->file_size = 0;
    encryptor->key_index = 0;
}

int read_file(char* filename, FileEncryptor* encryptor) {
    encryptor->file = fopen(filename, "rb");
    if (encryptor->file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    fseek(encryptor->file, 0, SEEK_END);
    encryptor->file_size = ftell(encryptor->file);
    rewind(encryptor->file);

    return 0;
}

int encrypt_file(char* filename, char* key) {
    FileEncryptor encryptor;
    init_encryptor(&encryptor, key);

    if (read_file(filename, &encryptor)!= 0) {
        return 1;
    }

    char buffer[MAX_FILE_SIZE];
    char encrypted_buffer[MAX_FILE_SIZE];
    int buffer_size;

    while ((buffer_size = fread(buffer, 1, MAX_FILE_SIZE, encryptor.file)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            encrypted_buffer[i] = buffer[i] ^ encryptor.key[encryptor.key_index % KEY_SIZE];
            encryptor.key_index++;
        }

        fwrite(encrypted_buffer, 1, buffer_size, encryptor.file);
    }

    fclose(encryptor.file);
    return 0;
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <file> <key>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    char* key = argv[2];

    time_t now = time(NULL);
    srand(now);

    char* generated_key = malloc(KEY_SIZE * sizeof(char));
    for (int i = 0; i < KEY_SIZE; i++) {
        generated_key[i] = rand() % 26 + 'a';
    }

    printf("Generated key: %s\n", generated_key);
    encrypt_file(filename, generated_key);

    free(generated_key);
    return 0;
}