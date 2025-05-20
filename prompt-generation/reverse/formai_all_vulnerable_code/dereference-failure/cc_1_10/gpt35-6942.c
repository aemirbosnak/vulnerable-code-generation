//FormAI DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the struct for our "database" entries
struct Entry {
    char* key;      // the key, which acts as the "primary key"
    char* value;    // the value associated with the key
};

// define the struct for our "database"
struct Database {
    struct Entry* entries;  // an array of entries
    int size;               // the number of entries currently in the database
    int capacity;           // the maximum number of entries the database can hold
};

// function to initialize a new Database with the given capacity
void initDatabase(struct Database* db, int capacity) {
    db->entries = (struct Entry*) malloc(sizeof(struct Entry) * capacity);
    db->size = 0;
    db->capacity = capacity;
}

// function to add a new entry to the database
void addEntry(struct Database* db, char* key, char* value) {
    // check if the database is already full
    if (db->size == db->capacity) {
        printf("Error: database is full!\n");
        return;
    }

    // create a new entry with the given key and value
    struct Entry* newEntry = (struct Entry*) malloc(sizeof(struct Entry));
    newEntry->key = (char*) malloc(strlen(key) + 1);     // +1 for the null terminator
    newEntry->value = (char*) malloc(strlen(value) + 1); // +1 for the null terminator
    strcpy(newEntry->key, key);
    strcpy(newEntry->value, value);

    // add the new entry to the end of the entries array
    db->entries[db->size] = *newEntry;
    db->size++;

    // free the memory for the new entry and its fields, since the database now owns them
    free(newEntry->key);
    free(newEntry->value);
    free(newEntry);
}

// function to remove an entry from the database, given its key
void removeEntry(struct Database* db, char* key) {
    // find the index of the entry with the given key
    int index = -1;
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            index = i;
            break;
        }
    }

    // if no entry with the given key was found, print an error message and return
    if (index == -1) {
        printf("Error: no entry with key '%s' found in database!\n", key);
        return;
    }

    // "remove" the entry by shifting all subsequent entries one index to the left
    for (int i = index + 1; i < db->size; i++) {
        db->entries[i - 1] = db->entries[i];
    }

    // decrement the size of the database
    db->size--;
}

// function to print all entries in the database
void printDatabase(struct Database* db) {
    printf("%-10s %-10s\n", "Key", "Value");
    for (int i = 0; i < db->size; i++) {
        printf("%-10s %-10s\n", db->entries[i].key, db->entries[i].value);
    }
}

// main function for testing
int main() {
    // initialize a new database with capacity 10
    struct Database db;
    initDatabase(&db, 10);

    // add some entries to the database
    addEntry(&db, "foo", "bar");
    addEntry(&db, "hello", "world");
    addEntry(&db, "spam", "eggs");

    // print the database before and after removing an entry
    printf("Before:\n");
    printDatabase(&db);
    removeEntry(&db, "hello");
    printf("\nAfter:\n");
    printDatabase(&db);

    // add some more entries to the database
    addEntry(&db, "apple", "pie");
    addEntry(&db, "coffee", "cup");

    // print the final database
    printf("\nFinal:\n");
    printDatabase(&db);

    // free the memory used by the database entries array
    free(db.entries);

    // return 0 to indicate success
    return 0;
}