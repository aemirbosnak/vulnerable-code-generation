//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DB_SIZE 1000
#define MAX_REC_SIZE 50

// Structure to represent a record in the database
typedef struct {
    char name[50];
    char address[50];
    int age;
} record_t;

// Function to insert a record into the database
void insert_record(record_t *db, int size, char *name, char *address, int age) {
    int i = 0;
    for (i = 0; i < size; i++) {
        if (db[i].name[0] == '\0' && db[i].address[0] == '\0') {
            break;
        }
    }
    if (i == size) {
        printf("Database is full! No more records can be inserted.\n");
        return;
    }
    strcpy(db[i].name, name);
    strcpy(db[i].address, address);
    db[i].age = age;
}

// Function to search for a record in the database
record_t *search_record(record_t *db, int size, char *name) {
    int i = 0;
    for (i = 0; i < size; i++) {
        if (strcmp(db[i].name, name) == 0) {
            return &db[i];
        }
    }
    return NULL;
}

// Function to delete a record from the database
void delete_record(record_t *db, int size, char *name) {
    int i = 0;
    for (i = 0; i < size; i++) {
        if (strcmp(db[i].name, name) == 0) {
            break;
        }
    }
    if (i == size) {
        printf("Record not found! Could not delete.\n");
        return;
    }
    memset(db[i].name, 0, strlen(db[i].name));
    memset(db[i].address, 0, strlen(db[i].address));
    db[i].age = 0;
}

int main() {
    srand(time(NULL));

    // Create an empty database
    record_t *db = malloc(MAX_DB_SIZE * sizeof(record_t));
    for (int i = 0; i < MAX_DB_SIZE; i++) {
        db[i].name[0] = '\0';
        db[i].address[0] = '\0';
        db[i].age = 0;
    }

    // Insert some records into the database
    insert_record(db, MAX_DB_SIZE, "Alice", "123 Main St", 25);
    insert_record(db, MAX_DB_SIZE, "Bob", "456 Elm St", 30);
    insert_record(db, MAX_DB_SIZE, "Charlie", "789 Oak St", 35);

    // Search for a record in the database
    record_t *found = search_record(db, MAX_DB_SIZE, "Bob");
    if (found != NULL) {
        printf("Found record: %s, %s, %d\n", found->name, found->address, found->age);
    } else {
        printf("Record not found!\n");
    }

    // Delete a record from the database
    delete_record(db, MAX_DB_SIZE, "Bob");

    // Print the remaining records in the database
    for (int i = 0; i < MAX_DB_SIZE; i++) {
        if (db[i].name[0] != '\0') {
            printf("%d: %s, %s, %d\n", i, db[i].name, db[i].address, db[i].age);
        }
    }

    free(db);
    return 0;
}