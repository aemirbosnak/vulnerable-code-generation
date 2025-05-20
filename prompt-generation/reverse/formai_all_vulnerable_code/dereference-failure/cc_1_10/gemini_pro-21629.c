//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to represent a record in a database
struct Record {
    int id;
    char name[256];
    float age;
};

// Data structure to represent a database
struct Database {
    struct Record *records;
    int num_records;
};

// Function to create a new database
struct Database *create_database() {
    struct Database *db = malloc(sizeof(struct Database));
    db->records = NULL;
    db->num_records = 0;
    return db;
}

// Function to add a new record to a database
void add_record(struct Database *db, int id, char *name, float age) {
    struct Record *new_record = malloc(sizeof(struct Record));
    new_record->id = id;
    strcpy(new_record->name, name);
    new_record->age = age;

    db->records = realloc(db->records, (db->num_records + 1) * sizeof(struct Record));
    db->records[db->num_records++] = *new_record;
}

// Function to find a record in a database by its ID
struct Record *find_record_by_id(struct Database *db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Function to delete a record in a database by its ID
void delete_record_by_id(struct Database *db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            db->records[i] = db->records[db->num_records - 1];
            db->num_records--;
            db->records = realloc(db->records, db->num_records * sizeof(struct Record));
            return;
        }
    }
}

// Function to print a database to the console
void print_database(struct Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("ID: %d, Name: %s, Age: %.2f\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
}

int main() {
    // Create a new database
    struct Database *db = create_database();

    // Add some records to the database
    add_record(db, 1, "John Doe", 30.5);
    add_record(db, 2, "Jane Doe", 25.5);
    add_record(db, 3, "Peter Parker", 20.5);

    // Print the database to the console
    print_database(db);

    // Find a record in the database by its ID
    struct Record *found_record = find_record_by_id(db, 2);
    if (found_record != NULL) {
        printf("Found record: ID: %d, Name: %s, Age: %.2f\n", found_record->id, found_record->name, found_record->age);
    } else {
        printf("Record not found.\n");
    }

    // Delete a record from the database by its ID
    delete_record_by_id(db, 3);

    // Print the database to the console
    print_database(db);

    return 0;
}