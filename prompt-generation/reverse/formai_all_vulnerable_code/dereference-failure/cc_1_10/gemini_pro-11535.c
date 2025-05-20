//GEMINI-pro DATASET v1.0 Category: Password management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

// Structure to store a password
typedef struct {
    char *username;
    char *password;
} Password;

// Array to store passwords
Password passwords[MAX_PASSWORDS];

// Number of passwords stored
int numPasswords = 0;

// Function to add a password to the array
void addPassword(char *username, char *password) {
    // Check if the array is full
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Password array is full.\n");
        return;
    }

    // Allocate memory for the new password
    passwords[numPasswords].username = malloc(strlen(username) + 1);
    passwords[numPasswords].password = malloc(strlen(password) + 1);

    // Copy the username and password into the array
    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    // Increment the number of passwords stored
    numPasswords++;
}

// Function to search for a password in the array
char *searchPassword(char *username) {
    // Loop through the array of passwords
    for (int i = 0; i < numPasswords; i++) {
        // Check if the username matches
        if (strcmp(passwords[i].username, username) == 0) {
            // Return the password
            return passwords[i].password;
        }
    }

    // Password not found
    return NULL;
}

// Function to delete a password from the array
void deletePassword(char *username) {
    // Loop through the array of passwords
    for (int i = 0; i < numPasswords; i++) {
        // Check if the username matches
        if (strcmp(passwords[i].username, username) == 0) {
            // Free the memory for the password
            free(passwords[i].username);
            free(passwords[i].password);

            // Shift the remaining passwords down one
            for (int j = i; j < numPasswords - 1; j++) {
                passwords[j] = passwords[j + 1];
            }

            // Decrement the number of passwords stored
            numPasswords--;

            // Return
            return;
        }
    }

    // Password not found
    printf("Error: Password not found.\n");
}

// Function to print the passwords in the array
void printPasswords() {
    // Loop through the array of passwords
    for (int i = 0; i < numPasswords; i++) {
        // Print the username and password
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

// Main function
int main() {
    // Add some passwords to the array
    addPassword("alice", "password1");
    addPassword("bob", "password2");
    addPassword("charlie", "password3");

    // Search for a password
    char *password = searchPassword("alice");
    if (password != NULL) {
        printf("Password for alice: %s\n", password);
    } else {
        printf("Password not found.\n");
    }

    // Delete a password
    deletePassword("bob");

    // Print the passwords
    printPasswords();

    return 0;
}