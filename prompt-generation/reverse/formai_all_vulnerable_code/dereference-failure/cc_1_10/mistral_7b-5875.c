//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 101

typedef struct {
    char lastName[20];
    int id;
} Record;

int hashFunction(char *lastName) {
    int hash = 0;
    for (int i = 0; lastName[i] != '\0'; i++) {
        hash += lastName[i];
    }
    hash %= TABLE_SIZE;
    return hash;
}

void addRecord(Record *database, char *lastName, int id) {
    int index = hashFunction(lastName);
    if (database[index].id == -1) {
        strcpy(database[index].lastName, lastName);
        database[index].id = id;
    } else {
        addRecord(database, lastName, id); // recursively handle collisions
    }
}

Record *searchRecord(Record *database, char *lastName) {
    int index = hashFunction(lastName);
    if (database[index].id != -1 && strcmp(database[index].lastName, lastName) == 0) {
        return &database[index];
    }
    return NULL;
}

void deleteRecord(Record *database, char *lastName) {
    int index = hashFunction(lastName);
    if (database[index].id != -1 && strcmp(database[index].lastName, lastName) == 0) {
        database[index].id = -1;
    }
}

int main() {
    Record *database = (Record *)calloc(TABLE_SIZE, sizeof(Record));

    addRecord(database, "Smith", 1);
    addRecord(database, "Johnson", 2);
    addRecord(database, "Brown", 3);
    addRecord(database, "Davis", 4);
    addRecord(database, "Williams", 5);

    Record *record = searchRecord(database, "Johnson");
    if (record != NULL) {
        printf("Record found: ID = %d\n", record->id);
    } else {
        printf("Record not found.\n");
    }

    deleteRecord(database, "Brown");

    free(database);

    return 0;
}