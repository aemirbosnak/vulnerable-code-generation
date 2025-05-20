//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// Function to encrypt the message using public key
void encrypt(char *message, char *publicKey) {
    // Convert the message to ASCII values
    int length = strlen(message);
    int i;
    char *asciiMessage = (char *)malloc(length * sizeof(char));
    for (i = 0; i < length; i++) {
        asciiMessage[i] = message[i];
    }

    // Convert the ASCII values to binary
    int j;
    int binaryMessage[length];
    for (j = 0; j < length; j++) {
        binaryMessage[j] = asciiMessage[j] & 0xff;
    }

    // Perform XOR operation with the public key
    int k;
    for (k = 0; k < length; k++) {
        binaryMessage[k] ^= publicKey[k];
    }

    // Convert the binary message back to ASCII values
    char *binaryMessageAscii = (char *)malloc(length * sizeof(char));
    for (j = 0; j < length; j++) {
        binaryMessageAscii[j] = (char)binaryMessage[j];
    }

    // Convert the binary message ASCII values to string
    char *encryptedMessage = (char *)malloc(length * sizeof(char));
    for (i = 0; i < length; i++) {
        encryptedMessage[i] = binaryMessageAscii[i];
    }

    // Free memory
    free(asciiMessage);
    free(binaryMessageAscii);
    free(encryptedMessage);
}

// Function to decrypt the message using private key
void decrypt(char *message, char *privateKey) {
    // Convert the message to ASCII values
    int length = strlen(message);
    int i;
    char *asciiMessage = (char *)malloc(length * sizeof(char));
    for (i = 0; i < length; i++) {
        asciiMessage[i] = message[i];
    }

    // Convert the ASCII values to binary
    int j;
    int binaryMessage[length];
    for (j = 0; j < length; j++) {
        binaryMessage[j] = asciiMessage[j] & 0xff;
    }

    // Perform XOR operation with the private key
    int k;
    for (k = 0; k < length; k++) {
        binaryMessage[k] ^= privateKey[k];
    }

    // Convert the binary message back to ASCII values
    char *binaryMessageAscii = (char *)malloc(length * sizeof(char));
    for (j = 0; j < length; j++) {
        binaryMessageAscii[j] = (char)binaryMessage[j];
    }

    // Convert the binary message ASCII values to string
    char *decryptedMessage = (char *)malloc(length * sizeof(char));
    for (i = 0; i < length; i++) {
        decryptedMessage[i] = binaryMessageAscii[i];
    }

    // Free memory
    free(asciiMessage);
    free(binaryMessageAscii);
    free(decryptedMessage);
}

int main() {
    // Generate public and private keys
    char publicKey[10] = "publickey";
    char privateKey[10] = "privatekey";

    // Encrypt the message
    char message[10] = "This is a secret message.";
    encrypt(message, publicKey);

    // Decrypt the message
    decrypt(message, privateKey);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}