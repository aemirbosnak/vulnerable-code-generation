//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: light-weight
// Lightweight C Database Simulation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Table Definition
typedef struct {
    char name[32];
    int age;
    char city[32];
} Person;

// Database Definition
typedef struct {
    Person* records;
    int size;
    int capacity;
} Database;

// Create a database with initial capacity
Database* create_database(int capacity) {
    Database* db = malloc(sizeof(Database));
    db->records = malloc(sizeof(Person) * capacity);
    db->size = 0;
    db->capacity = capacity;
    return db;
}

// Insert a record into the database
void insert_record(Database* db, Person record) {
    if (db->size >= db->capacity) {
        db->records = realloc(db->records, sizeof(Person) * (db->capacity *= 2));
    }
    db->records[db->size++] = record;
}

// Print the database contents
void print_database(Database* db) {
    for (int i = 0; i < db->size; i++) {
        printf("%s, %d, %s\n", db->records[i].name, db->records[i].age, db->records[i].city);
    }
}

// MAIN FUNCTION
int main() {
    // Create a database with initial capacity of 5
    Database* db = create_database(5);

    // Insert some fake records
    insert_record(db, (Person){"John", 30, "New York"});
    insert_record(db, (Person){"Mary", 25, "London"});
    insert_record(db, (Person){"Bob", 40, "Paris"});

    // Print the database contents
    printf("Database Contents:\n");
    print_database(db);

    // Free the database resources
    free(db->records);
    free(db);
    return 0;
}