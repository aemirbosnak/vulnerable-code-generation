//FormAI DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function generates a random key for encryption
char* generateKey(int length) {
    char* key = (char*)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        key[i] = (char)(rand() % 26 + 65);
    }
    key[length] = '\0';
    return key;
}

// This function converts a string to an array of primes
int* stringToPrimes(char* str) {
    int length = strlen(str);
    int* primes = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        primes[i] = str[i];
        for (int j = 2; j <= primes[i] / 2; j++) {
            if (primes[i] % j == 0) {
                primes[i] = j;
                break;
            }
        }
    }
    return primes;
}

// This function encrypts a string using a key
char* encrypt(char* str, char* key) {
    int length = strlen(str);
    int keyLength = strlen(key);
    char* cipher = (char*)malloc(length + 1);
    int* primes = stringToPrimes(str);
    for (int i = 0; i < length; i++) {
        cipher[i] = (char)((primes[i] % (key[i % keyLength] - 64)) + 32);
    }
    cipher[length] = '\0';
    free(primes);
    return cipher;
}

// This function decrypts a string using a key
char* decrypt(char* cipher, char* key) {
    int length = strlen(cipher);
    int keyLength = strlen(key);
    char* str = (char*)malloc(length + 1);
    int* primes = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        primes[i] = ((int)cipher[i] - 32) * (key[i % keyLength] - 64);
        str[i] = (char)primes[i];
    }
    str[length] = '\0';
    free(primes);
    return str;
}

// Main function to demonstrate how the encryption works
int main() {
    char message[100];
    char* key = generateKey(10);
    printf("Enter message to encrypt: ");
    scanf("%[^\n]s", message);
    char* cipher = encrypt(message, key);
    printf("Encrypted message: %s\n", cipher);
    char* decrypted = decrypt(cipher, key);
    printf("Decrypted message: %s\n", decrypted);
    free(key);
    free(cipher);
    free(decrypted);
    return 0;
}