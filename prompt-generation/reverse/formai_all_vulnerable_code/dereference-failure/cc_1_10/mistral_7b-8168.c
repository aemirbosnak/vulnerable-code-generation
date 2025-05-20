//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <unistd.h>

#define KEY_SIZE 16
#define IV_SIZE 16
#define BUFFER_SIZE 128

bool checkKey(const unsigned char *key, size_t keylen) {
    size_t i;
    for (i = 0; i < keylen; i++)
        if (!isxdigit(key[i])) return false;
    keylen /= 2;
    for (i = 0; i < keylen; i++) {
        unsigned char c = key[i * 2], d = key[i * 2 + 1];
        if (!(isdigit(c) && isdigit(d) && c < '9' && d < '9' + (isdigit(c) ? 10 : 15)))
            return false;
    }
    return true;
}

unsigned char *readKeyFile(const char *filename, size_t *keylen) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return NULL;

    size_t len = 0;
    unsigned char *key = NULL;
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (len + 2 > *keylen) {
            *keylen += BUFFER_SIZE;
            key = realloc(key, *keylen);
        }
        key[len++] = c;
        key[len++] = c >> 4;
    }
    fclose(fp);

    if (len % 2 != 0) {
        free(key);
        return NULL;
    }
    len /= 2;
    *keylen = len * 2;
    return key;
}

unsigned char *encrypt(const unsigned char *data, const unsigned char *key, const unsigned char *iv) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, KEY_SIZE, &aes_key);
    size_t len = strlen(data);

    unsigned char *encrypted = malloc(len + IV_SIZE);
    unsigned char ivCopy[IV_SIZE];
    memcpy(ivCopy, iv, IV_SIZE);

    int i;
    for (i = 0; i < IV_SIZE; i++) ivCopy[i] ^= 0x36;

    AES_cbc_encrypt(data, encrypted, len, &aes_key, ivCopy, AES_ENCRYPT);

    free(ivCopy);
    return encrypted;
}

void printHex(const unsigned char *data, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        if (i > 0 && i % 16 == 0) printf("\n%04x: ", i);
        printf("%.2x ", data[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <keyfile> <data>\n", argv[0]);
        return 1;
    }

    const char *keyfile = argv[1];
    const char *data = argv[2];

    size_t keylen;
    unsigned char *key = readKeyFile(keyfile, &keylen);
    if (!key) return 1;

    if (!checkKey(key, keylen)) {
        fprintf(stderr, "Invalid key.\n");
        free(key);
        return 1;
    }

    unsigned char iv[IV_SIZE];
    memset(iv, 0x36, IV_SIZE);

    unsigned char *encrypted = encrypt((unsigned char *)data, key, iv);
    if (!encrypted) {
        fprintf(stderr, "Encryption failed.\n");
        free(key);
        return 1;
    }

    printf("Encrypted data:\n");
    printHex(encrypted, strlen(data) + IV_SIZE);

    free(key);
    free(encrypted);
    return 0;
}