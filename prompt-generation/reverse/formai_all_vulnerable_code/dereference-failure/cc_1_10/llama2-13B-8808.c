//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DB_SIZE 1000
#define MAX_REC_SIZE 100

// Structure to represent a record in the database
typedef struct {
    int id; // Record ID
    char name[MAX_REC_SIZE]; // Record name
    double value; // Record value
} record_t;

// Function to create a new record
record_t* new_record(int id, char name[MAX_REC_SIZE], double value) {
    record_t* rec = (record_t*)malloc(sizeof(record_t));
    rec->id = id;
    strcpy(rec->name, name);
    rec->value = value;
    return rec;
}

// Function to insert a record into the database
void insert_record(record_t** db, int id, char name[MAX_REC_SIZE], double value) {
    int i;
    for (i = 0; i < MAX_DB_SIZE; i++) {
        if (db[i] == NULL) {
            break;
        }
    }
    if (i == MAX_DB_SIZE) {
        printf("Database is full, cannot insert new record\n");
        return;
    }
    db[i] = new_record(id, name, value);
}

// Function to retrieve a record from the database
record_t* get_record(record_t** db, int id) {
    int i;
    for (i = 0; i < MAX_DB_SIZE; i++) {
        if (db[i] != NULL && db[i]->id == id) {
            return db[i];
        }
    }
    return NULL;
}

// Function to update a record in the database
void update_record(record_t** db, int id, char name[MAX_REC_SIZE], double value) {
    record_t* rec = get_record(db, id);
    if (rec != NULL) {
        strcpy(rec->name, name);
        rec->value = value;
    }
}

// Function to delete a record from the database
void delete_record(record_t** db, int id) {
    int i;
    for (i = 0; i < MAX_DB_SIZE; i++) {
        if (db[i] != NULL && db[i]->id == id) {
            free(db[i]);
            db[i] = NULL;
            break;
        }
    }
}

// Function to display the contents of the database
void display_db(record_t** db) {
    int i;
    for (i = 0; i < MAX_DB_SIZE; i++) {
        if (db[i] != NULL) {
            printf("%d: %s %f\n", db[i]->id, db[i]->name, db[i]->value);
        }
    }
}

int main() {
    record_t** db = (record_t**)malloc(MAX_DB_SIZE * sizeof(record_t*));
    srand(time(NULL));

    // Insert some records into the database
    insert_record(db, 1, "John", 25.5);
    insert_record(db, 2, "Jane", 32.2);
    insert_record(db, 3, "Bob", 43.1);

    // Retrieve and update a record
    record_t* rec = get_record(db, 2);
    if (rec != NULL) {
        rec->value = 35.3;
        update_record(db, 2, "Jane", 35.3);
    }

    // Delete a record
    delete_record(db, 3);

    // Display the contents of the database
    display_db(db);

    return 0;
}