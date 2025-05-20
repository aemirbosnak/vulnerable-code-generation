//FormAI DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
} Person;

// Define a struct that will represent our database
typedef struct {
    Person* data;
    int num_entries;
} Database;

// Function to initialize a new database
Database init_db(int num_entries) {
    Database db;
    db.num_entries = num_entries;
    db.data = malloc(sizeof(Person) * num_entries);
    return db;
}

// Function to add a new entry to the database
void add_entry(Database* db, const char* name, int age) {
    db->data[db->num_entries].age = age;
    strcpy(db->data[db->num_entries].name, name);
    db->num_entries++;
}

// Function to search for an entry by name
Person* search_entry(Database* db, const char* name) {
    for (int i = 0; i < db->num_entries; i++) {
        if (strcmp(db->data[i].name, name) == 0) {
            return &db->data[i];
        }
    }
    return NULL;
}

int main() {
    // Create a new database with 3 entries
    Database db = init_db(3);

    // Add some entries to the database
    add_entry(&db, "Alice", 25);
    add_entry(&db, "Bob", 30);
    add_entry(&db, "Charlie", 35);

    // Search for an entry by name
    const char* name = "Bob";
    Person* result = search_entry(&db, name);
    if (result != NULL) {
        printf("%s is %d years old.\n", result->name, result->age);
    } else {
        printf("No entry found for %s.\n", name);
    }

    // Free the database's memory before exiting the program
    free(db.data);

    return 0;
}