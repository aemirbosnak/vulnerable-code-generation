//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} Record;

typedef struct {
    Record *records;
    int num_records;
    int max_records;
} Database;

void init_database(Database *db, int max_records) {
    db->records = (Record *)malloc(max_records * sizeof(Record));
    db->num_records = 0;
    db->max_records = max_records;
}

void destroy_database(Database *db) {
    free(db->records);
}

int add_record(Database *db, char *key, char *value) {
    if (db->num_records >= db->max_records) {
        return -1; // database is full
    }

    Record *record = &db->records[db->num_records];
    strcpy(record->key, key);
    strcpy(record->value, value);

    db->num_records++;

    return 0;
}

int search_record(Database *db, char *key) {
    for (int i = 0; i < db->num_records; i++) {
        Record *record = &db->records[i];
        if (strcmp(record->key, key) == 0) {
            return i;
        }
    }

    return -1; // record not found
}

void print_record(Record *record) {
    printf("Key: %s\nValue: %s\n", record->key, record->value);
}

int main() {
    Database db;
    init_database(&db, 10);

    add_record(&db, "name", "John");
    add_record(&db, "age", "30");
    add_record(&db, "city", "New York");

    int index = search_record(&db, "name");
    if (index!= -1) {
        print_record(&db.records[index]);
    }

    destroy_database(&db);

    return 0;
}