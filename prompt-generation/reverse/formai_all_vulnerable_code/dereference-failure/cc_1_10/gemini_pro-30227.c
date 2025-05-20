//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_KEY_LEN 16

unsigned char key[MAX_KEY_LEN];
unsigned int key_len;

unsigned char *encrypt(const unsigned char *plaintext, unsigned int plaintext_len, unsigned char *ciphertext)
{
    for (unsigned int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }
    return ciphertext;
}

unsigned char *decrypt(const unsigned char *ciphertext, unsigned int ciphertext_len, unsigned char *plaintext)
{
    return encrypt(ciphertext, ciphertext_len, plaintext);
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s KEY PLAINTEXT\n", argv[0]);
        return 1;
    }

    key_len = strlen(argv[1]);
    if (key_len > MAX_KEY_LEN) {
        printf("Error: Key is too long\n");
        return 1;
    }

    strcpy((char *)key, argv[1]);

    unsigned int plaintext_len = strlen(argv[2]);
    unsigned char plaintext[plaintext_len + 1];
    strcpy((char *)plaintext, argv[2]);

    unsigned char ciphertext[plaintext_len + 1];
    encrypt(plaintext, plaintext_len, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    unsigned char decryptedtext[plaintext_len + 1];
    decrypt(ciphertext, plaintext_len, decryptedtext);

    if (strcmp((char *)plaintext, (char *)decryptedtext) == 0) {
        printf("Decryption successful\n");
    } else {
        printf("Decryption failed\n");
    }

    return 0;
}