//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a database record
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// Database structure containing records and a count of records
typedef struct {
    Record *records;
    int count;
    int capacity;
} Database;

// Function declarations
Database* create_database(int capacity);
void add_record(Database *db, int id, const char *name, int age);
void display_records(const Database *db);
Record* search_record(const Database *db, int id);
void free_database(Database *db);

// Main function
int main() {
    Database *db = create_database(2); // Start with a capacity of 2
    int choice, id, age;
    char name[50];

    do {
        printf("\n--- Database Menu ---\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                add_record(db, id, name, age);
                break;
            case 2:
                display_records(db);
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Record *record = search_record(db, id);
                if (record) {
                    printf("Record Found: ID=%d, Name=%s, Age=%d\n", record->id, record->name, record->age);
                } else {
                    printf("Record not found!\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    free_database(db);
    return 0;
}

// Function to create a new database
Database* create_database(int capacity) {
    Database *db = (Database *)malloc(sizeof(Database));
    db->count = 0;
    db->capacity = capacity;
    db->records = (Record *)malloc(capacity * sizeof(Record));
    return db;
}

// Function to add a record to the database
void add_record(Database *db, int id, const char *name, int age) {
    // Resize the record array if needed
    if (db->count == db->capacity) {
        db->capacity *= 2;
        db->records = (Record *)realloc(db->records, db->capacity * sizeof(Record));
    }
    
    db->records[db->count].id = id;
    strncpy(db->records[db->count].name, name, sizeof(db->records[db->count].name) - 1);
    db->records[db->count].name[sizeof(db->records[db->count].name) - 1] = '\0'; // Null-terminate the string
    db->records[db->count].age = age;
    db->count++;
    printf("Record added successfully!\n");
}

// Function to display all records in the database
void display_records(const Database *db) {
    if (db->count == 0) {
        printf("No records found!\n");
    } else {
        printf("\n--- All Records ---\n");
        for (int i = 0; i < db->count; i++) {
            printf("ID: %d, Name: %s, Age: %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
        }
    }
}

// Function to search for a record by ID
Record* search_record(const Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            return &db->records[i]; // Return pointer to the record
        }
    }
    return NULL; // Not found
}

// Function to free the allocated memory for the database
void free_database(Database *db) {
    free(db->records);
    free(db);
}