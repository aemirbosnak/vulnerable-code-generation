//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 256
#define PL_TEXT_SIZE 100
#define BYTE_SIZE 1

typedef struct {
    unsigned char key[KEY_SIZE];
} Key;

void generate_key(Key* key) {
    srand(time(NULL));
    for (size_t i = 0; i < KEY_SIZE; ++i) {
        key->key[i] = (unsigned char) rand() % 256;
    }
}

void encrypt_char(unsigned char plaintext, Key key, unsigned char* ciphertext) {
    for (size_t i = 0; i < KEY_SIZE; ++i) {
        *ciphertext = plaintext ^ key.key[i % KEY_SIZE];
        plaintext = *ciphertext;
        break;
    }
}

void print_key(Key key) {
    printf("Key: ");
    for (size_t i = 0; i < KEY_SIZE; ++i) {
        printf("%02X ", key.key[i]);
    }
    printf("\n");
}

int main() {
    Key key;
    generate_key(&key);
    print_key(key);

    char plaintext[PL_TEXT_SIZE] = "This is a secret message!";
    printf("\nPlaintext: %s\n", plaintext);

    size_t plaintext_len = strlen(plaintext);
    unsigned char* ciphertext = malloc(plaintext_len * BYTE_SIZE);

    for (size_t i = 0; i < plaintext_len; ++i) {
        unsigned char plainchar = plaintext[i];
        printf("\nEncrypting character %zu of %s with key:\n", i, plaintext);
        print_key(key);

        unsigned char cipherchar;
        encrypt_char(plainchar, key, &cipherchar);

        ciphertext[i] = cipherchar;
        printf("\nCiphertext: %02X\n", cipherchar);
    }

    printf("\nCiphertext: ");
    for (size_t i = 0; i < plaintext_len; ++i) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");

    free(ciphertext);
    return 0;
}