//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// XOR encryption function
void encrypt(char *str, char *key) {
    int keyLen = strlen(key);
    for (int i = 0; i < strlen(str); i++) {
        str[i] ^= key[i % keyLen];
    }
}

// Decryption function
void decrypt(char *str, char *key) {
    encrypt(str, key);
}

// XOR encryption with random key
void randomEncrypt(char *str) {
    // Generate a random key
    char key[16];
    for (int i = 0; i < 16; i++) {
        key[i] = rand() % 256;
    }

    // Encrypt the string
    encrypt(str, key);

    // Print the encrypted string and key
    printf("Encrypted string: %s\n", str);
    printf("Encryption key: ");
    for (int i = 0; i < 16; i++) {
        printf("%02X", key[i]);
    }
    printf("\n");
}

// XOR decryption with user-provided key
void userDecrypt(char *str) {
    // Get the key from the user
    char key[16];
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Decrypt the string
    decrypt(str, key);

    // Print the decrypted string
    printf("Decrypted string: %s\n", str);
}

int main() {
    // Sample string to encrypt
    char str[] = "This is a secret message.";

    // Encrypt the string using a fixed key
    char key[] = "my_secret_key";
    encrypt(str, key);

    // Print the encrypted string
    printf("Encrypted string: %s\n", str);

    // Decrypt the string using the same key
    decrypt(str, key);

    // Print the decrypted string
    printf("Decrypted string: %s\n\n", str);

    // Encrypt the string using a random key
    randomEncrypt(str);

    // Decrypt the string using the user-provided key
    userDecrypt(str);

    return 0;
}