//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define database structure
typedef struct database {
    int num_records;
    int max_id;
    struct record *records;
} database;

// Define record structure
typedef struct record {
    int id;
    double score;
    char name[20];
} record;

// Function to insert a record into the database
void insert_record(database *db, int id, double score, char name[]) {
    record new_record = {id, score, name};
    if (db->num_records == 0) {
        // Initialize database with first record
        db->max_id = id;
        db->records = (struct record *)calloc(1, sizeof(record));
        *db->records = new_record;
        db->num_records = 1;
    } else {
        // Find the last record and increment its id
        int last_id = db->records[db->num_records - 1].id;
        last_id += 1;
        new_record.id = last_id;
        db->records = (struct record *)realloc(db->records,
                                             (db->num_records + 1) * sizeof(record));
        db->records[db->num_records] = new_record;
        db->num_records++;
    }
}

// Function to retrieve all records from the database
void retrieve_records(database *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("%d - %f - %s\n", db->records[i].id, db->records[i].score, db->records[i].name);
    }
}

// Function to update a record in the database
void update_record(database *db, int id, double score, char name[]) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            db->records[i].score = score;
            strcpy(db->records[i].name, name);
            break;
        }
    }
}

// Function to delete a record from the database
void delete_record(database *db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            // Remove the record from the database
            memmove(&db->records[i], &db->records[i + 1],
                    (db->num_records - i - 1) * sizeof(record));
            db->num_records--;
            break;
        }
    }
}

int main() {
    database db = {0, 0, NULL};
    insert_record(&db, 1, 10.5, "John");
    insert_record(&db, 2, 8.9, "Jane");
    insert_record(&db, 3, 12.3, "Bob");
    retrieve_records(&db);
    update_record(&db, 2, 9.9, "Jane Doe");
    retrieve_records(&db);
    delete_record(&db, 3);
    retrieve_records(&db);
    return 0;
}