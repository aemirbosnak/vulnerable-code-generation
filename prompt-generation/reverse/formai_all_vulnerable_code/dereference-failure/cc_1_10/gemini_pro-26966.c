//GEMINI-pro DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store a password entry
typedef struct {
    char *username;
    char *password;
    char *website;
} PasswordEntry;

// Create a new password entry
PasswordEntry *new_password_entry(char *username, char *password, char *website) {
    PasswordEntry *entry = malloc(sizeof(PasswordEntry));
    entry->username = strdup(username);
    entry->password = strdup(password);
    entry->website = strdup(website);
    return entry;
}

// Free a password entry
void free_password_entry(PasswordEntry *entry) {
    free(entry->username);
    free(entry->password);
    free(entry->website);
    free(entry);
}

// Print a password entry
void print_password_entry(PasswordEntry *entry) {
    printf("Username: %s\n", entry->username);
    printf("Password: %s\n", entry->password);
    printf("Website: %s\n", entry->website);
}

// Compare two password entries
int compare_password_entries(PasswordEntry *entry1, PasswordEntry *entry2) {
    return strcmp(entry1->username, entry2->username) == 0 &&
           strcmp(entry1->password, entry2->password) == 0 &&
           strcmp(entry1->website, entry2->website) == 0;
}

// Main function
int main() {
    // Create a list of password entries
    PasswordEntry *entries[] = {
        new_password_entry("username1", "password1", "website1"),
        new_password_entry("username2", "password2", "website2"),
        new_password_entry("username3", "password3", "website3"),
    };

    // Find a password entry by username and website
    char *username = "username2";
    char *website = "website2";
    PasswordEntry *found_entry = NULL;
    for (int i = 0; i < sizeof(entries) / sizeof(PasswordEntry *); i++) {
        if (strcmp(entries[i]->username, username) == 0 && strcmp(entries[i]->website, website) == 0) {
            found_entry = entries[i];
            break;
        }
    }

    // Print the found password entry
    if (found_entry != NULL) {
        print_password_entry(found_entry);
    } else {
        printf("No password entry found for username '%s' and website '%s'\n", username, website);
    }

    // Free the password entries
    for (int i = 0; i < sizeof(entries) / sizeof(PasswordEntry *); i++) {
        free_password_entry(entries[i]);
    }

    return 0;
}