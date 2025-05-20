//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024
#define MAX_KEY_SIZE 256

char* encrypt(char* plaintext, char* key) {
    int i, j, n;
    char* ciphertext = malloc(MAX_SIZE);
    memset(ciphertext, 0, MAX_SIZE);

    for (i = 0, j = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            n = toupper(plaintext[i]) - 'A';
            if (isupper(key[j])) {
                n = (n - toupper(key[j]) + 26) % 26;
            } else {
                n = (n - tolower(key[j]) + 26) % 26;
            }
            ciphertext[j] = n + 'A';
            j++;
        } else {
            ciphertext[j] = plaintext[i];
            j++;
        }
    }

    return ciphertext;
}

char* decrypt(char* ciphertext, char* key) {
    int i, j, n;
    char* plaintext = malloc(MAX_SIZE);
    memset(plaintext, 0, MAX_SIZE);

    for (i = 0, j = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            n = toupper(ciphertext[i]) - 'A';
            if (isupper(key[j])) {
                n = (n - toupper(key[j]) + 26) % 26;
            } else {
                n = (n - tolower(key[j]) + 26) % 26;
            }
            plaintext[j] = n + 'A';
            j++;
        } else {
            plaintext[j] = ciphertext[i];
            j++;
        }
    }

    return plaintext;
}

int main() {
    char* plaintext = "Hello, world!";
    char* key = "Cyberpunk";
    char* ciphertext = encrypt(plaintext, key);
    printf("Ciphertext: %s\n", ciphertext);

    char* decrypted = decrypt(ciphertext, key);
    printf("Decrypted: %s\n", decrypted);

    free(ciphertext);
    free(decrypted);

    return 0;
}