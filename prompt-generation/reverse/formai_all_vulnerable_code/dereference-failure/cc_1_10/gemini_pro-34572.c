//GEMINI-pro DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 100

// Define the number of password entries
#define NUM_PASSWORDS 5

// Define the password entry structure
typedef struct {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} password_entry;

// Define the password manager structure
typedef struct {
    password_entry entries[NUM_PASSWORDS];
    int num_entries;
} password_manager;

// Create a new password manager
password_manager *new_password_manager() {
    password_manager *pm = malloc(sizeof(password_manager));
    pm->num_entries = 0;
    return pm;
}

// Add a new password entry to the password manager
void add_password_entry(password_manager *pm, char *username, char *password) {
    if (pm->num_entries >= NUM_PASSWORDS) {
        printf("Error: Password manager is full\n");
        return;
    }

    strcpy(pm->entries[pm->num_entries].username, username);
    strcpy(pm->entries[pm->num_entries].password, password);
    pm->num_entries++;
}

// Get a password entry from the password manager
password_entry *get_password_entry(password_manager *pm, char *username) {
    for (int i = 0; i < pm->num_entries; i++) {
        if (strcmp(pm->entries[i].username, username) == 0) {
            return &pm->entries[i];
        }
    }

    return NULL;
}

// Delete a password entry from the password manager
void delete_password_entry(password_manager *pm, char *username) {
    for (int i = 0; i < pm->num_entries; i++) {
        if (strcmp(pm->entries[i].username, username) == 0) {
            for (int j = i + 1; j < pm->num_entries; j++) {
                pm->entries[j - 1] = pm->entries[j];
            }

            pm->num_entries--;
            return;
        }
    }

    printf("Error: Password entry not found\n");
}

// Print the password manager
void print_password_manager(password_manager *pm) {
    for (int i = 0; i < pm->num_entries; i++) {
        printf("%s: %s\n", pm->entries[i].username, pm->entries[i].password);
    }
}

// Main function
int main() {
    // Create a new password manager
    password_manager *pm = new_password_manager();

    // Add some password entries to the password manager
    add_password_entry(pm, "user1", "password1");
    add_password_entry(pm, "user2", "password2");
    add_password_entry(pm, "user3", "password3");

    // Print the password manager
    print_password_manager(pm);

    // Get a password entry from the password manager
    password_entry *pe = get_password_entry(pm, "user2");
    if (pe != NULL) {
        printf("Password for user2: %s\n", pe->password);
    } else {
        printf("Error: Password entry not found\n");
    }

    // Delete a password entry from the password manager
    delete_password_entry(pm, "user3");

    // Print the password manager
    print_password_manager(pm);

    // Free the password manager
    free(pm);

    return 0;
}