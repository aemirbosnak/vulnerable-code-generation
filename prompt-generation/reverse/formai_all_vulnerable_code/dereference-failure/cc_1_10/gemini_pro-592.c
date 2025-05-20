//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A simple database entry
typedef struct {
    int id;
    char *name;
    char *email;
    char *phone;
} Entry;

// A database is a collection of entries
typedef struct {
    Entry *entries;
    int num_entries;
} Database;

// Create a new database
Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->entries = NULL;
    db->num_entries = 0;
    return db;
}

// Add an entry to the database
void add_entry(Database *db, Entry *entry) {
    db->entries = realloc(db->entries, sizeof(Entry) * (db->num_entries + 1));
    db->entries[db->num_entries++] = *entry;
}

// Find an entry in the database by ID
Entry *find_entry_by_id(Database *db, int id) {
    for (int i = 0; i < db->num_entries; i++) {
        if (db->entries[i].id == id) {
            return &db->entries[i];
        }
    }
    return NULL;
}

// Find all entries in the database by name
Entry *find_entries_by_name(Database *db, char *name) {
    Entry *results = malloc(sizeof(Entry) * db->num_entries);
    int num_results = 0;
    for (int i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].name, name) == 0) {
            results[num_results++] = db->entries[i];
        }
    }
    return results;
}

// Print the database
void print_database(Database *db) {
    for (int i = 0; i < db->num_entries; i++) {
        printf("ID: %d\n", db->entries[i].id);
        printf("Name: %s\n", db->entries[i].name);
        printf("Email: %s\n", db->entries[i].email);
        printf("Phone: %s\n\n", db->entries[i].phone);
    }
}

int main() {
    // Create a new database
    Database *db = create_database();

    // Add some entries to the database
    Entry entry1 = {1, "John Doe", "john.doe@example.com", "555-1212"};
    add_entry(db, &entry1);
    Entry entry2 = {2, "Jane Doe", "jane.doe@example.com", "555-1213"};
    add_entry(db, &entry2);

    // Find an entry in the database by ID
    Entry *entry = find_entry_by_id(db, 1);
    if (entry != NULL) {
        printf("Found entry with ID 1:\n");
        printf("Name: %s\n", entry->name);
        printf("Email: %s\n", entry->email);
        printf("Phone: %s\n", entry->phone);
    } else {
        printf("Entry with ID 1 not found.\n");
    }

    // Find all entries in the database by name
    Entry *entries = find_entries_by_name(db, "Doe");
    if (entries != NULL) {
        printf("Found entries with name Doe:\n");
        for (int i = 0; i < db->num_entries; i++) {
            printf("ID: %d\n", db->entries[i].id);
            printf("Name: %s\n", db->entries[i].name);
            printf("Email: %s\n", db->entries[i].email);
            printf("Phone: %s\n\n", db->entries[i].phone);
        }
    } else {
        printf("No entries with name Doe found.\n");
    }

    // Print the database
    print_database(db);

    return 0;
}