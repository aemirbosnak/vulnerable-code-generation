//GEMINI-pro DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a password entry
typedef struct {
    char *username;
    char *password;
    char *website;
} PasswordEntry;

// Array of password entries
PasswordEntry *passwords = NULL;

// Number of password entries
int num_passwords = 0;

// Function to add a password entry
void add_password(char *username, char *password, char *website) {
    // Allocate memory for the new entry
    passwords = realloc(passwords, (num_passwords + 1) * sizeof(PasswordEntry));

    // Store the entry in the array
    passwords[num_passwords].username = username;
    passwords[num_passwords].password = password;
    passwords[num_passwords].website = website;

    // Increment the number of password entries
    num_passwords++;
}

// Function to find a password entry by username and website
PasswordEntry *find_password(char *username, char *website) {
    // Iterate over the password entries
    for (int i = 0; i < num_passwords; i++) {
        // Check if the username and website match
        if (strcmp(passwords[i].username, username) == 0 && strcmp(passwords[i].website, website) == 0) {
            // Return the password entry
            return &passwords[i];
        }
    }

    // No matching password entry found
    return NULL;
}

// Function to print all password entries
void print_passwords() {
    // Iterate over the password entries
    for (int i = 0; i < num_passwords; i++) {
        // Print the password entry
        printf("%s:%s:%s\n", passwords[i].username, passwords[i].password, passwords[i].website);
    }
}

// Function to free the memory allocated for the password entries
void free_passwords() {
    // Iterate over the password entries
    for (int i = 0; i < num_passwords; i++) {
        // Free the memory for the username, password, and website
        free(passwords[i].username);
        free(passwords[i].password);
        free(passwords[i].website);
    }

    // Free the memory for the array of password entries
    free(passwords);
}

// Main function
int main() {
    // Add some password entries
    add_password("username1", "password1", "website1");
    add_password("username2", "password2", "website2");
    add_password("username3", "password3", "website3");

    // Find a password entry by username and website
    PasswordEntry *password = find_password("username1", "website1");

    // Print the found password entry
    if (password != NULL) {
        printf("Found password: %s:%s:%s\n", password->username, password->password, password->website);
    } else {
        printf("No matching password entry found.\n");
    }

    // Print all password entries
    printf("\nAll password entries:\n");
    print_passwords();

    // Free the memory allocated for the password entries
    free_passwords();

    return 0;
}