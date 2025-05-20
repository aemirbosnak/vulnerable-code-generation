//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DB_SIZE 1000
#define MAX_RECORD_LEN 256

// Structure to hold a record in the database
typedef struct {
    char name[MAX_RECORD_LEN];
    char address[MAX_RECORD_LEN];
    int age;
} record_t;

// Function to initialize the database
void init_db(record_t **db) {
    int i;
    for (i = 0; i < DB_SIZE; i++) {
        // Generate a random record and insert it into the database
        srand(time(NULL));
        record_t *rec = malloc(sizeof(record_t));
        rec->name[0] = 'A' + (rand() % 26);
        rec->address[0] = 'a' + (rand() % 26);
        rec->age = rand() % 100;
        db[i] = rec;
    }
}

// Function to search the database for a record based on a given name
record_t* search_db(record_t **db, const char *name) {
    int i;
    for (i = 0; i < DB_SIZE; i++) {
        if (strcmp(db[i]->name, name) == 0) {
            return db[i];
        }
    }
    return NULL;
}

// Function to insert a new record into the database
void insert_record(record_t **db, const char *name, const char *address, int age) {
    int i;
    for (i = 0; i < DB_SIZE; i++) {
        if (db[i] == NULL) {
            break;
        }
    }
    if (i == DB_SIZE) {
        printf("Database is full! Cannot insert new record.\n");
        return;
    }
    record_t *new_rec = malloc(sizeof(record_t));
    strcpy(new_rec->name, name);
    strcpy(new_rec->address, address);
    new_rec->age = age;
    db[i] = new_rec;
}

// Function to delete a record from the database
void delete_record(record_t **db, const char *name) {
    int i;
    for (i = 0; i < DB_SIZE; i++) {
        if (strcmp(db[i]->name, name) == 0) {
            free(db[i]);
            db[i] = NULL;
            break;
        }
    }
}

int main() {
    record_t **db = malloc(DB_SIZE * sizeof(record_t*));
    init_db(db);

    // Test the database functions
    record_t *found_rec = search_db(db, "Alice");
    if (found_rec != NULL) {
        printf("Found record: %s %s %d\n", found_rec->name, found_rec->address, found_rec->age);
    } else {
        printf("No record found.\n");
    }

    insert_record(db, "Bob", "123 Main St", 30);
    found_rec = search_db(db, "Bob");
    if (found_rec != NULL) {
        printf("Found record: %s %s %d\n", found_rec->name, found_rec->address, found_rec->age);
    } else {
        printf("No record found.\n");
    }

    delete_record(db, "Alice");
    found_rec = search_db(db, "Alice");
    if (found_rec == NULL) {
        printf("Record deleted successfully.\n");
    } else {
        printf("Record not found (expected).\n");
    }

    return 0;
}