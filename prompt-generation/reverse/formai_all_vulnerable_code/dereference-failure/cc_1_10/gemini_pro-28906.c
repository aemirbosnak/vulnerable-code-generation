//GEMINI-pro DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *username;
    char *password;
} PasswordEntry;

// Create a new password entry.
PasswordEntry *new_password_entry(char *username, char *password) {
    PasswordEntry *entry = malloc(sizeof(PasswordEntry));
    entry->username = strdup(username);
    entry->password = strdup(password);
    printf("Created password for %s", username);
    return entry;
}

// Delete a password entry.
void delete_password_entry(PasswordEntry *entry) {
    free(entry->username);
    free(entry->password);
    free(entry);
}

// Get the username for a password entry.
char *get_username(PasswordEntry *entry) {
    return entry->username;
}

// Get the password for a password entry.
char *get_password(PasswordEntry *entry) {
    return entry->password;
}

// Set the password for a password entry.
void set_password(PasswordEntry *entry, char *password) {
    free(entry->password);
    entry->password = strdup(password);
    printf("Password set for %s", get_username(entry));
}

// Print a password entry.
void print_password_entry(PasswordEntry *entry) {
    printf("Username: %s, Password: %s", get_username(entry), get_password(entry));
}

// Main function.
int main() {
    // Create a new password entry.
    PasswordEntry *entry = new_password_entry("username", "password");

    // Get the username and password for the entry.
    char *username = get_username(entry);
    char *password = get_password(entry);

    // Print the username and password.
    printf("Username: %s, Password: %s", username, password);

    // Set a new password for the entry.
    set_password(entry, "newpassword");

    // Get the new password for the entry.
    password = get_password(entry);

    // Print the new password.
    printf("New Password: %s", password);

    // Delete the password entry.
    delete_password_entry(entry);

    return 0;
}