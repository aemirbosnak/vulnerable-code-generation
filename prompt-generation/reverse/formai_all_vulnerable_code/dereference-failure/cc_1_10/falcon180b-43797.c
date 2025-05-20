//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size is 1MB
#define KEY_SIZE 16 // Key size is 16 bytes (128 bits)

typedef struct {
    char* filename;
    FILE* file;
} FILE_INFO;

typedef struct {
    char* key;
    int key_size;
} KEY_INFO;

void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        char c = (char)rand() % 26 + 'a';
        key[i] = toupper(c);
    }
    key[key_size] = '\0';
}

int encrypt_file(FILE_INFO* file_info, KEY_INFO* key_info) {
    FILE* file = file_info->file;
    char* key = key_info->key;
    int key_size = key_info->key_size;

    char buffer[MAX_FILE_SIZE];
    int buffer_size = 0;

    while ((buffer_size = fread(buffer, 1, MAX_FILE_SIZE, file)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            char c = buffer[i];
            if (isalpha(c)) {
                c = (c - 'a' + (int)key[i % key_size]) % 26 + 'a';
            }
            buffer[i] = c;
        }
        fwrite(buffer, 1, buffer_size, file);
    }

    return 0;
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <key>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    char* key = argv[2];

    FILE* file = fopen(filename, "rb+");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    FILE_INFO file_info = {
       .filename = filename,
       .file = file
    };

    KEY_INFO key_info = {
       .key = key,
       .key_size = strlen(key)
    };

    generate_key(key_info.key, key_info.key_size);

    encrypt_file(&file_info, &key_info);

    fclose(file);

    printf("File encrypted successfully.\n");

    return 0;
}