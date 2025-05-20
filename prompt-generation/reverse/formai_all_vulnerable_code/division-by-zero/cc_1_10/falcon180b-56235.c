//Falcon-180B DATASET v1.0 Category: Encryption ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char message[], char key[]) {
    int i, j, n;
    char encrypted_message[MAX_MESSAGE_LENGTH];

    n = strlen(message);
    encrypted_message[0] = tolower(message[0]);
    for (i = 1; i < n; i++) {
        if (islower(message[i])) {
            encrypted_message[i] = (message[i] - key[i % strlen(key)] + 26) % 26 + 'a';
        } else if (isupper(message[i])) {
            encrypted_message[i] = (message[i] - key[i % strlen(key)] + 26) % 26 + 'A';
        } else {
            encrypted_message[i] = message[i];
        }
    }

    for (i = 0, j = n - 1; i < j; i++, j--) {
        char temp = encrypted_message[i];
        encrypted_message[i] = encrypted_message[j];
        encrypted_message[j] = temp;
    }

    printf("\nEncrypted message: %s\n", encrypted_message);
}

void decrypt(char encrypted_message[], char key[]) {
    int i, j, n;
    char decrypted_message[MAX_MESSAGE_LENGTH];

    n = strlen(encrypted_message);
    decrypted_message[0] = toupper(encrypted_message[0]);
    for (i = 1; i < n; i++) {
        if (isupper(encrypted_message[i])) {
            decrypted_message[i] = (encrypted_message[i] - key[i % strlen(key)] - 26 + 26) % 26 + 'A';
        } else if (islower(encrypted_message[i])) {
            decrypted_message[i] = (encrypted_message[i] - key[i % strlen(key)] - 26 + 26) % 26 + 'a';
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    for (i = 0, j = n - 1; i < j; i++, j--) {
        char temp = decrypted_message[i];
        decrypted_message[i] = decrypted_message[j];
        decrypted_message[j] = temp;
    }

    printf("\nDecrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = '\0';

    printf("\nEncrypted message: ");
    encrypt(message, key);

    printf("\nDecrypted message: ");
    decrypt(message, key);

    return 0;
}