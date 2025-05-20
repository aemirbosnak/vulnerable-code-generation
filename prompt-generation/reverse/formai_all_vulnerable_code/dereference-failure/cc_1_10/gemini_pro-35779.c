//GEMINI-pro DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declare the password manager struct
typedef struct {
    char *username;
    char *password;
} PasswordManager;

// Declare the functions
void add_password(PasswordManager *pm, char *username, char *password);
void print_passwords(PasswordManager *pm);
void free_passwords(PasswordManager *pm);

// Main function
int main() {
    // Create a new password manager
    PasswordManager pm;
    pm.username = NULL;
    pm.password = NULL;

    // Add some passwords to the manager
    add_password(&pm, "admin", "password");
    add_password(&pm, "user1", "password1");
    add_password(&pm, "user2", "password2");

    // Print the passwords
    print_passwords(&pm);

    // Free the passwords
    free_passwords(&pm);

    return 0;
}

// Add a password to the manager
void add_password(PasswordManager *pm, char *username, char *password) {
    // Allocate memory for the username and password
    pm->username = malloc(strlen(username) + 1);
    pm->password = malloc(strlen(password) + 1);

    // Copy the username and password into the manager
    strcpy(pm->username, username);
    strcpy(pm->password, password);
}

// Print the passwords
void print_passwords(PasswordManager *pm) {
    // Print the username and password for each user
    for (int i = 0; i < pm->username; i++) {
        printf("Username: %s\n", pm->username[i]);
        printf("Password: %s\n", pm->password[i]);
        printf("\n");
    }
}

// Free the passwords
void free_passwords(PasswordManager *pm) {
    // Free the memory allocated for the username and password
    free(pm->username);
    free(pm->password);
}