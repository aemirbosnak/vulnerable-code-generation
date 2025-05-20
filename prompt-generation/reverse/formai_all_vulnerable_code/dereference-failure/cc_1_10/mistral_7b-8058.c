//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define IV_SIZE 16

typedef struct {
    unsigned char key[KEY_SIZE];
    unsigned char iv[IV_SIZE];
} EncryptionKey;

void generate_key_iv(EncryptionKey *key) {
    RAND_bytes(key->key, KEY_SIZE);
    RAND_bytes(key->iv, IV_SIZE);
}

void print_binary(unsigned char *bytes, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%.2x", bytes[i]);
    }
    printf("\n");
}

void encrypt_text(const unsigned char *plain_text, const EncryptionKey *key, const unsigned char *iv) {
    int len = strlen((const char *)plain_text);
    unsigned char cipher_text[len + AES_BLOCK_SIZE];

    AES_KEY aes_key;
    AES_set_encrypt_key(key->key, 128, &aes_key);

    int num_blocks = (len + AES_BLOCK_SIZE - 1) / AES_BLOCK_SIZE;
    int padding = AES_BLOCK_SIZE - (len % AES_BLOCK_SIZE);

    int encrypted_len = 0;
    for (int i = 0; i < num_blocks; i++) {
        AES_cbc_encrypt(plain_text, cipher_text, len, &aes_key, iv, AES_ENCRYPT);

        if (i < num_blocks - 1) {
            memcpy(iv, cipher_text + len, IV_SIZE);
            len += AES_BLOCK_SIZE;
        }

        encrypted_len += AES_BLOCK_SIZE;
        memmove(cipher_text, cipher_text + AES_BLOCK_SIZE, encrypted_len - AES_BLOCK_SIZE);
    }

    memmove(cipher_text + encrypted_len, plain_text + len - padding, padding);
    encrypted_len += padding;

    printf("Encrypted Text: ");
    print_binary(cipher_text, encrypted_len);
}

int main() {
    srand(time(NULL));

    EncryptionKey encryption_key;
    generate_key_iv(&encryption_key);

    const unsigned char plain_text[] = "This is a secret message.";
    const int plain_text_len = strlen((const char *)plain_text);

    printf("Plain Text: ");
    print_binary(plain_text, plain_text_len);

    encrypt_text(plain_text, &encryption_key, encryption_key.iv);

    return 0;
}