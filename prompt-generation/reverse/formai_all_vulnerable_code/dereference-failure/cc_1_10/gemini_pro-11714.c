//GEMINI-pro DATASET v1.0 Category: Password management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encrypt a password using a simple XOR cipher
char *encrypt(char *password, char *key) {
    int password_len = strlen(password);
    int key_len = strlen(key);
    char *encrypted_password = malloc(password_len + 1);
    for (int i = 0; i < password_len; i++) {
        encrypted_password[i] = password[i] ^ key[i % key_len];
    }
    encrypted_password[password_len] = '\0';
    return encrypted_password;
}

// Decrypt a password using a simple XOR cipher
char *decrypt(char *password, char *key) {
    int password_len = strlen(password);
    int key_len = strlen(key);
    char *decrypted_password = malloc(password_len + 1);
    for (int i = 0; i < password_len; i++) {
        decrypted_password[i] = password[i] ^ key[i % key_len];
    }
    decrypted_password[password_len] = '\0';
    return decrypted_password;
}

// Generate a random password of a given length
char *generate_password(int length) {
    char *password = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        password[i] = rand() % 26 + 'a';
    }
    password[length] = '\0';
    return password;
}

// Print a menu of options for the user to choose from
void print_menu() {
    printf("1. Encrypt a password\n");
    printf("2. Decrypt a password\n");
    printf("3. Generate a random password\n");
    printf("4. Quit\n");
}

// Get the user's choice from the menu
int get_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Print a welcome message
    printf("Welcome to the Password Manager!\n");

    // Loop until the user chooses to quit
    int choice;
    do {
        // Print the menu
        print_menu();

        // Get the user's choice
        choice = get_choice();

        // Perform the selected action
        switch (choice) {
            case 1:
                // Encrypt a password
                printf("Enter the password to encrypt: ");
                char *password = malloc(100);
                scanf("%s", password);
                printf("Enter the encryption key: ");
                char *key = malloc(100);
                scanf("%s", key);
                char *encrypted_password = encrypt(password, key);
                printf("Encrypted password: %s\n", encrypted_password);
                free(password);
                free(key);
                free(encrypted_password);
                break;
            case 2:
                // Decrypt a password
                printf("Enter the password to decrypt: ");
                password = malloc(100);
                scanf("%s", password);
                printf("Enter the decryption key: ");
                key = malloc(100);
                scanf("%s", key);
                char *decrypted_password = decrypt(password, key);
                printf("Decrypted password: %s\n", decrypted_password);
                free(password);
                free(key);
                free(decrypted_password);
                break;
            case 3:
                // Generate a random password
                printf("Enter the length of the password to generate: ");
                int length;
                scanf("%d", &length);
                char *random_password = generate_password(length);
                printf("Random password: %s\n", random_password);
                free(random_password);
                break;
            case 4:
                // Quit
                printf("Thank you for using the Password Manager!\n");
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}