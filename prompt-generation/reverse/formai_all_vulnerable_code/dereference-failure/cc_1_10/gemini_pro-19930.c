//GEMINI-pro DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 100

// Define the number of passwords to store in the database
#define MAX_PASSWORD_COUNT 100

// Define the structure of a password entry
typedef struct PasswordEntry {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

// Define the structure of the password database
typedef struct PasswordDatabase {
    PasswordEntry passwords[MAX_PASSWORD_COUNT];
    int count;
} PasswordDatabase;

// Create a new password database
PasswordDatabase* createPasswordDatabase() {
    PasswordDatabase* database = (PasswordDatabase*)malloc(sizeof(PasswordDatabase));
    database->count = 0;
    return database;
}

// Add a new password entry to the database
void addPasswordEntry(PasswordDatabase* database, PasswordEntry entry) {
    if (database->count < MAX_PASSWORD_COUNT) {
        database->passwords[database->count] = entry;
        database->count++;
    }
}

// Find a password entry in the database by website and username
PasswordEntry* findPasswordEntry(PasswordDatabase* database, char* website, char* username) {
    for (int i = 0; i < database->count; i++) {
        if (strcmp(database->passwords[i].website, website) == 0 && strcmp(database->passwords[i].username, username) == 0) {
            return &database->passwords[i];
        }
    }
    return NULL;
}

// Delete a password entry from the database by website and username
void deletePasswordEntry(PasswordDatabase* database, char* website, char* username) {
    for (int i = 0; i < database->count; i++) {
        if (strcmp(database->passwords[i].website, website) == 0 && strcmp(database->passwords[i].username, username) == 0) {
            for (int j = i + 1; j < database->count; j++) {
                database->passwords[j - 1] = database->passwords[j];
            }
            database->count--;
            return;
        }
    }
}

// Print the password database to the console
void printPasswordDatabase(PasswordDatabase* database) {
    for (int i = 0; i < database->count; i++) {
        printf("%s %s %s\n", database->passwords[i].website, database->passwords[i].username, database->passwords[i].password);
    }
}

// Destroy the password database and free all allocated memory
void destroyPasswordDatabase(PasswordDatabase* database) {
    free(database);
}

// Main function
int main() {
    // Create a new password database
    PasswordDatabase* database = createPasswordDatabase();

    // Add some password entries to the database
    addPasswordEntry(database, (PasswordEntry){"www.google.com", "john", "password123"});
    addPasswordEntry(database, (PasswordEntry){"www.amazon.com", "mary", "password456"});
    addPasswordEntry(database, (PasswordEntry){"www.facebook.com", "bob", "password789"});

    // Print the password database to the console
    printPasswordDatabase(database);

    // Find a password entry in the database by website and username
    PasswordEntry* entry = findPasswordEntry(database, "www.google.com", "john");
    if (entry != NULL) {
        printf("Found password entry: %s %s %s\n", entry->website, entry->username, entry->password);
    } else {
        printf("Password entry not found.\n");
    }

    // Delete a password entry from the database by website and username
    deletePasswordEntry(database, "www.amazon.com", "mary");

    // Print the password database to the console
    printPasswordDatabase(database);

    // Destroy the password database and free all allocated memory
    destroyPasswordDatabase(database);

    return 0;
}