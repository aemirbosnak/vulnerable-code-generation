//GEMINI-pro DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password.
#define MAX_PASSWORD_LENGTH 256

// Define the maximum number of passwords that can be stored.
#define MAX_PASSWORDS 10

// Define the structure of a password entry.
typedef struct password_entry {
    char *name;
    char *password;
} password_entry;

// Create an array of password entries.
password_entry passwords[MAX_PASSWORDS];

// The number of passwords that have been stored.
int num_passwords = 0;

// Function to add a new password to the array.
void add_password(char *name, char *password) {
    // Check if the array is full.
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: The password array is full.\n");
        return;
    }

    // Allocate memory for the new password entry.
    passwords[num_passwords].name = malloc(strlen(name) + 1);
    passwords[num_passwords].password = malloc(strlen(password) + 1);

    // Copy the name and password into the new entry.
    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].password, password);

    // Increment the number of passwords.
    num_passwords++;
}

// Function to find a password by name.
char *find_password(char *name) {
    // Iterate over the array of passwords.
    for (int i = 0; i < num_passwords; i++) {
        // Check if the name matches the given name.
        if (strcmp(passwords[i].name, name) == 0) {
            // Return the password.
            return passwords[i].password;
        }
    }

    // If the password was not found, return NULL.
    return NULL;
}

// Function to delete a password by name.
void delete_password(char *name) {
    // Iterate over the array of passwords.
    for (int i = 0; i < num_passwords; i++) {
        // Check if the name matches the given name.
        if (strcmp(passwords[i].name, name) == 0) {
            // Free the memory for the password entry.
            free(passwords[i].name);
            free(passwords[i].password);

            // Shift the remaining passwords down one position.
            for (int j = i + 1; j < num_passwords; j++) {
                passwords[j - 1] = passwords[j];
            }

            // Decrement the number of passwords.
            num_passwords--;

            // Return.
            return;
        }
    }

    // If the password was not found, do nothing.
}

// Function to print all of the passwords.
void print_passwords() {
    // Iterate over the array of passwords.
    for (int i = 0; i < num_passwords; i++) {
        // Print the name and password.
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

// Main function.
int main() {
    // Add some passwords to the array.
    add_password("Facebook", "my_facebook_password");
    add_password("Google", "my_google_password");
    add_password("Amazon", "my_amazon_password");

    // Print all of the passwords.
    print_passwords();

    // Find a password by name.
    char *password = find_password("Google");

    // Print the password.
    printf("The password for Google is: %s\n", password);

    // Delete a password by name.
    delete_password("Amazon");

    // Print all of the passwords.
    print_passwords();

    return 0;
}