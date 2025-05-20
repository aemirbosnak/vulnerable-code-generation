//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 25
#define BUFFER_SIZE 1024

void generate_key(char *passphrase, char *key) {
    int i;
    for (i = 0; i < KEY_LENGTH && i < strlen(passphrase); i++) {
        key[i] = toupper(passphrase[i]);
    }
    while (KEY_LENGTH > i) {
        key[KEY_LENGTH - 1 - i] = key[i] ^ (i + 1);
        i++;
    }
}

void xor_cipher(char *plaintext, char *key, char *ciphertext) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_LENGTH];
    }
    ciphertext[i] = '\0';
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <passphrase> <plaintext>\n", argv[0]);
        return 1;
    }

    char passphrase[KEY_LENGTH + 1];
    char plaintext[BUFFER_SIZE];
    char key[KEY_LENGTH];
    char ciphertext[BUFFER_SIZE];

    strcpy(passphrase, argv[1]);

    generate_key(passphrase, key);

    fgets(plaintext, BUFFER_SIZE, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    xor_cipher(plaintext, key, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Key: ");
    for (int i = 0; i < KEY_LENGTH; i++) {
        printf("%c ", key[i]);
    }
    printf("\n");
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}