//FormAI DATASET v1.0 Category: modern Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY "mysecretkey"

char *encrypt(char *message, char *key) {
    srand(time(NULL));
    int len = strlen(message);
    char *encrypted = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        int shift = rand() % 26;
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = (message[i] - 'a' + shift) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = (message[i] - 'A' + shift) % 26 + 'A';
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[len] = '\0';
    return encrypted;
}

char *decrypt(char *message, char *key) {
    srand(time(NULL));
    int len = strlen(message);
    char *decrypted = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        int shift = rand() % 26;
        if (message[i] >= 'a' && message[i] <= 'z') {
            decrypted[i] = (message[i] - 'a' - shift + 26) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            decrypted[i] = (message[i] - 'A' - shift + 26) % 26 + 'A';
        } else {
            decrypted[i] = message[i];
        }
    }
    decrypted[len] = '\0';
    return decrypted;
}

int main() {
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;
    char *encrypted = encrypt(message, KEY);
    printf("Encrypted message: %s\n", encrypted);
    char *decrypted = decrypt(encrypted, KEY);
    printf("Decrypted message: %s\n", decrypted);
    free(encrypted);
    free(decrypted);
    return 0;
}