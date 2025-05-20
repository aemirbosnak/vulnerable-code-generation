//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: happy
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Function to generate a random string of characters
char* generateRandomString(int length) {
    char* str = (char*)malloc(length * sizeof(char));
    int i;
    for (i = 0; i < length; i++) {
        str[i] = (char)rand() % 26 + 'A';
    }
    return str;
}

// Function to generate a public key from a private key
void generatePublicKey(char* privateKey, char* publicKey) {
    int i, j;
    int length = strlen(privateKey);
    
    // Find the index of the first occurrence of the character 'A' in the private key
    int indexA = -1;
    for (i = 0; i < length; i++) {
        if (privateKey[i] == 'A') {
            indexA = i;
            break;
        }
    }
    
    // Calculate the index of the first occurrence of the character 'B' after the index of the first occurrence of the character 'A'
    int indexB = -1;
    for (i = indexA + 1; i < length; i++) {
        if (privateKey[i] == 'B') {
            indexB = i;
            break;
        }
    }
    
    // Calculate the public key by concatenating the characters between the indices of the first occurrences of the characters 'A' and 'B'
    for (i = indexA + 1; i <= indexB; i++) {
        publicKey[i - indexA - 1] = privateKey[i];
    }
    
    // Reverse the public key
    for (i = 0, j = strlen(publicKey) - 1; i < j; i++, j--) {
        char temp = publicKey[i];
        publicKey[i] = publicKey[j];
        publicKey[j] = temp;
    }
}

// Function to encrypt a message using the public key
void encryptMessage(char* publicKey, char* message) {
    int i, j;
    int length = strlen(message);
    
    // Find the index of the first occurrence of the character 'A' in the message
    int indexA = -1;
    for (i = 0; i < length; i++) {
        if (message[i] == 'A') {
            indexA = i;
            break;
        }
    }
    
    // Calculate the index of the first occurrence of the character 'B' after the index of the first occurrence of the character 'A'
    int indexB = -1;
    for (i = indexA + 1; i < length; i++) {
        if (message[i] == 'B') {
            indexB = i;
            break;
        }
    }
    
    // Calculate the encrypted message by concatenating the characters between the indices of the first occurrences of the characters 'A' and 'B'
    for (i = indexA + 1; i <= indexB; i++) {
        publicKey[i - indexA - 1] = message[i];
    }
}

// Function to decrypt a message using the private key
void decryptMessage(char* privateKey, char* encryptedMessage) {
    int i, j;
    int length = strlen(encryptedMessage);
    
    // Find the index of the first occurrence of the character 'A' in the encrypted message
    int indexA = -1;
    for (i = 0; i < length; i++) {
        if (encryptedMessage[i] == 'A') {
            indexA = i;
            break;
        }
    }
    
    // Calculate the index of the first occurrence of the character 'B' after the index of the first occurrence of the character 'A'
    int indexB = -1;
    for (i = indexA + 1; i < length; i++) {
        if (encryptedMessage[i] == 'B') {
            indexB = i;
            break;
        }
    }
    
    // Calculate the decrypted message by concatenating the characters between the indices of the first occurrences of the characters 'A' and 'B'
    for (i = indexA + 1; i <= indexB; i++) {
        privateKey[i - indexA - 1] = encryptedMessage[i];
    }
}

int main() {
    // Generate a random string of characters for the private key
    char* privateKey = generateRandomString(MAX_LEN);
    
    // Generate a random string of characters for the public key
    char* publicKey = generateRandomString(MAX_LEN);
    
    // Generate the public key from the private key
    generatePublicKey(privateKey, publicKey);
    
    // Encrypt a message using the public key
    char* message = generateRandomString(MAX_LEN);
    encryptMessage(publicKey, message);
    
    // Decrypt the encrypted message using the private key
    char* encryptedMessage = generateRandomString(MAX_LEN);
    decryptMessage(privateKey, encryptedMessage);
    
    printf("Private Key: %s\n", privateKey);
    printf("Public Key: %s\n", publicKey);
    printf("Encrypted Message: %s\n", encryptedMessage);
    printf("Decrypted Message: %s\n", privateKey);
    
    free(privateKey);
    free(publicKey);
    free(message);
    free(encryptedMessage);
    
    return 0;
}