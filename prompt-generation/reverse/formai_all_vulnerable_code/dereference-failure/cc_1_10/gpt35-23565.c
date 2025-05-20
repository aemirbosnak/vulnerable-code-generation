//FormAI DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "cyberpunk"

void encrypt(char *filename);
void decrypt(char *filename);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <encrypt/decrypt> <filename>\n", argv[0]);
        return 0;
    }

    char *option = argv[1];
    char *filename = argv[2];

    if (strcmp(option, "encrypt") == 0) {
        printf("Encrypting file %s...\n", filename);
        encrypt(filename);
    } else if (strcmp(option, "decrypt") == 0) {
        printf("Decrypting file %s...\n", filename);
        decrypt(filename);
    } else {
        printf("Invalid option!\n");
        return 0;
    }

    return 0;
}

void encrypt(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Failed to open file!\n");
        return;
    }

    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char *buffer = malloc(size);
    fread(buffer, size, 1, fp);

    for (int i = 0; i < size; i++) {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    fclose(fp);

    fp = fopen(filename, "wb");
    fwrite(buffer, size, 1, fp);
    fclose(fp);

    printf("Encryption complete!\n");
}

void decrypt(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Failed to open file!\n");
        return;
    }

    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char *buffer = malloc(size);
    fread(buffer, size, 1, fp);

    for (int i = 0; i < size; i++) {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    fclose(fp);

    fp = fopen(filename, "wb");
    fwrite(buffer, size, 1, fp);
    fclose(fp);

    printf("Decryption complete!\n");
}