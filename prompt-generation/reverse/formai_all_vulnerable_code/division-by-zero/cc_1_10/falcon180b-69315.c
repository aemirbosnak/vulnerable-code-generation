//Falcon-180B DATASET v1.0 Category: Encryption ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int i, j, key_index = 0;
    for (i = 0; plaintext[i]!= '\0'; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[i] = (char) ((int) plaintext[i] + (int) key[key_index] - 65);
            } else {
                ciphertext[i] = (char) ((int) plaintext[i] + (int) key[key_index] - 97);
            }
            key_index = (key_index + 1) % strlen(key);
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    int i, j, key_index = 0;
    for (i = 0; ciphertext[i]!= '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                plaintext[i] = (char) ((int) ciphertext[i] - (int) key[key_index] - 65);
            } else {
                plaintext[i] = (char) ((int) ciphertext[i] - (int) key[key_index] - 97);
            }
            key_index = (key_index + 1) % strlen(key);
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0';
}

int main() {
    char plaintext[100], ciphertext[100], key[MAX_KEY_LEN];
    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    printf("Enter key: ");
    scanf("%s", key);
    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    decrypt(ciphertext, key, plaintext);
    printf("Decrypted text: %s\n", plaintext);
    return 0;
}