//GEMINI-pro DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

// Define the structure of a password entry
typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_entry;

// Define the structure of the password manager
typedef struct {
    password_entry passwords[MAX_PASSWORDS];
    int num_passwords;
} password_manager;

// Create a new password manager
password_manager* create_password_manager() {
    password_manager* pm = malloc(sizeof(password_manager));
    pm->num_passwords = 0;
    return pm;
}

// Add a new password entry to the password manager
void add_password_entry(password_manager* pm, char* username, char* password) {
    strcpy(pm->passwords[pm->num_passwords].username, username);
    strcpy(pm->passwords[pm->num_passwords].password, password);
    pm->num_passwords++;
}

// Get a password entry from the password manager by username
password_entry* get_password_entry(password_manager* pm, char* username) {
    for (int i = 0; i < pm->num_passwords; i++) {
        if (strcmp(pm->passwords[i].username, username) == 0) {
            return &pm->passwords[i];
        }
    }
    return NULL;
}

// Delete a password entry from the password manager by username
void delete_password_entry(password_manager* pm, char* username) {
    for (int i = 0; i < pm->num_passwords; i++) {
        if (strcmp(pm->passwords[i].username, username) == 0) {
            for (int j = i; j < pm->num_passwords - 1; j++) {
                pm->passwords[j] = pm->passwords[j + 1];
            }
            pm->num_passwords--;
            return;
        }
    }
}

// Print all password entries in the password manager
void print_password_manager(password_manager* pm) {
    for (int i = 0; i < pm->num_passwords; i++) {
        printf("%s: %s\n", pm->passwords[i].username, pm->passwords[i].password);
    }
}

// Main function
int main() {
    // Create a new password manager
    password_manager* pm = create_password_manager();

    // Add some password entries to the password manager
    add_password_entry(pm, "user1", "password1");
    add_password_entry(pm, "user2", "password2");
    add_password_entry(pm, "user3", "password3");

    // Get a password entry from the password manager by username
    password_entry* pe = get_password_entry(pm, "user2");
    if (pe != NULL) {
        printf("Username: %s\n", pe->username);
        printf("Password: %s\n", pe->password);
    } else {
        printf("No password entry found for user2.\n");
    }

    // Delete a password entry from the password manager by username
    delete_password_entry(pm, "user3");

    // Print all password entries in the password manager
    print_password_manager(pm);

    // Free the memory allocated for the password manager
    free(pm);

    return 0;
}