//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a record in the database
struct record {
    int id;
    char name[20];
    int age;
};

// Structure to represent the database
struct database {
    struct record *records;
    int num_records;
};

// Function to create a new database
struct database *create_database() {
    struct database *db = malloc(sizeof(struct database));
    db->records = NULL;
    db->num_records = 0;

    return db;
}

// Function to add a new record to the database
void add_record(struct database *db, int id, char *name, int age) {
    struct record *new_record = malloc(sizeof(struct record));
    new_record->id = id;
    strcpy(new_record->name, name);
    new_record->age = age;

    // Add the new record to the end of the records array
    db->records = realloc(db->records, (db->num_records + 1) * sizeof(struct record));
    db->records[db->num_records++] = *new_record;

    free(new_record);
}

// Function to find a record in the database by its id
struct record *find_record(struct database *db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }

    return NULL;
}

// Function to delete a record from the database by its id
void delete_record(struct database *db, int id) {
    int index = -1;

    // Find the index of the record to be deleted
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            index = i;
            break;
        }
    }

    // If the record was found, delete it
    if (index >= 0) {
        for (int i = index; i < db->num_records - 1; i++) {
            db->records[i] = db->records[i + 1];
        }

        db->num_records--;
    }
}

// Function to print the database
void print_database(struct database *db) {
    printf("ID\tName\tAge\n");
    for (int i = 0; i < db->num_records; i++) {
        printf("%d\t%s\t%d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
}

// Main function
int main() {
    // Create a new database
    struct database *db = create_database();

    // Add some records to the database
    add_record(db, 1, "John Doe", 20);
    add_record(db, 2, "Jane Doe", 25);
    add_record(db, 3, "Peter Parker", 18);

    // Find a record in the database by its id
    struct record *record = find_record(db, 2);

    // If the record was found, print its details
    if (record != NULL) {
        printf("Record found!\n");
        printf("ID: %d\n", record->id);
        printf("Name: %s\n", record->name);
        printf("Age: %d\n", record->age);
    } else {
        printf("Record not found.\n");
    }

    // Delete a record from the database by its id
    delete_record(db, 1);

    // Print the database
    print_database(db);

    // Free the memory allocated for the database
    free(db->records);
    free(db);

    return 0;
}