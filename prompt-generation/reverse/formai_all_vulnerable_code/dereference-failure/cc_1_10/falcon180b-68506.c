//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16

typedef struct {
    char filename[100];
    char encrypted_filename[100];
} File;

typedef struct {
    unsigned char key[KEY_SIZE];
    int index;
} Key;

void generate_key(Key *key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key->key[i] = rand() % 256;
    }
    key->index = 0;
}

void encrypt_file(File *file, Key *key) {
    FILE *input_file = fopen(file->filename, "rb");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", file->filename);
        exit(1);
    }

    FILE *output_file = fopen(file->encrypted_filename, "wb");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", file->encrypted_filename);
        exit(1);
    }

    unsigned char input_buffer[1024];
    unsigned char output_buffer[1024];
    while (1) {
        int bytes_read = fread(input_buffer, 1, 1024, input_file);
        if (bytes_read == 0) {
            break;
        }

        for (int i = 0; i < bytes_read; i++) {
            output_buffer[i] = input_buffer[i] ^ key->key[key->index];
            key->index = (key->index + 1) % KEY_SIZE;
        }

        fwrite(output_buffer, 1, bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    File file;
    strcpy(file.filename, argv[1]);
    strcat(file.encrypted_filename, ".enc");

    Key key;
    generate_key(&key);

    encrypt_file(&file, &key);

    printf("File encrypted successfully.\n");

    return 0;
}