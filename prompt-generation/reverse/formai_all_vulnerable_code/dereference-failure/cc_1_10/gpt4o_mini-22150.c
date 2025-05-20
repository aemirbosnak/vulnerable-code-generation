//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random key
void generate_key(char *key, int length) {
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        key[i] = characters[rand() % (sizeof(characters) - 1)];
    }
    key[length] = '\0';
}

// Function to encrypt the plaintext using Vigenère cipher
void encrypt(char *plaintext, char *key, char *ciphertext) {
    int len_plaintext = strlen(plaintext);
    int len_key = strlen(key);
    
    for (int i = 0, j = 0; i < len_plaintext; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = (plaintext[i] + key[j % len_key] - 2 * 'A') % 26 + 'A';
            j++;
        } else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = (plaintext[i] + key[j % len_key] - 2 * 'a') % 26 + 'a';
            j++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[len_plaintext] = '\0';
}

// Function to decrypt the ciphertext using Vigenère cipher
void decrypt(char *ciphertext, char *key, char *plaintext) {
    int len_ciphertext = strlen(ciphertext);
    int len_key = strlen(key);

    for (int i = 0, j = 0; i < len_ciphertext; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = (ciphertext[i] - key[j % len_key] + 26) % 26 + 'A';
            j++;
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = (ciphertext[i] - key[j % len_key] + 26) % 26 + 'a';
            j++;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[len_ciphertext] = '\0';
}

// Function to calculate frequencies of letters in the text
void calculate_frequency(char *text, int *frequency) {
    for (int i = 0; text[i]; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            frequency[text[i] - 'A']++;
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            frequency[text[i] - 'a']++;
        }
    }
}

// Function to print frequency statistics
void print_frequency_statistics(int *frequency) {
    printf("Letter Frequencies:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", i + 'A', frequency[i]);
    }
}

// Main function
int main() {
    srand(time(0)); // Seed for random number generator

    char plaintext[256];
    char key[32];
    char ciphertext[256];
    char decryptedtext[256];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline character

    int key_length;
    printf("Enter the length of the key: ");
    scanf("%d", &key_length);
    
    generate_key(key, key_length);
    printf("Generated Key: %s\n", key);

    // Encrypt the plaintext
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted Ciphertext: %s\n", ciphertext);

    // Decrypting the ciphertext
    decrypt(ciphertext, key, decryptedtext);
    printf("Decrypted Plaintext: %s\n", decryptedtext);

    // Calculate frequency statistics
    int frequency[26] = {0};
    calculate_frequency(ciphertext, frequency);
    print_frequency_statistics(frequency);

    return 0;
}