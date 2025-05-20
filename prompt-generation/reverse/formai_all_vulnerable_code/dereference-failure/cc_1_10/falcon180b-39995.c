//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

typedef struct {
    char key[KEY_LENGTH];
    FILE *file;
} CipherContext;

void generate_key() {
    char key[KEY_LENGTH];
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    printf("Generated key: %s\n", key);
}

void encrypt_file(CipherContext *context) {
    char buffer[BLOCK_SIZE];
    while (fread(buffer, 1, BLOCK_SIZE, context->file) == BLOCK_SIZE) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] ^= context->key[i % KEY_LENGTH];
        }
        fwrite(buffer, 1, BLOCK_SIZE, context->file);
    }
}

void decrypt_file(CipherContext *context) {
    char buffer[BLOCK_SIZE];
    while (fread(buffer, 1, BLOCK_SIZE, context->file) == BLOCK_SIZE) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] ^= context->key[i % KEY_LENGTH];
        }
        fwrite(buffer, 1, BLOCK_SIZE, context->file);
    }
}

int main() {
    CipherContext context;
    printf("Enter filename: ");
    scanf("%s", context.file);
    printf("Enter encryption mode (e/d): ");
    char mode;
    scanf("%c", &mode);
    if (mode == 'e') {
        generate_key();
        strcpy(context.key, "key");
        encrypt_file(&context);
    } else if (mode == 'd') {
        printf("Enter key: ");
        scanf("%s", context.key);
        decrypt_file(&context);
    } else {
        printf("Invalid mode\n");
    }
    fclose(context.file);
    return 0;
}