//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Record;

typedef struct {
    Record* records;
    int numRecords;
} Database;

Database* createDatabase() {
    Database* db = malloc(sizeof(Database));
    db->records = NULL;
    db->numRecords = 0;
    return db;
}

void destroyDatabase(Database* db) {
    for (int i = 0; i < db->numRecords; i++) {
        free(db->records[i].name);
        free(db->records[i].value);
    }
    free(db->records);
    free(db);
}

void addRecord(Database* db, char* name, char* value) {
    Record* record = malloc(sizeof(Record));
    strcpy(record->name, name);
    strcpy(record->value, value);
    db->records = realloc(db->records, sizeof(Record) * (db->numRecords + 1));
    db->records[db->numRecords] = *record;
    db->numRecords++;
}

void printRecord(Record* record) {
    printf("Name: %s\nValue: %s\n", record->name, record->value);
}

void printDatabase(Database* db) {
    for (int i = 0; i < db->numRecords; i++) {
        printRecord(&db->records[i]);
    }
}

int main() {
    Database* db = createDatabase();
    addRecord(db, "John", "25");
    addRecord(db, "Jane", "30");
    addRecord(db, "Bob", "40");
    printDatabase(db);
    destroyDatabase(db);
    return 0;
}