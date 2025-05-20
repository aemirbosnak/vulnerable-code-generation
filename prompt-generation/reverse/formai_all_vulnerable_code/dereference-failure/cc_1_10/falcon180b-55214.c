//Falcon-180B DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

void encrypt(char *message, int key) {
    int i = 0, j = 0;
    char encrypted_message[1000];
    char *decrypted_message = malloc(strlen(message) + 1);

    while (message[i]) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[j] = (((message[i] - 65 + key) % 26) + 65);
            } else {
                encrypted_message[j] = (((message[i] - 97 + key) % 26) + 97);
            }
        } else {
            encrypted_message[j] = message[i];
        }
        i++;
        j++;
    }

    encrypted_message[j] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);

    for (i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[i] = (((encrypted_message[i] - 65 - key + 26) % 26) + 65);
            } else {
                decrypted_message[i] = (((encrypted_message[i] - 97 - key + 26) % 26) + 97);
            }
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    decrypted_message[strlen(encrypted_message)] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);

    free(decrypted_message);
}

int main() {
    char message[1000];
    int key;

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter key (0-25): ");
    scanf("%d", &key);

    encrypt(message, key);

    return 0;
}