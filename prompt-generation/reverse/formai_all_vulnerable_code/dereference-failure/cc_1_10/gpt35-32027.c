//FormAI DATASET v1.0 Category: File Encyptor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "my_secret_key"

void encrypt_file(char* file_path);
void decrypt_file(char* file_path);
void encrypt_content(unsigned char* content, int size);
void decrypt_content(unsigned char* content, int size);
unsigned char* read_file(char* file_path, int* size);
void write_file(char* file_path, unsigned char* content, int size);

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: ./encrypt <file_path>\n");
        return 1;
    }

    char* file_path = argv[1];
    int len = strlen(file_path);

    if(len < 4) {
        printf("Invalid file path\n");
        return 1;
    }

    char* ext = &file_path[len-3];
    if(strcmp(ext, ".py") != 0 && strcmp(ext, ".txt") != 0) {
        printf("Only .py and .txt files are supported\n");
        return 1;
    }

    char mode;
    printf("Enter mode (e for encrypt and d for decrypt): ");
    scanf(" %c", &mode);

    switch(mode) {
        case 'e':
            encrypt_file(file_path);
            break;

        case 'd':
            decrypt_file(file_path);
            break;

        default:
            printf("Invalid mode\n");
            return 1;
    }

    return 0;
}

void encrypt_file(char* file_path) {
    int size;
    unsigned char* content = read_file(file_path, &size);
    encrypt_content(content, size);
    write_file(file_path, content, size);
}

void decrypt_file(char* file_path) {
    int size;
    unsigned char* content = read_file(file_path, &size);
    decrypt_content(content, size);
    write_file(file_path, content, size);
}

void encrypt_content(unsigned char* content, int size) {
    int key_len = strlen(KEY);
    for(int i = 0; i < size; i++) {
        content[i] = (content[i] + KEY[i % key_len]) % 256;
    }
}

void decrypt_content(unsigned char* content, int size) {
    int key_len = strlen(KEY);
    for(int i = 0; i < size; i++) {
        content[i] = (content[i] - KEY[i % key_len] + 256) % 256;
    }
}

unsigned char* read_file(char* file_path, int* size) {
    unsigned char* content = NULL;
    FILE* file = fopen(file_path, "rb");

    if(file != NULL) {
        fseek(file, 0, SEEK_END);
        *size = ftell(file);
        fseek(file, 0, SEEK_SET);

        content = (unsigned char*)malloc(*size);
        if(content != NULL) {
            fread(content, sizeof(unsigned char), *size, file);
        }

        fclose(file);
    }

    return content;
}

void write_file(char* file_path, unsigned char* content, int size) {
    FILE* file = fopen(file_path, "wb");

    if(file != NULL) {
        fwrite(content, sizeof(unsigned char), size, file);
        fclose(file);
    }
}