//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

void initialize_database(Database *db) {
    db->records = NULL;
    db->num_records = 0;
}

void add_record(Database *db, char *key, char *value) {
    Record *record = (Record *)malloc(sizeof(Record));
    strcpy(record->key, key);
    strcpy(record->value, value);
    db->records = (Record *)realloc(db->records, sizeof(Record) * (db->num_records + 1));
    db->records[db->num_records] = *record;
    db->num_records++;
}

void print_records(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("Key: %s, Value: %s\n", db->records[i].key, db->records[i].value);
    }
}

void free_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        free(db->records[i].key);
        free(db->records[i].value);
    }
    free(db->records);
    db->num_records = 0;
}

int main() {
    Database db;
    initialize_database(&db);

    add_record(&db, "John", "25");
    add_record(&db, "Jane", "30");
    add_record(&db, "Bob", "40");

    printf("Records:\n");
    print_records(&db);

    free_database(&db);

    return 0;
}