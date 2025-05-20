//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a character
char encrypt(char ch, int key) {
    return (ch + key) % 128;
}

// Function to decrypt a character
char decrypt(char ch, int key) {
    return (ch - key) % 128;
}

// Function to encrypt a string
char *encrypt_string(char *str, int key) {
    char *encrypted_str = malloc(strlen(str) + 1);
    int i;
    for (i = 0; i < strlen(str); i++) {
        encrypted_str[i] = encrypt(str[i], key);
    }
    encrypted_str[i] = '\0';
    return encrypted_str;
}

// Function to decrypt a string
char *decrypt_string(char *str, int key) {
    char *decrypted_str = malloc(strlen(str) + 1);
    int i;
    for (i = 0; i < strlen(str); i++) {
        decrypted_str[i] = decrypt(str[i], key);
    }
    decrypted_str[i] = '\0';
    return decrypted_str;
}

// Main function
int main() {
    // Get the input string
    char str[100];
    printf("Enter the string to be encrypted: ");
    scanf("%s", str);

    // Get the encryption key
    int key;
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // Encrypt the string
    char *encrypted_str = encrypt_string(str, key);
    printf("Encrypted string: %s\n", encrypted_str);

    // Decrypt the string
    char *decrypted_str = decrypt_string(encrypted_str, key);
    printf("Decrypted string: %s\n", decrypted_str);

    return 0;
}