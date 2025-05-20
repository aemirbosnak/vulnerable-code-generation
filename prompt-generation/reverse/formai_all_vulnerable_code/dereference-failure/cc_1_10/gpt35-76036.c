//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

/* Function to encrypt message using Caesar cipher */
char* caesarCipher(char* message, int key) {
    char *encryptedMessage = (char *)malloc(sizeof(char));
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encryptedMessage[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            encryptedMessage[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
        else {
            encryptedMessage[i] = message[i];
        }
    }
    encryptedMessage[i] = '\0';
    return encryptedMessage;
}

/* Function to decrypt message using Caesar cipher */
char* caesarDecipher(char* message, int key) {
    char *decryptedMessage = (char *)malloc(sizeof(char));
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            decryptedMessage[i] = (((message[i] - 'a' - key) + 26) % 26) + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            decryptedMessage[i] = (((message[i] - 'A' - key) + 26) % 26) + 'A';
        }
        else {
            decryptedMessage[i] = message[i];
        }
    }
    decryptedMessage[i] = '\0';
    return decryptedMessage;
}

int main() {
    char message[100], *encryptedMessage, *decryptedMessage;
    int key;

    printf("Enter message to encrypt: ");
    scanf("%[^\n]%*c", message);

    printf("Enter key: ");
    scanf("%d", &key);

    encryptedMessage = caesarCipher(message, key);
    printf("Encrypted message: %s\n", encryptedMessage);

    decryptedMessage = caesarDecipher(encryptedMessage, key);
    printf("Decrypted message: %s\n", decryptedMessage);

    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}