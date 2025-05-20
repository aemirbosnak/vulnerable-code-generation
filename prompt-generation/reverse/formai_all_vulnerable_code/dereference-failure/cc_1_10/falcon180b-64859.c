//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 256
#define MAX_FILE_NAME_SIZE 1024
#define MAX_FILE_SIZE (1024 * 1024 * 1024)

typedef struct {
    char key[MAX_KEY_SIZE];
    char file_name[MAX_FILE_NAME_SIZE];
    char encrypted_file_name[MAX_FILE_NAME_SIZE];
} Encryptor;

void generate_key(Encryptor *encryptor) {
    char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        encryptor->key[i] = letters[rand() % strlen(letters)];
    }
    encryptor->key[MAX_KEY_SIZE - 1] = '\0';
}

void encrypt_file(Encryptor *encryptor) {
    FILE *input_file = fopen(encryptor->file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    FILE *output_file = fopen(encryptor->encrypted_file_name, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    char buffer[1024];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        int i;
        for (i = 0; i < bytes_read; i++) {
            char c = buffer[i];
            c = c ^ encryptor->key[i % MAX_KEY_SIZE];
            fwrite(&c, 1, 1, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        exit(1);
    }

    Encryptor encryptor;
    strcpy(encryptor.file_name, argv[1]);
    strcpy(encryptor.encrypted_file_name, argv[2]);
    strcpy(encryptor.key, argv[3]);

    generate_key(&encryptor);
    encrypt_file(&encryptor);

    printf("File encrypted successfully.\n");
    return 0;
}