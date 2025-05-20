//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *key;
    int keylen;
} key_pair;

int encrypt(char *file, key_pair key) {
    FILE *fp = fopen(file, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    char *buffer = malloc(filesize);
    fread(buffer, filesize, 1, fp);
    fclose(fp);

    for (int i = 0; i < filesize; i++) {
        buffer[i] ^= key.key[i % key.keylen];
    }

    fp = fopen(file, "wb");
    fwrite(buffer, filesize, 1, fp);
    fclose(fp);

    free(buffer);

    return 0;
}

int decrypt(char *file, key_pair key) {
    return encrypt(file, key);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s encrypt/decrypt file keyfile\n", argv[0]);
        return -1;
    }

    char *mode = argv[1];
    char *file = argv[2];
    char *keyfile = argv[3];

    FILE *fp = fopen(keyfile, "rb");
    if (fp == NULL) {
        perror("Error opening keyfile");
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    long keylen = ftell(fp);
    rewind(fp);

    char *key = malloc(keylen + 1);
    fread(key, keylen, 1, fp);
    fclose(fp);

    key[keylen] = '\0';

    key_pair key_pair;
    key_pair.key = key;
    key_pair.keylen = keylen;

    if (strcmp(mode, "encrypt") == 0) {
        encrypt(file, key_pair);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt(file, key_pair);
    } else {
        fprintf(stderr, "Error: Invalid mode '%s'\n", mode);
        return -1;
    }

    free(key);

    return 0;
}