//Falcon-180B DATASET v1.0 Category: Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *message, char *key);
void decrypt(char *ciphertext, char *key);

int main() {
    char message[1000], key[100];
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, char *key) {
    int i, j, k;
    char ch;

    for (i = 0, j = 0; message[i]; i++) {
        ch = tolower(message[i]);
        if (isalpha(ch)) {
            ch = (ch + tolower(key[j]) - 97) % 26 + 97;
            message[i] = ch;
            j = (j + 1) % strlen(key);
        }
    }
}

void decrypt(char *ciphertext, char *key) {
    int i, j, k;
    char ch;

    for (i = 0, j = 0; ciphertext[i]; i++) {
        ch = tolower(ciphertext[i]);
        if (isalpha(ch)) {
            ch = (ch - tolower(key[j]) + 26) % 26 + 97;
            ciphertext[i] = ch;
            j = (j + 1) % strlen(key);
        }
    }
}