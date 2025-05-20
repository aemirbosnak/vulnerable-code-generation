//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a record in the database
typedef struct {
    int id;
    char name[100];
    int age;
} Record;

// Structure for the database
typedef struct {
    Record* records;
    size_t size;
    size_t capacity;
} Database;

// Function to initialize the database
Database* create_database(size_t capacity) {
    Database* db = (Database*)malloc(sizeof(Database));
    db->records = (Record*)malloc(sizeof(Record) * capacity);
    db->size = 0;
    db->capacity = capacity;
    return db;
}

// Function to free the database
void free_database(Database* db) {
    free(db->records);
    free(db);
}

// Function to add a record to the database
void add_record(Database* db, int id, const char* name, int age) {
    if (db->size >= db->capacity) {
        db->capacity *= 2;
        db->records = (Record*)realloc(db->records, sizeof(Record) * db->capacity);
    }
    db->records[db->size].id = id;
    strncpy(db->records[db->size].name, name, sizeof(db->records[db->size].name) - 1);
    db->records[db->size].name[sizeof(db->records[db->size].name) - 1] = '\0';
    db->records[db->size].age = age;
    db->size++;
}

// Function to display all records
void display_records(Database* db) {
    printf("ID\tName\t\tAge\n");
    printf("-----------------------------\n");
    for (size_t i = 0; i < db->size; i++) {
        printf("%d\t%s\t%d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
}

// Function to search for a record by id
Record* search_by_id(Database* db, int id) {
    for (size_t i = 0; i < db->size; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Function to remove a record by id
void remove_record(Database* db, int id) {
    for (size_t i = 0; i < db->size; i++) {
        if (db->records[i].id == id) {
            memmove(&db->records[i], &db->records[i + 1], sizeof(Record) * (db->size - i - 1));
            db->size--;
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

// Main function
int main() {
    Database* db = create_database(5);

    add_record(db, 1, "Alice", 30);
    add_record(db, 2, "Bob", 25);
    add_record(db, 3, "Charlie", 35);
    add_record(db, 4, "David", 28);
    add_record(db, 5, "Eve", 22);

    printf("Current records in the database:\n");
    display_records(db);
    
    // Searching for a record
    int search_id = 3;
    Record* found_record = search_by_id(db, search_id);
    if (found_record != NULL) {
        printf("Found record: ID = %d, Name = %s, Age = %d\n", found_record->id, found_record->name, found_record->age);
    } else {
        printf("Record with ID %d not found.\n", search_id);
    }

    // Removing a record
    printf("\nRemoving record with ID 2:\n");
    remove_record(db, 2);
    display_records(db);

    // Free resources
    free_database(db);
    return 0;
}