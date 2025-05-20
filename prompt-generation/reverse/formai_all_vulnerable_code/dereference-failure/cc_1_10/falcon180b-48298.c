//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_KEY_SIZE 50

typedef struct {
    char key[MAX_KEY_SIZE];
    int value;
} Record;

typedef struct {
    Record* data;
    int size;
} Database;

void createDatabase(Database* db) {
    db->size = 0;
    db->data = (Record*)malloc(MAX_SIZE * sizeof(Record));
}

void insertRecord(Database* db, char* key, int value) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->key, key);
    newRecord->value = value;
    db->data[db->size++] = *newRecord;
    free(newRecord);
}

void deleteRecord(Database* db, char* key) {
    int i;
    for (i = 0; i < db->size; i++) {
        if (strcmp(db->data[i].key, key) == 0) {
            db->size--;
            break;
        }
    }
}

int searchRecord(Database* db, char* key) {
    int i;
    for (i = 0; i < db->size; i++) {
        if (strcmp(db->data[i].key, key) == 0) {
            return db->data[i].value;
        }
    }
    return -1;
}

void printDatabase(Database* db) {
    int i;
    for (i = 0; i < db->size; i++) {
        printf("%s %d\n", db->data[i].key, db->data[i].value);
    }
}

int main() {
    Database db;
    createDatabase(&db);
    insertRecord(&db, "John", 25);
    insertRecord(&db, "Jane", 30);
    insertRecord(&db, "Mike", 35);
    printDatabase(&db);
    printf("%d\n", searchRecord(&db, "John"));
    deleteRecord(&db, "Mike");
    printDatabase(&db);
    return 0;
}