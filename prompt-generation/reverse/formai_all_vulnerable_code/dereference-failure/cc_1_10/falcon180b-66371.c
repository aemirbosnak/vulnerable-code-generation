//Falcon-180B DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define the encryption key
#define KEY "mysecretkey"

// Function to encrypt a string using the key
char* encrypt(char* str) {
    int len = strlen(str);
    char* encrypted = (char*) malloc(len + 1);
    int key_len = strlen(KEY);
    int i, j, k;

    for(i = 0, j = 0; i < len; i++) {
        if(isalpha(str[i])) {
            str[i] = toupper(str[i]);
            encrypted[j++] = str[i] ^ KEY[i % key_len];
        } else {
            encrypted[j++] = str[i];
        }
    }

    encrypted[j] = '\0';
    return encrypted;
}

// Function to decrypt an encrypted string using the key
char* decrypt(char* encrypted) {
    int len = strlen(encrypted);
    char* decrypted = (char*) malloc(len + 1);
    int key_len = strlen(KEY);
    int i, j, k;

    for(i = 0, j = 0; i < len; i++) {
        if(isalpha(encrypted[i])) {
            encrypted[i] = toupper(encrypted[i]);
            decrypted[j++] = encrypted[i] ^ KEY[i % key_len];
        } else {
            decrypted[j++] = encrypted[i];
        }
    }

    decrypted[j] = '\0';
    return decrypted;
}

int main() {
    char* input = "This is a secret message. ";
    char* encrypted = encrypt(input);
    char* decrypted = decrypt(encrypted);

    printf("Input: %s\n", input);
    printf("Encrypted: %s\n", encrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}