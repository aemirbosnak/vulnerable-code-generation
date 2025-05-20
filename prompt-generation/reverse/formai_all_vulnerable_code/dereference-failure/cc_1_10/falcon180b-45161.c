//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 32
#define MAX_VALUE_LENGTH 64

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

typedef struct {
    Record *records;
    int numRecords;
    int maxRecords;
} Database;

void initDatabase(Database *db) {
    db->records = malloc(sizeof(Record) * 10);
    db->numRecords = 0;
    db->maxRecords = 10;
}

void destroyDatabase(Database *db) {
    free(db->records);
}

int addRecord(Database *db, char *name, char *value) {
    if (db->numRecords >= db->maxRecords) {
        return -1;
    }

    Record *record = db->records + db->numRecords;
    strncpy(record->name, name, MAX_NAME_LENGTH);
    strncpy(record->value, value, MAX_VALUE_LENGTH);

    db->numRecords++;
    return 0;
}

int queryDatabase(Database *db, char *query) {
    char *token;
    char *name = NULL;
    char *value = NULL;
    int numConditions = 0;

    token = strtok(query, " ");
    while (token!= NULL) {
        if (numConditions == 0) {
            name = token;
        } else if (numConditions == 1) {
            value = token;
        } else {
            break;
        }

        numConditions++;
        token = strtok(NULL, " ");
    }

    if (numConditions!= 2) {
        return -1;
    }

    int i;
    for (i = 0; i < db->numRecords; i++) {
        Record *record = db->records + i;

        if (strcmp(record->name, name) == 0 && strcmp(record->value, value) == 0) {
            printf("Record found: %s = %s\n", record->name, record->value);
            return 0;
        }
    }

    printf("Record not found\n");
    return -1;
}

int main() {
    Database db;
    initDatabase(&db);

    addRecord(&db, "name", "John");
    addRecord(&db, "age", "25");
    addRecord(&db, "gender", "male");

    queryDatabase(&db, "name John");
    queryDatabase(&db, "age 25");
    queryDatabase(&db, "gender male");

    destroyDatabase(&db);
    return 0;
}