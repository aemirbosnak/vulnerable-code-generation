//FormAI DATASET v1.0 Category: Database simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define record and database structures
typedef struct {
    int id;
    char name[50];
    float salary;
} Record;

typedef struct {
    Record** records;
    int size;
} Database;

// Function declarations
Database* createDatabase(int size);
void insertRecord(Database* db, Record* rec);
Record* findRecord(Database* db, int id);
void deleteRecord(Database* db, int id);
void printDatabase(Database* db);
void destroyDatabase(Database* db);

// Create an instance of the database structure
Database* createDatabase(int size) {
    Database* db = (Database*) malloc(sizeof(Database));
    db->records = (Record**) malloc(size * sizeof(Record*));
    db->size = size;
    return db;
}

// Insert a record into the database
void insertRecord(Database* db, Record* rec) {
    int pos = -1;
    for (int i = 0; i < db->size; i++) {
        if (db->records[i] == NULL) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        db->records[pos] = rec;
    } else {
        printf("Database is full!\n");
    }
}

// Find a record in the database by its id
Record* findRecord(Database* db, int id) {
    for (int i = 0; i < db->size; i++) {
        if (db->records[i] != NULL && db->records[i]->id == id) {
            return db->records[i];
        }
    }
    return NULL;
}

// Delete a record from the database by its id
void deleteRecord(Database* db, int id) {
    Record* rec = findRecord(db, id);
    if (rec != NULL) {
        int pos = -1;
        for (int i = 0; i < db->size; i++) {
            if (db->records[i] == rec) {
                pos = i;
                break;
            }
        }
        if (pos != -1) {
            db->records[pos] = NULL;
        }
    } else {
        printf("Record not found!\n");
    }
}

// Print the entire database
void printDatabase(Database* db) {
    for (int i = 0; i < db->size; i++) {
        if (db->records[i] != NULL) {
            printf("ID: %d, Name: %s, Salary: %.2f\n", db->records[i]->id, db->records[i]->name, db->records[i]->salary);
        }
    }
}

// Destroy the entire database and free up memory
void destroyDatabase(Database* db) {
    for (int i = 0; i < db->size; i++) {
        if (db->records[i] != NULL) {
            free(db->records[i]);
        }
    }
    free(db->records);
    free(db);
}

int main() {
    // Create database with 3 records
    Database* db = createDatabase(3);

    // Insert records into the database
    Record* rec1 = (Record*) malloc(sizeof(Record));
    rec1->id = 1001;
    strcpy(rec1->name, "John Smith");
    rec1->salary = 50000.00;
    insertRecord(db, rec1);

    Record* rec2 = (Record*) malloc(sizeof(Record));
    rec2->id = 1002;
    strcpy(rec2->name, "Jane Doe");
    rec2->salary = 60000.00;
    insertRecord(db, rec2);

    Record* rec3 = (Record*) malloc(sizeof(Record));
    rec3->id = 1003;
    strcpy(rec3->name, "Bob Johnson");
    rec3->salary = 70000.00;
    insertRecord(db, rec3);

    // Print the entire database
    printf("Database Contents:\n");
    printDatabase(db);

    // Delete a record from the database
    printf("Deleting record with ID 1002...\n");
    deleteRecord(db, 1002);

    // Print the entire database again
    printf("Database Contents after deletion:\n");
    printDatabase(db);

    // Destroy the entire database and free up memory
    destroyDatabase(db);
    return 0;
}