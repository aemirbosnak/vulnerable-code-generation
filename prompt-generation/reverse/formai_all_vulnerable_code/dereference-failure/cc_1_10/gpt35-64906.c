//FormAI DATASET v1.0 Category: modern Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, int key) {
    int length = strlen(message);
    char* encrypted = (char*) malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = ((message[i] - 'a') + key) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = ((message[i] - 'A') + key) % 26 + 'A';
        } else {
            encrypted[i] = message[i];
        }
    }
    return encrypted;
}

char* decrypt(char* message, int key) {
    int length = strlen(message);
    char* decrypted = (char*) malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            decrypted[i] = ((message[i] - 'a') - key + 26) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            decrypted[i] = ((message[i] - 'A') - key + 26) % 26 + 'A';
        } else {
            decrypted[i] = message[i];
        }
    }
    return decrypted;
}

int main() {
    char message[1000], option;
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter encryption key: ");
    scanf("%d", &key);

    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    printf("Do you want to decrypt the message? (Y/N): ");
    scanf(" %c", &option);

    if (option == 'Y' || option == 'y') {
        char* decrypted = decrypt(encrypted, key);
        printf("Decrypted message: %s\n", decrypted);
        free(decrypted);
    }

    free(encrypted);
    return 0;
}