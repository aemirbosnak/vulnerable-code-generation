//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100
#define NAME_SIZE 50

typedef struct Record {
    int id;
    char name[NAME_SIZE];
    float balance;
    struct Record* next;
} Record;

typedef struct Database {
    Record* table[TABLE_SIZE];
} Database;

int hash(int id) {
    return id % TABLE_SIZE;
}

Database* createDatabase() {
    Database* db = malloc(sizeof(Database));
    for (int i = 0; i < TABLE_SIZE; i++) {
        db->table[i] = NULL;
    }
    return db;
}

void insertRecord(Database* db, int id, const char* name, float balance) {
    int index = hash(id);
    Record* newRecord = malloc(sizeof(Record));
    newRecord->id = id;
    strncpy(newRecord->name, name, NAME_SIZE);
    newRecord->balance = balance;
    newRecord->next = db->table[index];
    db->table[index] = newRecord;
}

Record* findRecord(Database* db, int id) {
    int index = hash(id);
    Record* current = db->table[index];
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleteRecord(Database* db, int id) {
    int index = hash(id);
    Record* current = db->table[index];
    Record* previous = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                db->table[index] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Record with ID %d deleted.\n", id);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Record with ID %d not found.\n", id);
}

void displayDatabase(Database* db) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Record* current = db->table[i];
        if (current != NULL) {
            printf("Index %d:\n", i);
            while (current != NULL) {
                printf("  ID: %d, Name: %s, Balance: %.2f\n", current->id, current->name, current->balance);
                current = current->next;
            }
        }
    }
}

void freeDatabase(Database* db) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Record* current = db->table[i];
        while (current != NULL) {
            Record* toDelete = current;
            current = current->next;
            free(toDelete);
        }
    }
    free(db);
}

int main() {
    Database* db = createDatabase();

    insertRecord(db, 1, "Alice", 1500.00);
    insertRecord(db, 2, "Bob", 2000.50);
    insertRecord(db, 3, "Charlie", 1200.75);

    printf("Current records in the database:\n");
    displayDatabase(db);

    Record* rec = findRecord(db, 2);
    if (rec != NULL) {
        printf("Found: ID: %d, Name: %s, Balance: %.2f\n", rec->id, rec->name, rec->balance);
    } else {
        printf("Record not found\n");
    }

    deleteRecord(db, 2);
    printf("After deletion:\n");
    displayDatabase(db);

    rec = findRecord(db, 2);
    if (rec != NULL) {
        printf("Found: ID: %d, Name: %s, Balance: %.2f\n", rec->id, rec->name, rec->balance);
    } else {
        printf("Record not found\n");
    }

    freeDatabase(db);
    return 0;
}