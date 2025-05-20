//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *filename;
    char *key;
    char *encrypted;
} FileData;

void generate_key(char *key, int length) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        key[i] = chars[rand() % strlen(chars)];
    }
    key[length] = '\0';
}

void encrypt_file(FileData *file_data) {
    FILE *input_file = fopen(file_data->filename, "rb");
    if (input_file == NULL) {
        printf("Error opening file: %s\n", file_data->filename);
        exit(1);
    }

    FILE *output_file = fopen(file_data->encrypted, "wb");
    if (output_file == NULL) {
        printf("Error creating output file: %s\n", file_data->encrypted);
        exit(1);
    }

    char key[32];
    generate_key(key, 32);

    int buffer_size = 1024;
    unsigned char buffer[buffer_size];
    unsigned char encrypted_buffer[buffer_size];

    while (fread(buffer, 1, buffer_size, input_file) > 0) {
        int buffer_length = fwrite(encrypted_buffer, 1, buffer_size, output_file);
        for (int i = 0; i < buffer_length; i++) {
            encrypted_buffer[i] ^= key[i % 32];
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s filename key encrypted_filename\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    char *key = argv[2];
    char *encrypted_filename = argv[3];

    FileData file_data;
    file_data.filename = filename;
    file_data.key = key;
    file_data.encrypted = encrypted_filename;

    encrypt_file(&file_data);

    printf("File encrypted successfully!\n");

    return 0;
}