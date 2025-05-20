//GEMINI-pro DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password.
#define MAX_PASSWORD_LENGTH 256

// Define the structure of a password entry.
struct password_entry {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// Define the structure of a password database.
struct password_database {
    struct password_entry *entries;
    int num_entries;
};

// Create a new password entry.
struct password_entry *create_password_entry(char *username, char *password) {
    struct password_entry *entry = malloc(sizeof(struct password_entry));
    if (entry == NULL) {
        return NULL;
    }

    strcpy(entry->username, username);
    strcpy(entry->password, password);

    return entry;
}

// Add a password entry to a password database.
void add_password_entry(struct password_database *database, struct password_entry *entry) {
    database->entries = realloc(database->entries, (database->num_entries + 1) * sizeof(struct password_entry));
    if (database->entries == NULL) {
        free(entry);
        return;
    }

    database->entries[database->num_entries] = *entry;
    database->num_entries++;
}

// Find a password entry in a password database.
struct password_entry *find_password_entry(struct password_database *database, char *username) {
    for (int i = 0; i < database->num_entries; i++) {
        if (strcmp(database->entries[i].username, username) == 0) {
            return &database->entries[i];
        }
    }

    return NULL;
}

// Delete a password entry from a password database.
void delete_password_entry(struct password_database *database, char *username) {
    for (int i = 0; i < database->num_entries; i++) {
        if (strcmp(database->entries[i].username, username) == 0) {
            free(&database->entries[i]);
            database->num_entries--;
            return;
        }
    }
}

// Print a password database.
void print_password_database(struct password_database *database) {
    for (int i = 0; i < database->num_entries; i++) {
        printf("%s: %s\n", database->entries[i].username, database->entries[i].password);
    }
}

// Free a password database.
void free_password_database(struct password_database *database) {
    for (int i = 0; i < database->num_entries; i++) {
        free(&database->entries[i]);
    }

    free(database->entries);
    free(database);
}

// Main function.
int main() {
    // Create a new password database.
    struct password_database *database = malloc(sizeof(struct password_database));
    if (database == NULL) {
        return 1;
    }

    database->entries = NULL;
    database->num_entries = 0;

    // Add some password entries to the database.
    add_password_entry(database, create_password_entry("admin", "password"));
    add_password_entry(database, create_password_entry("user1", "password1"));
    add_password_entry(database, create_password_entry("user2", "password2"));

    // Print the password database.
    print_password_database(database);

    // Find a password entry in the database.
    struct password_entry *entry = find_password_entry(database, "user1");
    if (entry != NULL) {
        printf("Found password entry: %s: %s\n", entry->username, entry->password);
    } else {
        printf("Password entry not found.\n");
    }

    // Delete a password entry from the database.
    delete_password_entry(database, "user2");

    // Print the password database.
    print_password_database(database);

    // Free the password database.
    free_password_database(database);

    return 0;
}