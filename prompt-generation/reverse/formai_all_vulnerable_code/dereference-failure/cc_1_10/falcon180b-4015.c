//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 32
#define MAX_FILE_NAME_SIZE 1024

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
} encryption_key;

void generate_key(encryption_key *key) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int charset_size = strlen(charset);

    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        key->key[i] = charset[rand() % charset_size];
    }

    key->key_size = MAX_KEY_SIZE;
}

void encrypt_file(encryption_key *key, char *input_file, char *output_file) {
    FILE *input_fp = fopen(input_file, "rb");
    FILE *output_fp = fopen(output_file, "wb");

    if (input_fp == NULL || output_fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char buffer[1024];
    int buffer_size;

    while ((buffer_size = fread(buffer, 1, sizeof(buffer), input_fp)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            buffer[i] ^= key->key[i % key->key_size];
        }

        fwrite(buffer, 1, buffer_size, output_fp);
    }

    fclose(input_fp);
    fclose(output_fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s input_file output_file key_file key_size\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *key_file = argv[3];
    int key_size = atoi(argv[4]);

    encryption_key key;
    generate_key(&key);

    FILE *key_fp = fopen(key_file, "wb");
    if (key_fp == NULL) {
        printf("Error opening key file.\n");
        return 1;
    }

    fwrite(&key, sizeof(encryption_key), 1, key_fp);
    fclose(key_fp);

    encrypt_file(&key, input_file, output_file);

    return 0;
}