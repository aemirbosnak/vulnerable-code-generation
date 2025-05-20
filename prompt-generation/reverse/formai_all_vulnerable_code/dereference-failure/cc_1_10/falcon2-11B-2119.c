//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY 3

// Encrypts a string using a simple Caesar cipher algorithm
char* encrypt(char* str, int key) {
    int len = strlen(str);
    char* cipher = (char*)malloc(len + 1);
    int i;
    for (i = 0; i < len; i++) {
        cipher[i] = (char)(str[i] + key);
    }
    cipher[len] = '\0';
    return cipher;
}

// Decrypts a string using a simple Caesar cipher algorithm
char* decrypt(char* str, int key) {
    int len = strlen(str);
    char* cipher = (char*)malloc(len + 1);
    int i;
    for (i = 0; i < len; i++) {
        cipher[i] = (char)(str[i] - key);
    }
    cipher[len] = '\0';
    return cipher;
}

// Encrypts and decrypts a text file using a simple Caesar cipher algorithm
int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <file> <key>\n", argv[0]);
        return 1;
    }
    FILE* f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    char* buffer = (char*)malloc(4096);
    size_t len = fread(buffer, 1, 4096, f);
    if (feof(f)) {
        printf("Error reading file.\n");
        free(buffer);
        return 1;
    }
    char* encrypted = encrypt(buffer, KEY);
    fclose(f);
    printf("Encrypted: %s\n", encrypted);
    free(buffer);
    buffer = (char*)malloc(len + 1);
    f = fopen(argv[1], "w");
    if (f == NULL) {
        printf("Error opening file.\n");
        free(buffer);
        return 1;
    }
    fwrite(encrypted, 1, len, f);
    fclose(f);
    buffer = (char*)malloc(len + 1);
    f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        free(buffer);
        return 1;
    }
    len = fread(buffer, 1, len, f);
    if (feof(f)) {
        printf("Error reading file.\n");
        free(buffer);
        return 1;
    }
    char* decrypted = decrypt(buffer, KEY);
    printf("Decrypted: %s\n", decrypted);
    free(buffer);
    return 0;
}