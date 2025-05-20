//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100000

typedef struct {
    char* message;
    int len;
    char* key;
    int key_len;
} Steganography;

Steganography* createSteganography(char* message, int len, char* key, int key_len) {
    Steganography* steg = malloc(sizeof(Steganography));
    steg->message = malloc(len * sizeof(char));
    steg->len = len;
    steg->key = malloc(key_len * sizeof(char));
    steg->key_len = key_len;
    strcpy(steg->message, message);
    strcpy(steg->key, key);
    return steg;
}

void encrypt(Steganography* steg) {
    int i, j, k;
    for (i = 0, j = 0; i < steg->len; i++) {
        if (isalpha(steg->message[i])) {
            if (isupper(steg->message[i])) {
                steg->message[i] = steg->key[(j++) % steg->key_len];
            } else {
                steg->message[i] = steg->key[(j++) % steg->key_len];
            }
        }
    }
}

void decrypt(Steganography* steg) {
    int i, j, k;
    for (i = 0, j = 0; i < steg->len; i++) {
        if (isalpha(steg->message[i])) {
            if (isupper(steg->message[i])) {
                steg->message[i] = tolower(steg->key[(j++) % steg->key_len]);
            } else {
                steg->message[i] = tolower(steg->key[(j++) % steg->key_len]);
            }
        }
    }
}

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];
    Steganography* steg;
    int len, key_len;

    printf("Enter message: ");
    fgets(message, MAX_SIZE, stdin);
    len = strlen(message);

    printf("Enter key: ");
    fgets(key, MAX_SIZE, stdin);
    key_len = strlen(key);

    steg = createSteganography(message, len, key, key_len);
    encrypt(steg);
    printf("Encrypted message: %s\n", steg->message);

    decrypt(steg);
    printf("Decrypted message: %s\n", steg->message);

    free(steg->message);
    free(steg->key);
    free(steg);

    return 0;
}