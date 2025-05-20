//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define database structure
struct database {
    int num_records;
    struct record *records;
};

// Define record structure
struct record {
    int id;
    char name[50];
    char email[50];
    int age;
};

// Function to create a new database
struct database *create_db(int num_records) {
    struct database *db = malloc(sizeof(struct database));
    db->num_records = num_records;
    db->records = malloc(num_records * sizeof(struct record));
    return db;
}

// Function to insert a record into the database
void insert_record(struct database *db, int id, char *name, char *email, int age) {
    struct record *new_record = malloc(sizeof(struct record));
    new_record->id = id;
    strcpy(new_record->name, name);
    strcpy(new_record->email, email);
    new_record->age = age;
    db->records[db->num_records] = *new_record;
    db->num_records++;
}

// Function to retrieve a record from the database
struct record *get_record(struct database *db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Function to update a record in the database
void update_record(struct database *db, int id, char *name, char *email, int age) {
    struct record *record = get_record(db, id);
    if (record != NULL) {
        strcpy(record->name, name);
        strcpy(record->email, email);
        record->age = age;
    }
}

// Function to delete a record from the database
void delete_record(struct database *db, int id) {
    int i = 0;
    for (i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            break;
        }
    }
    if (i < db->num_records) {
        memmove(db->records + i, db->records + i + 1, (db->num_records - i - 1) * sizeof(struct record));
        db->num_records--;
    }
}

int main() {
    srand(time(NULL));

    // Create a new database with 5 records
    struct database *db = create_db(5);

    // Insert some records into the database
    insert_record(db, 1, "John", "john@example.com", 25);
    insert_record(db, 2, "Jane", "jane@example.com", 30);
    insert_record(db, 3, "Bob", "bob@example.com", 35);
    insert_record(db, 4, "Alice", "alice@example.com", 20);
    insert_record(db, 5, "Charlie", "charlie@example.com", 40);

    // Retrieve and update some records
    struct record *jane = get_record(db, 2);
    update_record(db, 2, "Jane Doe", "jane.doe@example.com", 35);
    struct record *bob = get_record(db, 3);
    update_record(db, 3, "Robert", "bob@example.com", 40);

    // Delete a record
    delete_record(db, 1);

    // Print the updated database
    for (int i = 0; i < db->num_records; i++) {
        printf("%d: %s %s %d\n", db->records[i].id, db->records[i].name, db->records[i].email, db->records[i].age);
    }

    return 0;
}