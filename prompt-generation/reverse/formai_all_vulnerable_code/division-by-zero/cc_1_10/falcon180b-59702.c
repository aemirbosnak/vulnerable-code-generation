//Falcon-180B DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_SIZE 16
#define MAX_MSG_SIZE 256

void encrypt(char* message, char* key) {
    int i, j, k;
    int msg_len = strlen(message);
    int key_len = strlen(key);

    if (key_len > MAX_KEY_SIZE) {
        printf("Key size too large. Maximum key size is %d.\n", MAX_KEY_SIZE);
        exit(1);
    }

    for (i = 0, j = 0; i < msg_len; i++) {
        char c = toupper(message[i]);
        if (isalpha(c)) {
            c = c + (key[j] - 'A');
            j = (j + 1) % key_len;
        }
        printf("%c", c);
    }
}

void decrypt(char* message, char* key) {
    int i, j, k;
    int msg_len = strlen(message);
    int key_len = strlen(key);

    if (key_len > MAX_KEY_SIZE) {
        printf("Key size too large. Maximum key size is %d.\n", MAX_KEY_SIZE);
        exit(1);
    }

    for (i = 0, j = 0; i < msg_len; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = c - (key[j] - 'A');
            j = (j + 1) % key_len;
        }
        printf("%c", c);
    }
}

int main() {
    char message[MAX_MSG_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter message: ");
    fgets(message, MAX_MSG_SIZE, stdin);

    printf("Enter key: ");
    fgets(key, MAX_KEY_SIZE, stdin);

    printf("Encrypted message: ");
    encrypt(message, key);
    printf("\n");

    printf("Decrypted message: ");
    decrypt(message, key);
    printf("\n");

    return 0;
}