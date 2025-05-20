//Falcon-180B DATASET v1.0 Category: Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 1024
#define MAX_DATA_LEN 1024

typedef struct {
    char key[MAX_KEY_LEN];
    char data[MAX_DATA_LEN];
} encryption_t;

encryption_t *create_encryption(char *key, char *data) {
    encryption_t *enc = malloc(sizeof(encryption_t));
    strcpy(enc->key, key);
    strcpy(enc->data, data);
    return enc;
}

void encrypt(encryption_t *enc) {
    int key_len = strlen(enc->key);
    int data_len = strlen(enc->data);
    char *result = malloc(data_len + 1);

    int i, j;
    for (i = 0, j = 0; i < data_len; i++) {
        char c = enc->data[i];
        c ^= enc->key[j];
        result[i] = c;
        j = (j + 1) % key_len;
    }

    strcpy(enc->data, result);
    free(result);
}

void decrypt(encryption_t *enc) {
    int key_len = strlen(enc->key);
    int data_len = strlen(enc->data);
    char *result = malloc(data_len + 1);

    int i, j;
    for (i = 0, j = 0; i < data_len; i++) {
        char c = enc->data[i];
        c ^= enc->key[j];
        result[i] = c;
        j = (j + 1) % key_len;
    }

    strcpy(enc->data, result);
    free(result);
}

int main() {
    encryption_t *enc = create_encryption("secret_key", "Hello, world!");
    printf("Original data: %s\n", enc->data);

    encrypt(enc);
    printf("Encrypted data: %s\n", enc->data);

    decrypt(enc);
    printf("Decrypted data: %s\n", enc->data);

    return 0;
}