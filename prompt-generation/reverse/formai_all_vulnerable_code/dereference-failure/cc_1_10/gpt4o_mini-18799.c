//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

typedef struct {
    Record *records[MAX_RECORDS];
    int count;
} Database;

Database* create_database() {
    Database *db = malloc(sizeof(Database));
    db->count = 0;
    return db;
}

void add_record(Database *db, int id, const char *name) {
    if (db->count >= MAX_RECORDS) {
        printf("The database is full, cannot add more records.\n");
        return;
    }
    Record *new_record = malloc(sizeof(Record));
    new_record->id = id;
    strncpy(new_record->name, name, NAME_LENGTH - 1);
    new_record->name[NAME_LENGTH - 1] = '\0';  // Ensure null termination
    db->records[db->count++] = new_record;
}

int compare(const void *a, const void *b) {
    Record *recordA = *(Record**)a;
    Record *recordB = *(Record**)b;
    return strcmp(recordA->name, recordB->name);
}

void index_database(Database *db) {
    qsort(db->records, db->count, sizeof(Record*), compare);
}

int search_record(Database *db, const char *name) {
    int left = 0;
    int right = db->count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int result = strcmp(db->records[mid]->name, name);

        if (result == 0) {
            return db->records[mid]->id;  // Record found
        } else if (result < 0) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Record not found
}

void display_records(Database *db) {
    printf("Database Records:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s\n", db->records[i]->id, db->records[i]->name);
    }
}

void free_database(Database *db) {
    for (int i = 0; i < db->count; i++) {
        free(db->records[i]);
    }
    free(db);
}

int main() {
    Database *db = create_database();

    add_record(db, 1, "Alice");
    add_record(db, 2, "Bob");
    add_record(db, 3, "Charlie");
    add_record(db, 4, "Diana");

    printf("Before indexing:\n");
    display_records(db);

    index_database(db);

    printf("\nAfter indexing:\n");
    display_records(db);

    char name_to_search[NAME_LENGTH];
    printf("\nEnter name to search: ");
    fgets(name_to_search, NAME_LENGTH, stdin);
    name_to_search[strcspn(name_to_search, "\n")] = 0; // Remove newline

    int found_id = search_record(db, name_to_search);
    
    if (found_id != -1) {
        printf("Record found: ID = %d for Name = %s\n", found_id, name_to_search);
    } else {
        printf("No record found with the name: %s\n", name_to_search);
    }

    free_database(db);
    return 0;
}