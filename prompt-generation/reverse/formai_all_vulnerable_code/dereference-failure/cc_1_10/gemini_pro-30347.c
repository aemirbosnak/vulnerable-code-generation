//GEMINI-pro DATASET v1.0 Category: Password management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of passwords to store
#define MAX_PASSWORDS 100

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 20

// Define the data structure for a password
typedef struct {
    char *username;
    char *password;
} Password;

// Create an array of passwords
Password passwords[MAX_PASSWORDS];

// Create a counter for the number of passwords stored
int numPasswords = 0;

// Function to add a new password to the array
void addPassword(char *username, char *password) {
    // Check if the array is full
    if (numPasswords == MAX_PASSWORDS) {
        printf("Error: Password array is full\n");
        return;
    }

    // Allocate memory for the username and password
    passwords[numPasswords].username = malloc(strlen(username) + 1);
    passwords[numPasswords].password = malloc(strlen(password) + 1);

    // Copy the username and password into the array
    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    // Increment the number of passwords stored
    numPasswords++;
}

// Function to generate a random password
char *generatePassword() {
    // Create a string to store the password
    char *password = malloc(MAX_PASSWORD_LENGTH + 1);

    // Loop through the characters in the password
    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        // Generate a random character
        int randomCharacter = rand() % 26 + 'a';

        // Add the random character to the password
        password[i] = randomCharacter;
    }

    // Add a null terminator to the end of the password
    password[MAX_PASSWORD_LENGTH] = '\0';

    // Return the password
    return password;
}

// Function to find a password by username
char *findPasswordByUsername(char *username) {
    // Loop through the array of passwords
    for (int i = 0; i < numPasswords; i++) {
        // Check if the username matches
        if (strcmp(passwords[i].username, username) == 0) {
            // Return the password
            return passwords[i].password;
        }
    }

    // Return NULL if the username was not found
    return NULL;
}

// Function to print all the passwords
void printAllPasswords() {
    // Loop through the array of passwords
    for (int i = 0; i < numPasswords; i++) {
        // Print the username and password
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

// Function to delete a password by username
void deletePasswordByUsername(char *username) {
    // Loop through the array of passwords
    for (int i = 0; i < numPasswords; i++) {
        // Check if the username matches
        if (strcmp(passwords[i].username, username) == 0) {
            // Free the memory allocated for the username and password
            free(passwords[i].username);
            free(passwords[i].password);

            // Shift the remaining passwords down one position in the array
            for (int j = i + 1; j < numPasswords; j++) {
                passwords[j - 1] = passwords[j];
            }

            // Decrement the number of passwords stored
            numPasswords--;

            // Return
            return;
        }
    }

    // Print an error message if the username was not found
    printf("Error: Username not found\n");
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Add some sample passwords to the array
    addPassword("alice", "password123");
    addPassword("bob", "password456");
    addPassword("charlie", "password789");

    // Print all the passwords
    printAllPasswords();

    // Find the password for a specific username
    char *password = findPasswordByUsername("alice");
    printf("Password for alice: %s\n", password);

    // Generate a random password
    char *randomPassword = generatePassword();
    printf("Random password: %s\n", randomPassword);

    // Delete a password by username
    deletePasswordByUsername("charlie");

    // Print all the passwords
    printAllPasswords();

    return 0;
}