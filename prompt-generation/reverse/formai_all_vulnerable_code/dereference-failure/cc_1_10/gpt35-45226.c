//FormAI DATASET v1.0 Category: Modern Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* This function generates a key for encryption */
char *generateKey(int keyLength) {
    char *key = malloc((keyLength + 1) * sizeof(char));
    srand(time(NULL)); // seed for randomness
    for (int i = 0; i < keyLength; i++) {
        key[i] = rand() % 26 + 'a'; // generate a random lowercase letter
    }
    key[keyLength] = '\0'; // terminate the string
    return key;
}

/* This function performs encryption using the key provided */
char *encrypt(char *plaintext, char *key) {
    int plaintextLength = strlen(plaintext);
    int keyLength = strlen(key);
    char *ciphertext = malloc((plaintextLength + 1) * sizeof(char));
    for (int i = 0; i < plaintextLength; i++) {
        ciphertext[i] = ((plaintext[i] - 'a') + (key[i % keyLength] - 'a')) % 26 + 'a'; // perform encryption
    }
    ciphertext[plaintextLength] = '\0'; // terminate the string
    return ciphertext;
}

/* This function performs decryption using the key provided */
char *decrypt(char *ciphertext, char *key) {
    int ciphertextLength = strlen(ciphertext);
    int keyLength = strlen(key);
    char *plaintext = malloc((ciphertextLength + 1) * sizeof(char));
    for (int i = 0; i < ciphertextLength; i++) {
        plaintext[i] = ((ciphertext[i] - 'a') - (key[i % keyLength] - 'a') + 26) % 26 + 'a'; // perform decryption
    }
    plaintext[ciphertextLength] = '\0'; // terminate the string
    return plaintext;
}

int main() {
    char plaintext[] = "hello world";
    int keyLength = 10;
    char *key = generateKey(keyLength);
    printf("Key: %s\n", key);

    char *ciphertext = encrypt(plaintext, key);
    printf("Ciphertext: %s\n", ciphertext);

    char *decryptedText = decrypt(ciphertext, key);
    printf("Decrypted text: %s\n", decryptedText);

    free(key);
    free(ciphertext);
    free(decryptedText);

    return 0;
}