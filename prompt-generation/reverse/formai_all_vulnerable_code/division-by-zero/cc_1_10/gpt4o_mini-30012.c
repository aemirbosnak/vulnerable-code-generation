//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024
#define KEY_LEN 256

void generate_key(const char *password, char *key) {
    int pass_len = strlen(password);
    for (int i = 0; i < KEY_LEN; i++) {
        key[i] = password[i % pass_len];
    }
}

void encrypt(const char *plaintext, const char *key, char *ciphertext) {
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = (plaintext[i] + key[i]) % 256;  // Basic encryption
    }
    ciphertext[strlen(plaintext)] = '\0';
}

void decrypt(const char *ciphertext, const char *key, char *plaintext) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = (ciphertext[i] - key[i] + 256) % 256; // Basic decryption
    }
    plaintext[strlen(ciphertext)] = '\0';
}

void print_menu() {
    printf("\nEncryption Program Menu:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char password[KEY_LEN];
    char key[KEY_LEN];
    char plaintext[MAX_LEN];
    char ciphertext[MAX_LEN];
    
    int option;

    while (1) {
        print_menu();
        scanf("%d", &option);
        getchar(); // Clear newline character from buffer

        switch (option) {
            case 1: // Encrypt
                printf("Enter the password for the encryption: ");
                fgets(password, KEY_LEN, stdin);
                password[strcspn(password, "\n")] = '\0'; // Remove newline character

                generate_key(password, key);

                printf("Enter the plaintext message to encrypt: ");
                fgets(plaintext, MAX_LEN, stdin);
                plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

                encrypt(plaintext, key, ciphertext);

                printf("Encrypted message: ");
                for (int i = 0; i < strlen(plaintext); i++) {
                    printf("%02x", (unsigned char)ciphertext[i]); // Print in hex format
                }
                printf("\n");
                break;

            case 2: // Decrypt
                printf("Enter the password for the decryption: ");
                fgets(password, KEY_LEN, stdin);
                password[strcspn(password, "\n")] = '\0'; // Remove newline character

                generate_key(password, key);

                printf("Enter the ciphertext message in hex: ");
                char hex_input[MAX_LEN];
                fgets(hex_input, MAX_LEN, stdin);
                hex_input[strcspn(hex_input, "\n")] = '\0'; // Remove newline character

                for (int i = 0; i < strlen(hex_input) / 2; i++) {
                    sscanf(hex_input + 2 * i, "%2hhx", (unsigned char *)&ciphertext[i]);
                }
                ciphertext[strlen(hex_input) / 2] = '\0'; // Add null terminator

                decrypt(ciphertext, key, plaintext);
                printf("Decrypted message: %s\n", plaintext);
                break;

            case 3: // Exit
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}