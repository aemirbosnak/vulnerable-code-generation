//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *public_key;
} KeyPair;

void generate_keypair(KeyPair *keypair) {
    srand(time(NULL));
    int len = 16;
    char *key = (char *)malloc(len * sizeof(char));
    char *public_key = (char *)malloc(len * sizeof(char));

    for (int i = 0; i < len; i++) {
        key[i] = 'a' + rand() % 26;
        public_key[i] = key[i];
    }

    keypair->key = key;
    keypair->public_key = public_key;
}

char *encrypt(const char *plaintext, const KeyPair *keypair) {
    char *ciphertext = (char *)malloc(strlen(plaintext) + 1 * sizeof(char));
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = keypair->public_key[plaintext[i] - 'a'];
    }
    ciphertext[strlen(plaintext)] = '\0';
    return ciphertext;
}

char *decrypt(const char *ciphertext, const KeyPair *keypair) {
    char *plaintext = (char *)malloc(strlen(ciphertext) + 1 * sizeof(char));
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = keypair->key[ciphertext[i] - 'a'];
    }
    plaintext[strlen(ciphertext)] = '\0';
    return plaintext;
}

int main() {
    KeyPair keypair;
    generate_keypair(&keypair);

    char plaintext[] = "Hello, World!";
    char *ciphertext = encrypt(plaintext, &keypair);
    printf("Ciphertext: %s\n", ciphertext);

    char *plaintext2 = decrypt(ciphertext, &keypair);
    printf("Plaintext: %s\n", plaintext2);

    free(keypair.key);
    free(keypair.public_key);
    return 0;
}