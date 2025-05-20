//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    FILE *input_file;
    FILE *output_file;
} Encryptor;

void generate_random_key(char *key, int key_size) {
    const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < key_size; i++) {
        key[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    key[key_size] = '\0';
}

Encryptor *create_encryptor(char *input_file_path, char *output_file_path, char *key) {
    Encryptor *encryptor = (Encryptor *) malloc(sizeof(Encryptor));
    encryptor->key_size = strlen(key);
    strcpy(encryptor->key, key);
    encryptor->input_file = fopen(input_file_path, "rb");
    encryptor->output_file = fopen(output_file_path, "wb");
    if (encryptor->input_file == NULL || encryptor->output_file == NULL) {
        fprintf(stderr, "Error: Failed to open file(s).\n");
        exit(EXIT_FAILURE);
    }
    return encryptor;
}

void destroy_encryptor(Encryptor *encryptor) {
    fclose(encryptor->input_file);
    fclose(encryptor->output_file);
    free(encryptor);
}

void encrypt_file(Encryptor *encryptor) {
    char buffer[MAX_FILE_SIZE];
    int buffer_size;
    while ((buffer_size = fread(buffer, sizeof(char), MAX_FILE_SIZE, encryptor->input_file)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            buffer[i] ^= encryptor->key[i % encryptor->key_size];
        }
        fwrite(buffer, sizeof(char), buffer_size, encryptor->output_file);
    }
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s input_file output_file key\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *input_file_path = argv[1];
    char *output_file_path = argv[2];
    char *key = argv[3];
    if (strlen(key) == 0) {
        generate_random_key(key, MAX_KEY_SIZE);
        fprintf(stdout, "Generated key: %s\n", key);
    }
    Encryptor *encryptor = create_encryptor(input_file_path, output_file_path, key);
    encrypt_file(encryptor);
    destroy_encryptor(encryptor);
    return 0;
}