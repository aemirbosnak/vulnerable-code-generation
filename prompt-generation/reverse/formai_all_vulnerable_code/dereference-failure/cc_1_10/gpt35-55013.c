//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the key for encryption
typedef struct {
    char* value;
    int length;
} Key;

// Function to derive the key from a given password
Key deriveKeyFromPassword(char* password) {
    int length = strlen(password);
    char* temp = malloc(length*sizeof(char));

    // Manipulate the password to generate the key
    for (int i = 0; i < length; i++) {
        temp[i] = password[(length-1-i)%length];
        temp[i] = temp[i]^i;
    }

    Key key = {temp,length};

    return key;
}

// Function to encrypt a message using the key
char* encrypt(char* message, Key key) {
    int length = strlen(message);
    char* cipher = malloc(length*sizeof(char));

    // Encrypt each character of the message using the key
    for (int i = 0; i < length; i++) {
        cipher[i] = message[i]^key.value[i%key.length];
    }

    return cipher;
}

// Function to decrypt a message using the key
char* decrypt(char* cipher, Key key) {
    int length = strlen(cipher);
    char* message = malloc(length*sizeof(char));

    // Decrypt each character of the cipher using the key
    for (int i = 0; i < length; i++) {
        message[i] = cipher[i]^key.value[i%key.length];
    }

    return message;
}

int main() {
    char* password = "brave";

    // Derive the key from the password
    Key key = deriveKeyFromPassword(password);

    char* message = "This is a test message";
    printf("Original Message: %s\n", message);

    // Encrypt the message using the key
    char* cipher = encrypt(message, key);
    printf("Encrypted Message: %s\n", cipher);

    // Decrypt the encrypted message using the key
    char* decrypted = decrypt(cipher, key);
    printf("Decrypted Message: %s\n", decrypted);

    // Free the memory allocated for the strings
    free(key.value);
    free(cipher);
    free(decrypted);

    return 0;
}