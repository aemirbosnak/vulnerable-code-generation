//Falcon-180B DATASET v1.0 Category: Encryption ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

void encrypt(char *message, char *key) {
    int i, j, pos;
    char result[MAX_SIZE];

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[j] = (char) ((int) message[i] + (int) key[j % strlen(key)] - 65);
            } else {
                result[j] = (char) ((int) message[i] + (int) key[j % strlen(key)] - 97);
            }
            j++;
        } else {
            result[j] = message[i];
            j++;
        }
    }

    result[j] = '\0';
    strcpy(message, result);
}

void decrypt(char *message, char *key) {
    int i, j, pos;
    char result[MAX_SIZE];

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[j] = (char) ((int) message[i] - (int) key[j % strlen(key)] + 65);
            } else {
                result[j] = (char) ((int) message[i] - (int) key[j % strlen(key)] + 97);
            }
            j++;
        } else {
            result[j] = message[i];
            j++;
        }
    }

    result[j] = '\0';
    strcpy(message, result);
}

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];

    printf("Enter the message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);

    printf("Enter the encryption key: ");
    fgets(key, MAX_SIZE, stdin);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}