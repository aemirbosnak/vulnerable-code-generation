//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_KEY_LEN 32
#define MAX_FILE_SIZE (1 << 20) // 1 MB

void encrypt_file(const char *filename, const char *key) {
    FILE *fin, *fout;
    uint8_t buf[MAX_FILE_SIZE];
    int32_t key_len = strlen(key);
    uint32_t key_mask = (1 << key_len) - 1;
    int32_t pos = 0;

    fin = fopen(filename, "rb");
    if (!fin) {
        perror("fopen");
        return;
    }

    fout = fopen("encrypted.dat", "wb");
    if (!fout) {
        perror("fopen");
        fclose(fin);
        return;
    }

    while (!feof(fin)) {
        size_t bytes_read = fread(buf, 1, MAX_FILE_SIZE, fin);
        for (int32_t i = 0; i < bytes_read; i++) {
            buf[i] ^= key[pos & key_mask];
            pos++;
        }
        fwrite(buf, 1, bytes_read, fout);
    }

    fclose(fin);
    fclose(fout);
}

void decrypt_file(const char *filename, const char *key) {
    FILE *fin, *fout;
    uint8_t buf[MAX_FILE_SIZE];
    int32_t key_len = strlen(key);
    uint32_t key_mask = (1 << key_len) - 1;
    int32_t pos = 0;

    fin = fopen(filename, "rb");
    if (!fin) {
        perror("fopen");
        return;
    }

    fout = fopen("decrypted.dat", "wb");
    if (!fout) {
        perror("fopen");
        fclose(fin);
        return;
    }

    while (!feof(fin)) {
        size_t bytes_read = fread(buf, 1, MAX_FILE_SIZE, fin);
        for (int32_t i = 0; i < bytes_read; i++) {
            buf[i] ^= key[pos & key_mask];
            pos++;
        }
        fwrite(buf, 1, bytes_read, fout);
    }

    fclose(fin);
    fclose(fout);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s [encrypt|decrypt] [filename] [key]\n", argv[0]);
        return 1;
    }

    const char *op = argv[1];
    const char *filename = argv[2];
    const char *key = argv[3];

    if (strcmp(op, "encrypt") == 0) {
        encrypt_file(filename, key);
    } else if (strcmp(op, "decrypt") == 0) {
        decrypt_file(filename, key);
    } else {
        printf("Invalid operation: %s\n", op);
        return 1;
    }

    return 0;
}