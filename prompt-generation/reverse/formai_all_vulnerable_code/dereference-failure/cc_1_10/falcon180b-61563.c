//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *field1;
    char *field2;
    int field3;
} Record;

typedef struct {
    Record *records;
    int numRecords;
    int maxRecords;
} Database;

void initDatabase(Database *db) {
    db->records = malloc(MAX_RECORDS * sizeof(Record));
    db->numRecords = 0;
    db->maxRecords = MAX_RECORDS;
}

void destroyDatabase(Database *db) {
    for (int i = 0; i < db->numRecords; i++) {
        free(db->records[i].field1);
        free(db->records[i].field2);
    }
    free(db->records);
}

void addRecord(Database *db, char *field1, char *field2, int field3) {
    if (db->numRecords >= db->maxRecords) {
        printf("Error: Database is full\n");
        return;
    }
    Record *record = &db->records[db->numRecords];
    record->field1 = strdup(field1);
    record->field2 = strdup(field2);
    record->field3 = field3;
    db->numRecords++;
}

void printRecords(Database *db) {
    for (int i = 0; i < db->numRecords; i++) {
        printf("Record %d:\n", i+1);
        printf("Field1: %s\n", db->records[i].field1);
        printf("Field2: %s\n", db->records[i].field2);
        printf("Field3: %d\n\n", db->records[i].field3);
    }
}

int main() {
    Database db;
    initDatabase(&db);
    addRecord(&db, "John", "Doe", 25);
    addRecord(&db, "Jane", "Doe", 30);
    printRecords(&db);
    destroyDatabase(&db);
    return 0;
}