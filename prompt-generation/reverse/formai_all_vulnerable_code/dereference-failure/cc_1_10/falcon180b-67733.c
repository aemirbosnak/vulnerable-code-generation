//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100
#define MAX_NUM_KEYS 100
#define FILENAME_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

typedef struct {
    Record *records;
    int num_records;
    int num_keys;
} Database;

void createDatabase(Database *db) {
    db->records = (Record *) malloc(MAX_NUM_KEYS * sizeof(Record));
    db->num_records = 0;
    db->num_keys = 0;
}

void destroyDatabase(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        free(db->records[i].key);
        free(db->records[i].value);
    }
    free(db->records);
}

int getKeyIndex(Database *db, char *key) {
    for (int i = 0; i < db->num_keys; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

void addRecord(Database *db, char *key, char *value) {
    int index = getKeyIndex(db, key);
    if (index == -1) {
        if (db->num_records >= MAX_NUM_KEYS) {
            printf("Error: Database is full.\n");
            return;
        }
        if (db->num_keys >= MAX_NUM_KEYS) {
            printf("Error: Too many keys.\n");
            return;
        }
        strcpy(db->records[db->num_keys].key, key);
        db->num_keys++;
    }
    strcpy(db->records[index].value, value);
    db->num_records++;
}

void searchDatabase(Database *db, char *key) {
    int index = getKeyIndex(db, key);
    if (index == -1) {
        printf("Key not found.\n");
        return;
    }
    printf("Value for key '%s': %s\n", db->records[index].key, db->records[index].value);
}

void printDatabase(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("Key: %s, Value: %s\n", db->records[i].key, db->records[i].value);
    }
}

int main() {
    Database db;
    createDatabase(&db);

    addRecord(&db, "Name", "John Smith");
    addRecord(&db, "Age", "30");
    addRecord(&db, "City", "New York");

    searchDatabase(&db, "Name");
    searchDatabase(&db, "Age");
    searchDatabase(&db, "City");

    printDatabase(&db);

    destroyDatabase(&db);
    return 0;
}