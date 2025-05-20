//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
#define KEY "mysecretkey"

void encrypt(char* message, int key) {
    int length = strlen(message);
    char* encrypted = (char*) malloc(length + 1);
    int i = 0;
    int j = 0;
    while (i < length) {
        encrypted[j++] = message[i] ^ (key % 26 + 97);
        i++;
        if (key % 26 == 25) {
            key = 0;
        } else {
            key++;
        }
    }
    encrypted[j] = '\0';
    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char* encrypted, int key) {
    int length = strlen(encrypted);
    char* decrypted = (char*) malloc(length + 1);
    int i = 0;
    int j = 0;
    while (i < length) {
        decrypted[j++] = encrypted[i] ^ (key % 26 + 97);
        i++;
        if (key % 26 == 25) {
            key = 0;
        } else {
            key++;
        }
    }
    decrypted[j] = '\0';
    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char message[SIZE];
    printf("Enter a message to encrypt: ");
    fgets(message, SIZE, stdin);
    encrypt(message, KEY[0]);
    printf("\n");
    decrypt(message, KEY[0]);
    printf("\n");
    return 0;
}