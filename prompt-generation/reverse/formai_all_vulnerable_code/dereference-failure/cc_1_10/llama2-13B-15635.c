//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: visionary
// The Databasis: A Cosmic Database Simulation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 1000
#define MAX_RECORDS 50

typedef struct record {
    char name[50];
    int age;
} record_t;

typedef struct database {
    record_t records[DATABASE_SIZE];
    int capacity;
    int size;
} database_t;

void init_database(database_t *db) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        db->records[i].name[0] = '\0';
        db->records[i].age = -1;
    }
    db->capacity = DATABASE_SIZE;
    db->size = 0;
}

void insert_record(database_t *db, char *name, int age) {
    int i;
    for (i = 0; i < db->size; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            // Record already exists, update age
            db->records[i].age = age;
            return;
        }
    }
    // Record does not exist, insert it
    strcpy(db->records[db->size].name, name);
    db->records[db->size].age = age;
    db->size++;
    if (db->size == db->capacity) {
        // Database is full, reallocate memory
        database_t *new_db = realloc(db, (db->capacity *= 2) * sizeof(record_t));
        memset(new_db->records + db->capacity, 0, (db->capacity - db->size) * sizeof(record_t));
        db = new_db;
    }
}

void query_records(database_t *db, char *query) {
    int i, j;
    for (i = 0; i < db->size; i++) {
        if (strcmp(db->records[i].name, query) == 0) {
            // Found a matching record
            printf("Found record: %s, age: %d\n", db->records[i].name, db->records[i].age);
            for (j = i + 1; j < db->size; j++) {
                if (strcmp(db->records[j].name, query) == 0) {
                    // Found another matching record
                    printf("Found another record: %s, age: %d\n", db->records[j].name, db->records[j].age);
                }
            }
        }
    }
}

int main() {
    database_t *db = malloc(sizeof(record_t));
    init_database(db);

    // Insert some records
    insert_record(db, "Alice", 25);
    insert_record(db, "Bob", 30);
    insert_record(db, "Charlie", 20);

    // Query the database
    query_records(db, "Alice");

    // Print the database size
    printf("Database size: %d\n", db->size);

    return 0;
}