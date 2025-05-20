//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 128

// Simple XOR cipher function
void xor_cipher(char *input, char *output, char *key, int length) {
    for (int i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % strlen(key)];
    }
}

// Function to generate random key
void generate_key(char *key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = 'A' + rand() % 26; // Random character from A-Z
    }
    key[length] = '\0'; // Null-terminate the string
}

// Function to prompt for user input
void get_input(char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
}

// Function to display the menu
void display_menu() {
    printf("\n--- Simple XOR Cipher Menu ---\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Generate Random Key\n");
    printf("4. Exit\n");
    printf("------------------------------\n");
}

int main() {
    char input[256], output[256], key[KEY_SIZE + 1];
    int choice;
    srand(time(NULL)); // Seed for randomness

    while (1) {
        display_menu();
        get_input("Choose an option: ", input, sizeof(input));
        choice = atoi(input);

        switch (choice) {
            case 1: // Encrypt
                get_input("Enter text to encrypt: ", input, sizeof(input));
                get_input("Enter the key (or press Enter for random key): ", key, sizeof(key));
                if (key[0] == '\0') {
                    generate_key(key, KEY_SIZE);
                    printf("Generated key: %s\n", key);
                }
                xor_cipher(input, output, key, strlen(input));
                printf("Encrypted text: ");
                for (int i = 0; i < strlen(input); i++) {
                    printf("%02x", (unsigned char)output[i]);
                }
                printf("\n");
                break;

            case 2: // Decrypt
                get_input("Enter hex string to decrypt: ", input, sizeof(input));
                get_input("Enter the key: ", key, sizeof(key));
                int length = strlen(input) / 2;

                for (int i = 0; i < length; i++) {
                    sscanf(input + 2*i, "%2hhx", (unsigned char *)&output[i]); // convert hex to byte
                }
                xor_cipher(output, input, key, length);
                printf("Decrypted text: %s\n", input);
                break;

            case 3: // Generate random key
                generate_key(key, KEY_SIZE);
                printf("Randomly generated key: %s\n", key);
                break;

            case 4: // Exit
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}