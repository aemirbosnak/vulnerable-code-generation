//GEMINI-pro DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store a password entry
struct password_entry {
    char *name;
    char *password;
};

// Structure to store the password database
struct password_database {
    struct password_entry *entries;
    int num_entries;
};

// Function to create a new password database
struct password_database *create_password_database() {
    struct password_database *db = malloc(sizeof(struct password_database));
    db->entries = NULL;
    db->num_entries = 0;
    return db;
}

// Function to add a new password entry to the database
void add_password_entry(struct password_database *db, char *name, char *password) {
    // Allocate memory for the new entry
    struct password_entry *entry = malloc(sizeof(struct password_entry));

    // Copy the name and password into the new entry
    entry->name = strdup(name);
    entry->password = strdup(password);

    // Add the new entry to the database
    db->entries = realloc(db->entries, (db->num_entries + 1) * sizeof(struct password_entry));
    db->entries[db->num_entries++] = *entry;
}

// Function to find a password entry in the database
struct password_entry *find_password_entry(struct password_database *db, char *name) {
    for (int i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].name, name) == 0) {
            return &db->entries[i];
        }
    }
    return NULL;
}

// Function to print the password database
void print_password_database(struct password_database *db) {
    for (int i = 0; i < db->num_entries; i++) {
        printf("%s: %s\n", db->entries[i].name, db->entries[i].password);
    }
}

// Main function
int main() {
    // Create a new password database
    struct password_database *db = create_password_database();

    // Add some password entries to the database
    add_password_entry(db, "user1", "password1");
    add_password_entry(db, "user2", "password2");
    add_password_entry(db, "user3", "password3");

    // Print the password database
    print_password_database(db);

    // Find a password entry in the database
    struct password_entry *entry = find_password_entry(db, "user2");
    if (entry != NULL) {
        printf("Found password entry: %s: %s\n", entry->name, entry->password);
    } else {
        printf("Password entry not found.\n");
    }

    // Free the memory allocated for the password database
    for (int i = 0; i < db->num_entries; i++) {
        free(db->entries[i].name);
        free(db->entries[i].password);
    }
    free(db->entries);
    free(db);

    return 0;
}