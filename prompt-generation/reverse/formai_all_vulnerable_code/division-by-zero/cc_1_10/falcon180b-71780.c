//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_PLAINTEXT_LENGTH 1024
#define MAX_CIPHERTEXT_LENGTH (MAX_PLAINTEXT_LENGTH + 1)

void generate_key(char *key, int length) {
    for (int i = 0; i < length; i++) {
        char c = rand() % 26 + 'a';
        key[i] = c;
    }
    key[length] = '\0';
}

void encrypt(char *key, char *plaintext, char *ciphertext) {
    int i, j;
    for (i = 0, j = 0; plaintext[i]!= '\0'; i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[j++] = toupper(plaintext[i]) ^ key[i % strlen(key)];
        } else {
            ciphertext[j++] = plaintext[i];
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char *key, char *ciphertext, char *plaintext) {
    int i, j;
    for (i = 0, j = 0; ciphertext[i]!= '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[j++] = (ciphertext[i] ^ key[i % strlen(key)]) - 'A' + 'a';
        } else {
            plaintext[j++] = ciphertext[i];
        }
    }
    plaintext[j] = '\0';
}

int main() {
    char key[MAX_KEY_LENGTH];
    char plaintext[MAX_PLAINTEXT_LENGTH];
    char ciphertext[MAX_CIPHERTEXT_LENGTH];

    printf("Enter a key: ");
    scanf("%s", key);

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    generate_key(key, strlen(key));
    encrypt(key, plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    strcpy(plaintext, ciphertext);
    decrypt(key, plaintext, plaintext);

    printf("Plaintext: %s\n", plaintext);

    return 0;
}