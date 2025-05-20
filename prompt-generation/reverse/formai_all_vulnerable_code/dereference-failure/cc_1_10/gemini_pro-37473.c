//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 256

// Define the maximum number of passwords to store
#define MAX_PASSWORDS 10

// Define the structure of a password entry
typedef struct {
    char *username;
    char *password;
} password_entry;

// Create an array of password entries
password_entry passwords[MAX_PASSWORDS];

// The number of passwords stored in the array
int num_passwords = 0;

// Function to add a password entry to the array
void add_password(char *username, char *password) {
    // Check if the array is full
    if (num_passwords >= MAX_PASSWORDS) {
        printf("The password array is full. Cannot add more passwords.\n");
        return;
    }

    // Allocate memory for the username and password
    passwords[num_passwords].username = malloc(strlen(username) + 1);
    passwords[num_passwords].password = malloc(strlen(password) + 1);

    // Copy the username and password into the array
    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    // Increment the number of passwords stored in the array
    num_passwords++;
}

// Function to find a password entry in the array
password_entry *find_password(char *username) {
    // Loop through the array of passwords
    for (int i = 0; i < num_passwords; i++) {
        // Check if the username matches the given username
        if (strcmp(passwords[i].username, username) == 0) {
            // Return the password entry
            return &passwords[i];
        }
    }

    // If no password entry was found, return NULL
    return NULL;
}

// Function to display all the passwords in the array
void display_passwords() {
    // Loop through the array of passwords
    for (int i = 0; i < num_passwords; i++) {
        // Print the username and password
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n\n", passwords[i].password);
    }
}

// Function to free the memory allocated for the passwords
void free_passwords() {
    // Loop through the array of passwords
    for (int i = 0; i < num_passwords; i++) {
        // Free the memory allocated for the username and password
        free(passwords[i].username);
        free(passwords[i].password);
    }
}

// Main function
int main() {
    // Add some passwords to the array
    add_password("Sherlock Holmes", "Elementary, my dear Watson!");
    add_password("Dr. Watson", "I say old chap!");
    add_password("Mycroft Holmes", "The game is afoot!");

    // Find a password entry in the array
    password_entry *mycroft_password = find_password("Mycroft Holmes");

    // Display the password entry
    printf("Mycroft Holmes's password: %s\n", mycroft_password->password);

    // Display all the passwords in the array
    display_passwords();

    // Free the memory allocated for the passwords
    free_passwords();

    return 0;
}