//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// A structure to represent an entry in the database
struct Entry {
    char name[MAX_SIZE];
    int age;
};

// A structure to represent the database itself
struct Database {
    int size;
    struct Entry* entries;
};

// A function to add an entry to the database
void addEntry(struct Database* db, const char* name, int age) {
    if (db->size == MAX_SIZE) {
        printf("Database is full\n");
        return;
    }
    struct Entry newEntry = {name, age};
    db->entries[db->size++] = newEntry;
}

// A function to search for an entry in the database
struct Entry* searchEntry(struct Database* db, const char* name) {
    int i;
    for (i = 0; i < db->size; i++) {
        if (strcmp(db->entries[i].name, name) == 0) {
            return &(db->entries[i]);
        }
    }
    return NULL;
}

// A function to delete an entry from the database
void deleteEntry(struct Database* db, const char* name) {
    int i;
    for (i = 0; i < db->size; i++) {
        if (strcmp(db->entries[i].name, name) == 0) {
            for (int j = i; j < db->size - 1; j++) {
                db->entries[j] = db->entries[j + 1];
            }
            db->size--;
            return;
        }
    }
}

// A function to print the entire database
void printDatabase(struct Database* db) {
    int i;
    for (i = 0; i < db->size; i++) {
        printf("Name: %s, Age: %d\n", db->entries[i].name, db->entries[i].age);
    }
}

int main() {
    struct Database db = {0, NULL};
    addEntry(&db, "John", 25);
    addEntry(&db, "Jane", 20);
    addEntry(&db, "Bob", 30);
    addEntry(&db, "Alice", 28);

    printf("Database: \n");
    printDatabase(&db);

    struct Entry* entry = searchEntry(&db, "Bob");
    if (entry!= NULL) {
        printf("Found Bob: %s\n", entry->name);
    } else {
        printf("Bob not found\n");
    }

    deleteEntry(&db, "John");
    printf("Database after deleting John: \n");
    printDatabase(&db);

    return 0;
}