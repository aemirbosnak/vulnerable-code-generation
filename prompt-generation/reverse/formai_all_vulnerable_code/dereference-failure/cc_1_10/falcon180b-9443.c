//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

void generate_key(char *key) {
    int i;
    for (i = 0; i < SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[SIZE] = '\0';
}

void encrypt(char *message, char *key) {
    int i, j;
    char encrypted_message[SIZE];
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            encrypted_message[j] = (message[i] + key[i % SIZE] - 'a' + 26) % 26 + 'a';
            j++;
        } else {
            encrypted_message[j] = message[i];
            j++;
        }
    }
    encrypted_message[j] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *message, char *key) {
    int i, j;
    char decrypted_message[SIZE];
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            decrypted_message[j] = (message[i] - key[i % SIZE] - 'a' + 26) % 26 + 'a';
            j++;
        } else {
            decrypted_message[j] = message[i];
            j++;
        }
    }
    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[SIZE];
    char key[SIZE];
    generate_key(key);
    printf("Enter message: ");
    scanf("%s", message);
    printf("Encrypted message: ");
    encrypt(message, key);
    printf("Decrypted message: ");
    decrypt(message, key);
    return 0;
}