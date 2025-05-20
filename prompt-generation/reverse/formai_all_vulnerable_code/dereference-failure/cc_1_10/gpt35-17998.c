//FormAI DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for database entry
typedef struct Entry {
    int id;
    char name[50];
    int age;
    char email[100];
} Entry;

// Define struct for database
typedef struct Database {
    int size;
    Entry* entries;
} Database;

// Initialize database with capacity for 10 entries
Database* init_database() {
    Database* db = malloc(sizeof(Database));
    db->size = 0;
    db->entries = malloc(10 * sizeof(Entry));
    return db;
}

// Print a single database entry
void print_entry(Entry entry) {
    printf("ID: %d\n", entry.id);
    printf("Name: %s\n", entry.name);
    printf("Age: %d\n", entry.age);
    printf("Email: %s\n", entry.email);
}

// Print entire database
void print_database(Database* db) {
    printf("Size: %d\n", db->size);
    for (int i = 0; i < db->size; i++) {
        print_entry(db->entries[i]);
    }
}

// Add an entry to the database
void add_entry(Database* db, Entry entry) {
    if (db->size == 10) {
        printf("Unable to add entry. Database is full.\n");
        return;
    }
    db->entries[db->size] = entry;
    db->size++;
}

// Find an entry in the database by ID
Entry* find_entry(Database* db, int id) {
    for (int i = 0; i < db->size; i++) {
        if (db->entries[i].id == id) {
            return &db->entries[i];
        }
    }
    return NULL;
}

// Update an entry in the database by ID
void update_entry(Database* db, int id, Entry entry) {
    Entry* existing_entry = find_entry(db, id);
    if (existing_entry == NULL) {
        printf("Unable to update entry. Entry not found.\n");
        return;
    }
    existing_entry->id = entry.id;
    strcpy(existing_entry->name, entry.name);
    existing_entry->age = entry.age;
    strcpy(existing_entry->email, entry.email);
}

// Remove an entry from the database by ID
void remove_entry(Database* db, int id) {
    Entry* existing_entry = find_entry(db, id);
    if (existing_entry == NULL) {
        printf("Unable to remove entry. Entry not found.\n");
        return;
    }
    int index = (int)(existing_entry - db->entries);
    memmove(&db->entries[index], &db->entries[index + 1], (db->size - index - 1) * sizeof(Entry));
    db->size--;
}

int main() {
    // Initialize database
    Database* db = init_database();

    // Add some entries to the database
    Entry entry1 = { 1, "John Smith", 30, "john.smith@example.com" };
    add_entry(db, entry1);
    Entry entry2 = { 2, "Jane Doe", 25, "jane.doe@example.com" };
    add_entry(db, entry2);
    Entry entry3 = { 3, "Bob Johnson", 40, "bob.johnson@example.com" };
    add_entry(db, entry3);

    // Print the entire database
    printf("Initial database:\n");
    print_database(db);

    // Find and print an entry by ID
    int search_id = 2;
    Entry* found_entry = find_entry(db, search_id);
    printf("\nEntry with ID %d:\n", search_id);
    print_entry(*found_entry);

    // Update an entry
    Entry updated_entry = { 1, "John Smith Jr.", 31, "john.smith.jr@example.com" };
    update_entry(db, 1, updated_entry);

    // Print the entire database again
    printf("\nDatabase after update:\n");
    print_database(db);

    // Remove an entry
    remove_entry(db, 3);

    // Print the entire database one last time
    printf("\nFinal database:\n");
    print_database(db);

    // Clean up the database
    free(db->entries);
    free(db);

    return 0;
}