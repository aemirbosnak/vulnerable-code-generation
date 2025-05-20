//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a database record
typedef struct Record {
    char name[50];
    int age;
} Record;

// Structure for the database
typedef struct Database {
    Record *records;
    int size;
    int capacity;
} Database;

// Function to initialize the database
Database *initialize_database(int capacity) {
    Database *db = (Database *)malloc(sizeof(Database));
    db->records = (Record *)malloc(sizeof(Record) * capacity);
    db->size = 0;
    db->capacity = capacity;
    return db;
}

// Function to add a record to the database
void add_record(Database *db, char *name, int age) {
    if (db->size >= db->capacity) {
        db->capacity *= 2;
        db->records = (Record *)realloc(db->records, sizeof(Record) * db->capacity);
    }
    strncpy(db->records[db->size].name, name, sizeof(db->records[db->size].name));
    db->records[db->size].age = age;
    db->size++;
}

// Function to display all records
void display_records(Database *db) {
    printf("Database Records:\n");
    for (int i = 0; i < db->size; i++) {
        printf("Record %d: Name: %s, Age: %d\n", i + 1, db->records[i].name, db->records[i].age);
    }
}

// Function to delete a record by index
void delete_record(Database *db, int index) {
    if (index < 0 || index >= db->size) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = index; i < db->size - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->size--;
}

// Main function providing the user interface
int main() {
    Database *db = initialize_database(2);
    int choice;
    char name[50];
    int age;

    while (1) {
        printf("\n--- Simple Database Simulation ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Delete Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                add_record(db, name, age);
                printf("Record added!\n");
                break;

            case 2:
                display_records(db);
                break;

            case 3:
                printf("Enter record index to delete (starting from 0): ");
                int index;
                scanf("%d", &index);
                delete_record(db, index);
                printf("Record deleted (if the index was valid)!\n");
                break;

            case 4:
                free(db->records);
                free(db);
                printf("Exiting the database simulation.\n");
                return 0;

            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    }
}