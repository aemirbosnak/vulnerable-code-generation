//FormAI DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define constants
#define MAX_PASSWORD_LENGTH 16
#define MAX_ATTEMPTS 3

// Function prototypes
void enterPassword(char *password);
int checkPassword(char *password, char *storedPassword);

int main() {
    char storedPassword[MAX_PASSWORD_LENGTH+1];
    int attempts = 0;

    // Prompt user to enter new password
    printf("Please create your password (maximum of %d characters):\n", MAX_PASSWORD_LENGTH);
    enterPassword(storedPassword);

    // Clear screen and prompt user to enter password to log in
    system("clear");
    printf("Welcome! Please enter your password to log in:\n");

    // Loop until user enters correct password or runs out of attempts
    while (attempts < MAX_ATTEMPTS) {
        char enteredPassword[MAX_PASSWORD_LENGTH+1];
        enterPassword(enteredPassword);

        if (checkPassword(enteredPassword, storedPassword)) {
            printf("Password accepted!\n");
            return 0;
        } else {
            attempts++;
            printf("Incorrect password. Please try again.\n");
        }
    }

    // If user has exceeded password attempts, lock their account
    printf("Too many failed attempts. Your account has been locked. Please contact customer support.\n");
    return 0;
}

// Function to prompt user to enter a password and store it in the given string
void enterPassword(char *password) {
    // Initialize password with null terminator
    *password = '\0';

    // Loop until user has entered a non-empty password
    while (*password == '\0') {
        // Read input from user
        fgets(password, MAX_PASSWORD_LENGTH+1, stdin);

        // Replace newline character with null terminator
        size_t len = strlen(password);
        if (password[len-1] == '\n') {
            password[len-1] = '\0';
        } else {
            // If input was too long, clear the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        // Check that password is not empty
        if (*password == '\0') {
            printf("Password cannot be empty. Please enter a password:\n");
        }
    }
}

// Function to check if the entered password matches the stored password
int checkPassword(char *password, char *storedPassword) {
    return strcmp(password, storedPassword) == 0;
}