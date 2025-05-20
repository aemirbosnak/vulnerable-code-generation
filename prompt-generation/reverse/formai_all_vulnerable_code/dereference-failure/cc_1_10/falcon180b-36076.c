//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *field1;
    char *field2;
    int field3;
} RECORD;

typedef struct {
    RECORD *records;
    int numRecords;
} DATABASE;

void createDatabase(DATABASE *db) {
    db->records = (RECORD *) malloc(MAX_RECORDS * sizeof(RECORD));
    db->numRecords = 0;
}

void addRecord(DATABASE *db, char *field1, char *field2, int field3) {
    if (db->numRecords >= MAX_RECORDS) {
        printf("Error: Database is full.\n");
        return;
    }

    RECORD *record = &db->records[db->numRecords];
    record->field1 = strdup(field1);
    record->field2 = strdup(field2);
    record->field3 = field3;

    db->numRecords++;
}

void printRecord(RECORD *record) {
    printf("Field 1: %s\n", record->field1);
    printf("Field 2: %s\n", record->field2);
    printf("Field 3: %d\n", record->field3);
}

void printDatabase(DATABASE *db) {
    for (int i = 0; i < db->numRecords; i++) {
        printRecord(&db->records[i]);
    }
}

void searchRecord(DATABASE *db, char *field1, int field3) {
    for (int i = 0; i < db->numRecords; i++) {
        RECORD *record = &db->records[i];

        if (strcmp(record->field1, field1) == 0 && record->field3 == field3) {
            printRecord(record);
        }
    }
}

int main() {
    DATABASE db;
    createDatabase(&db);

    addRecord(&db, "John", "Doe", 25);
    addRecord(&db, "Jane", "Doe", 30);
    addRecord(&db, "Bob", "Smith", 40);

    printDatabase(&db);

    searchRecord(&db, "Doe", 30);

    return 0;
}