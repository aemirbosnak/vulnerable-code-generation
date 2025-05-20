//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 5
#define MAX_LENGTH 20

// Global variables
char passwords[MAX_PASSWORDS][MAX_LENGTH];
int numPasswords = 0;

// Function prototypes
void addPassword(char *password);
void listPasswords();
void deletePassword(int index);

int main() {
    // Welcome message
    printf("Welcome to the retro password manager!\n");

    // Prompt user to add passwords
    printf("Add a password:\n");

    // Loop until user exits
    while (1) {
        // Get password from user
        char password[MAX_LENGTH];
        printf("Password: ");
        fgets(password, MAX_LENGTH, stdin);

        // Add password to array
        addPassword(password);

        // List all passwords
        listPasswords();

        // User can delete passwords
        printf("Delete a password? (y/n): ");
        char deleteAnswer = getchar();

        // If user enters "y", delete the most recent password
        if (deleteAnswer == 'y') {
            deletePassword(numPasswords - 1);
        }
    }

    return 0;
}

// Function to add a password
void addPassword(char *password) {
    // Check if password is too long
    if (strlen(password) > MAX_LENGTH) {
        printf("Password too long! Maximum length is %d.\n", MAX_LENGTH);
        return;
    }

    // Check if password is already in the array
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(password, passwords[i]) == 0) {
            printf("Password already in the list!\n");
            return;
        }
    }

    // Add password to the end of the array
    strcpy(passwords[numPasswords], password);
    numPasswords++;

    // Print success message
    printf("Password added successfully!\n");
}

// Function to list all passwords
void listPasswords() {
    // Print header
    printf("Retro Password Manager\n");
    printf("-------------\n");

    // Print each password in the array
    for (int i = 0; i < numPasswords; i++) {
        printf("%d. %s\n", i + 1, passwords[i]);
    }

    // Print footer
    printf("\n");
}

// Function to delete a password
void deletePassword(int index) {
    // Check if index is valid
    if (index < 0 || index >= numPasswords) {
        printf("Invalid index! Must be between 1 and %d.\n", numPasswords);
        return;
    }

    // Delete the password at the specified index
    for (int i = index; i < numPasswords - 1; i++) {
        strcpy(passwords[i], passwords[i + 1]);
    }

    // Decrease the number of passwords
    numPasswords--;

    // Print success message
    printf("Password deleted successfully!\n");
}