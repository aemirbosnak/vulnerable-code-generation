//GEMINI-pro DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define data structures
typedef struct {
    char *website;
    char *username;
    char *password;
} PasswordEntry;

typedef struct {
    PasswordEntry *entries;
    int numEntries;
} PasswordManager;

// Create a new password manager
PasswordManager *createPasswordManager() {
    PasswordManager *manager = malloc(sizeof(PasswordManager));
    manager->entries = NULL;
    manager->numEntries = 0;
    return manager;
}

// Add a new password entry
void addPasswordEntry(PasswordManager *manager, char *website, char *username, char *password) {
    PasswordEntry *entry = malloc(sizeof(PasswordEntry));
    entry->website = strdup(website);
    entry->username = strdup(username);
    entry->password = strdup(password);

    manager->entries = realloc(manager->entries, (manager->numEntries + 1) * sizeof(PasswordEntry));
    manager->entries[manager->numEntries++] = *entry;
}

// Find a password entry by website
PasswordEntry *findPasswordEntry(PasswordManager *manager, char *website) {
    for (int i = 0; i < manager->numEntries; i++) {
        if (strcmp(manager->entries[i].website, website) == 0) {
            return &manager->entries[i];
        }
    }
    return NULL;
}

// Print all password entries
void printPasswordEntries(PasswordManager *manager) {
    for (int i = 0; i < manager->numEntries; i++) {
        printf("%s: %s, %s\n", manager->entries[i].website, manager->entries[i].username, manager->entries[i].password);
    }
}

// Free the memory allocated for a password entry
void freePasswordEntry(PasswordEntry *entry) {
    free(entry->website);
    free(entry->username);
    free(entry->password);
    free(entry);
}

// Free the memory allocated for a password manager
void freePasswordManager(PasswordManager *manager) {
    for (int i = 0; i < manager->numEntries; i++) {
        freePasswordEntry(&manager->entries[i]);
    }
    free(manager->entries);
    free(manager);
}

int main() {
    // Create a new password manager
    PasswordManager *manager = createPasswordManager();

    // Add some password entries
    addPasswordEntry(manager, "www.example.com", "john.doe", "secret123");
    addPasswordEntry(manager, "www.google.com", "jane.doe", "password123");
    addPasswordEntry(manager, "www.facebook.com", "mark.zuckerberg", "thefacebook123");

    // Find a password entry by website
    PasswordEntry *entry = findPasswordEntry(manager, "www.google.com");
    if (entry != NULL) {
        printf("Found password entry for %s: %s\n", entry->website, entry->password);
    } else {
        printf("No password entry found for www.google.com\n");
    }

    // Print all password entries
    printPasswordEntries(manager);

    // Free the memory allocated for the password manager
    freePasswordManager(manager);

    return 0;
}