//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *message, int key) {
    int i, j, n = strlen(message);
    char *result = malloc(n + 1);

    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[j++] = ((message[i] + key - 65) % 26) + 65;
            } else {
                result[j++] = ((message[i] + key - 97) % 26) + 97;
            }
        } else {
            result[j++] = message[i];
        }
    }
    result[j] = '\0';

    printf("Encrypted message: %s\n", result);
}

void decrypt(char *message, int key) {
    int i, j, n = strlen(message);
    char *result = malloc(n + 1);

    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[j++] = ((message[i] - key - 65) % 26) + 65;
            } else {
                result[j++] = ((message[i] - key - 97) % 26) + 97;
            }
        } else {
            result[j++] = message[i];
        }
    }
    result[j] = '\0';

    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[100];
    int key, choice;

    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    printf("Enter the encryption key (1-25): ");
    scanf("%d", &key);

    printf("Enter 1 to encrypt and 2 to decrypt: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(message, key);
            break;
        case 2:
            decrypt(message, key);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}