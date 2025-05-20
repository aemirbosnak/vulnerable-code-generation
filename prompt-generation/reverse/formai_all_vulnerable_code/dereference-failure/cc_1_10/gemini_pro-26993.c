//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Function to perform binary XOR on two bitstrings
char* XOR(char* a, char* b) {
    char* result = (char*)malloc(sizeof(char) * 256);
    for (int i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
        result[i] = (a[i] == b[i]) ? '0' : '1';
    }
    result[256] = '\0';  // Null-terminate the result string
    return result;
}

// Function to perform modulo 2 exponentiation
char* modPow(char* base, char* exponent, char* modulus) {
    char* result = (char*)malloc(sizeof(char) * 256);
    strcpy(result, base);  // Initialize result to the base

    for (int i = 1; exponent[i] != '\0'; i++) {
        char* temp = XOR(result, base);  // Compute result XOR base
        free(result);  // Free the previous result
        result = XOR(temp, exponent[i] - '0' ? modulus : "0");  // Update result based on exponent bit
        free(temp);  // Free the temporary variable
    }

    return result;
}

// Function to perform RSA encryption
char* RSA(char* message, char* publicKey, char* modulus) {
    char* encryptedMessage = modPow(message, publicKey, modulus);
    printf("Encrypted Message: %s\n", encryptedMessage);
    return encryptedMessage;
}

// Function to perform RSA decryption
char* RSAdecrypt(char* encryptedMessage, char* privateKey, char* modulus) {
    char* decryptedMessage = modPow(encryptedMessage, privateKey, modulus);
    printf("Decrypted Message: %s\n", decryptedMessage);
    return decryptedMessage;
}

int main() {
    // Initialize input variables
    char* message = "Hello, World!";
    char* publicKey = "000001";
    char* privateKey = "000001";
    char* modulus = "100001";

    // Perform encryption and decryption
    char* encryptedMessage = RSA(message, publicKey, modulus);
    char* decryptedMessage = RSAdecrypt(encryptedMessage, privateKey, modulus);

    return 0;
}