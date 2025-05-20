//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Caesar cipher
char *caesar_cipher(char *str, int shift) {
    int len = strlen(str);
    char *encrypted = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        encrypted[i] = (str[i] + shift - 'a') % 26 + 'a';
    }
    encrypted[len] = '\0';
    return encrypted;
}

// Vigenere cipher
char *vigenere_cipher(char *str, char *key) {
    int len = strlen(str);
    int keylen = strlen(key);
    char *encrypted = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        encrypted[i] = (str[i] + key[i % keylen] - 'a') % 26 + 'a';
    }
    encrypted[len] = '\0';
    return encrypted;
}

// One-time pad cipher
char *one_time_pad_cipher(char *str, char *key) {
    int len = strlen(str);
    int keylen = strlen(key);
    char *encrypted = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        encrypted[i] = (str[i] ^ key[i % keylen]) & 0xff;
    }
    encrypted[len] = '\0';
    return encrypted;
}

// Display the menu and get the user's choice
int get_choice() {
    int choice;
    printf("Choose an encryption algorithm:\n");
    printf("1. Caesar cipher\n");
    printf("2. Vigenere cipher\n");
    printf("3. One-time pad cipher\n");
    printf("4. Exit\n");
    scanf("%d", &choice);
    return choice;
}

// Get the plaintext from the user
char *get_plaintext() {
    char *plaintext;
    printf("Enter the plaintext: ");
    scanf(" %[^\n]s", plaintext);
    return plaintext;
}

// Get the key from the user
char *get_key() {
    char *key;
    printf("Enter the key: ");
    scanf(" %[^\n]s", key);
    return key;
}

// Encrypt the plaintext using the specified algorithm
char *encrypt(int choice, char *plaintext, char *key) {
    char *encrypted;
    switch (choice) {
        case 1:
            encrypted = caesar_cipher(plaintext, key - 'a');
            break;
        case 2:
            encrypted = vigenere_cipher(plaintext, key);
            break;
        case 3:
            encrypted = one_time_pad_cipher(plaintext, key);
            break;
        default:
            printf("Invalid choice\n");
            return NULL;
    }
    return encrypted;
}

// Display the encrypted text
void display_encrypted(char *encrypted) {
    printf("Encrypted text: %s\n", encrypted);
}

int main() {
    int choice;
    char *plaintext, *key;
    while ((choice = get_choice()) != 4) {
        plaintext = get_plaintext();
        key = get_key();
        char *encrypted = encrypt(choice, plaintext, key);
        display_encrypted(encrypted);
    }
    return 0;
}