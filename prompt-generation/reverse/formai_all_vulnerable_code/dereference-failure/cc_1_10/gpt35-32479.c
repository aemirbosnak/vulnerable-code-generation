//FormAI DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of the database record
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// Define the structure of the database
typedef struct {
    int size;
    int capacity;
    Record *data;
} Database;

// Create a new database
Database *create_database(int capacity) {
    Database *db = (Database *) malloc(sizeof(Database));
    db->size = 0;
    db->capacity = capacity;
    db->data = (Record *) calloc(db->capacity, sizeof(Record));
    return db;
}

// Add a new record to the database
void add_record(Database *db, int id, char *name, int age) {
    if (db->size < db->capacity) {
        Record *record = &(db->data[db->size]);
        record->id = id;
        strcpy(record->name, name);
        record->age = age;
        db->size++;
    } else {
        printf("Database is full.\n");
    }
}

// Find a record by ID
Record *find_record(Database *db, int id) {
    for (int i = 0; i < db->size; i++) {
        if (db->data[i].id == id) {
            return &(db->data[i]);
        }
    }
    return NULL;
}

// Update a record by ID
void update_record(Database *db, int id, char *name, int age) {
    Record *record = find_record(db, id);
    if (record != NULL) {
        strcpy(record->name, name);
        record->age = age;
    } else {
        printf("Record not found.\n");
    }
}

// Remove a record by ID
void remove_record(Database *db, int id) {
    Record *record = find_record(db, id);
    if (record != NULL) {
        *record = db->data[db->size - 1];
        db->size--;
    } else {
        printf("Record not found.\n");
    }
}

// Print all records in the database
void print_database(Database *db) {
    printf("ID\tName\tAge\n");
    for (int i = 0; i < db->size; i++) {
        Record *record = &(db->data[i]);
        printf("%d\t%s\t%d\n", record->id, record->name, record->age);
    }
}

// Main function
int main() {
    // Create a new database with capacity for 10 records
    Database *db = create_database(10);

    // Add some example records
    add_record(db, 1, "John", 25);
    add_record(db, 2, "Jane", 30);

    // Print all records in the database
    printf("Database after adding example records:\n");
    print_database(db);

    // Update a record
    update_record(db, 1, "Jonathan", 26);

    // Print all records in the database again
    printf("Database after updating record with ID 1:\n");
    print_database(db);

    // Remove a record
    remove_record(db, 2);

    // Print all records in the database one last time
    printf("Database after removing record with ID 2:\n");
    print_database(db);

    // Free memory
    free(db->data);
    free(db);

    return 0;
}