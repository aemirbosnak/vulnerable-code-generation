//FormAI DATASET v1.0 Category: Password management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the password meets the criteria
bool checkPassword(char* password) {
    int length = strlen(password);
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;

    // Check if the password is at least 6 characters long
    if (length < 6) {
        return false;
    }

    // Check if the password contains uppercase letters, lowercase letters, and digits
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUpper = true;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            hasLower = true;
        } else if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = true;
        }
    }

    // Return true only if all three criteria are met
    return (hasUpper && hasLower && hasDigit);
}

// Function to encrypt the password using a simple XOR cipher
char* encryptPassword(char* password) {
    int length = strlen(password);
    char* encrypted = (char*)malloc(length + 1);

    for (int i = 0; i < length; i++) {
        encrypted[i] = password[i] ^ 0x12; // XOR with a fixed key
    }

    encrypted[length] = '\0';

    return encrypted;
}

int main() {
    // Ask the user to enter a password
    printf("Enter your password: ");
    char password[100];
    fgets(password, 100, stdin);

    // Remove the newline character from the password
    password[strcspn(password, "\n")] = '\0';

    // Check if the password meets the criteria
    if (!checkPassword(password)) {
        printf("Error: Password must be at least 6 characters long and contain uppercase letters, lowercase letters, and digits.\n");
        return 1;
    }

    // Encrypt the password
    char* encrypted = encryptPassword(password);

    // Zero out the original password
    memset(password, 0, sizeof(password));

    // Print the encrypted password
    printf("Encrypted password: %s\n", encrypted);

    // Zero out the encrypted password
    memset(encrypted, 0, strlen(encrypted));

    // Free the memory allocated for the encrypted password
    free(encrypted);

    return 0;
}