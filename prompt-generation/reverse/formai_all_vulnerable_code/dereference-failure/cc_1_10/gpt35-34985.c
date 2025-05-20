//FormAI DATASET v1.0 Category: Modern Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform encryption on a given string
char *encrypt(char *plain_text, int key) {
    int length = strlen(plain_text);
    char *cipher_text = (char *) malloc((length + 1) * sizeof(char));   //Allocate memory dynamically for cipher text
    int i;
    for (i = 0; i < length; i++) {
        if (plain_text[i] >= 'a' && plain_text[i] <= 'z') {  // If character is a lower case alphabet
            cipher_text[i] = ((plain_text[i] - 'a') + key) % 26 + 'a';
        } else if (plain_text[i] >= 'A' && plain_text[i] <= 'Z') {   // If character is an upper case alphabet
            cipher_text[i] = ((plain_text[i] - 'A') + key) % 26 + 'A';
        } else {   // If character is a space or some other special character
            cipher_text[i] = plain_text[i];
        }
    }
    cipher_text[length] = '\0';   // Add null terminator at the end of cipher text
    return cipher_text;
}

// Function to perform decryption on a given string
char *decrypt(char *cipher_text, int key) {
    int length = strlen(cipher_text);
    char *plain_text = (char *) malloc((length + 1) * sizeof(char));   //Allocate memory dynamically for plain text
    int i;
    for (i = 0; i < length; i++) {
        if (cipher_text[i] >= 'a' && cipher_text[i] <= 'z') {   // If character is a lower case alphabet
            plain_text[i] = ((cipher_text[i] - 'a') - key + 26) % 26 + 'a';
        } else if (cipher_text[i] >= 'A' && cipher_text[i] <= 'Z') {   // If character is an upper case alphabet
            plain_text[i] = ((cipher_text[i] - 'A') - key + 26) % 26 + 'A';
        } else {   // If character is a space or some other special character
            plain_text[i] = cipher_text[i];
        }
    }
    plain_text[length] = '\0';   // Add null terminator at the end of plain text
    return plain_text;
}

int main() {
    char input[1000];   // Input string
    int key;   // Key value for encryption/decryption
    char *encrypted_str;   // Encrypted string
    char *decrypted_str;   // Decrypted string

    // Get input string from user
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';   // Remove newline character from input

    // Get key value from user
    printf("Enter the key value: ");
    scanf("%d", &key);

    // Encrypt the input string using the given key
    encrypted_str = encrypt(input, key);
    printf("\nEncrypted string: %s", encrypted_str);

    // Decrypt the encrypted string using the given key
    decrypted_str = decrypt(encrypted_str, key);
    printf("\nDecrypted string: %s\n", decrypted_str);

    // Free the allocated memory
    free(encrypted_str);
    free(decrypted_str);

    return 0;
}