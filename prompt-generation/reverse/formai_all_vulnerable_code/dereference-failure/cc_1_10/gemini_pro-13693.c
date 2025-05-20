//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT_KEY 0x12345678

typedef unsigned char byte;

void encrypt_file(const char *file_name) {
    FILE *fin, *fout;
    byte buf[1024];
    size_t nread;
    unsigned int i;

    fin = fopen(file_name, "rb");
    if (fin == NULL) {
        perror(file_name);
        return;
    }

    fout = fopen(strcat(file_name, ".enc"), "wb");
    if (fout == NULL) {
        perror(file_name);
        fclose(fin);
        return;
    }

    while ((nread = fread(buf, 1, sizeof(buf), fin)) > 0) {
        for (i = 0; i < nread; i++) {
            buf[i] ^= ENCRYPT_KEY;
        }
        fwrite(buf, 1, nread, fout);
    }

    fclose(fin);
    fclose(fout);
}

void decrypt_file(const char *file_name) {
    FILE *fin, *fout;
    byte buf[1024];
    size_t nread;
    unsigned int i;

    fin = fopen(file_name, "rb");
    if (fin == NULL) {
        perror(file_name);
        return;
    }

    fout = fopen(strcat(file_name, ".dec"), "wb");
    if (fout == NULL) {
        perror(file_name);
        fclose(fin);
        return;
    }

    while ((nread = fread(buf, 1, sizeof(buf), fin)) > 0) {
        for (i = 0; i < nread; i++) {
            buf[i] ^= ENCRYPT_KEY;
        }
        fwrite(buf, 1, nread, fout);
    }

    fclose(fin);
    fclose(fout);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return -1;
    }

    encrypt_file(argv[1]);
    decrypt_file(strcat(argv[1], ".enc"));

    return 0;
}