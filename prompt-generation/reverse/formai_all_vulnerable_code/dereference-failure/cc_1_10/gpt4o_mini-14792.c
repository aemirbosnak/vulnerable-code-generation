//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Record;

typedef struct {
    Record *records;
    int size;
} Database;

void initializeDatabase(Database *db) {
    db->records = malloc(sizeof(Record) * MAX_RECORDS);
    db->size = 0;
}

void addRecord(Database *db, int id, const char *name) {
    if (db->size < MAX_RECORDS) {
        db->records[db->size].id = id;
        strncpy(db->records[db->size].name, name, MAX_NAME_LENGTH - 1);
        db->records[db->size].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
        db->size++;
    } else {
        printf("Database is full, cannot add more records.\n");
    }
}

void displayRecords(const Database *db) {
    printf("Records in the Database:\n");
    for (int i = 0; i < db->size; i++) {
        printf("ID: %d, Name: %s\n", db->records[i].id, db->records[i].name);
    }
}

int compareRecords(const void *a, const void *b) {
    return strcmp(((Record *)a)->name, ((Record *)b)->name);
}

void sortRecords(Database *db) {
    qsort(db->records, db->size, sizeof(Record), compareRecords);
}

int searchRecord(const Database *db, const char *name) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return i; // Return index of the found record
        }
    }
    return -1; // Not found
}

void freeDatabase(Database *db) {
    free(db->records);
    db->records = NULL;
    db->size = 0;
}

void romanticDetails() {
    printf("In the garden of our hearts, we gather records,\n");
    printf("Each entry a sweet memory of our love's untold saga.\n");
    printf("With every id, a promise, with every name, a caress,\n");
    printf("Together, let us explore the database of our affection.\n");
}

int main() {
    Database db;
    initializeDatabase(&db);

    romanticDetails();
    
    // Adding romantic entries to the database
    addRecord(&db, 1, "Juliet");
    addRecord(&db, 2, "Romeo");
    addRecord(&db, 3, "Desdemona");
    addRecord(&db, 4, "Othello");
    addRecord(&db, 5, "Ophelia");
    
    // Displaying the records
    displayRecords(&db);
    
    // Sorting the records
    sortRecords(&db);
    printf("\nRecords sorted by names:\n");
    displayRecords(&db);

    // Searching for a record
    char *searchName = "Juliet";
    int index = searchRecord(&db, searchName);
    if (index != -1) {
        printf("\nWe found our love: %s with ID: %d\n", db.records[index].name, db.records[index].id);
    } else {
        printf("\nOh! My dear, %s is lost in the memories...\n", searchName);
    }

    // Freeing memory
    freeDatabase(&db);
    printf("The garden of our hearts has been cleared, but our love remains eternal.\n");
    
    return 0;
}