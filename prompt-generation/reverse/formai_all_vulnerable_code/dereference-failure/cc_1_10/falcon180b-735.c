//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000

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

int add_record(Database *db, const char *key, const char *value) {
    if (db->num_records >= db->max_records) {
        return -1;
    }

    Record *record = &db->records[db->num_records];
    strncpy(record->key, key, MAX_KEY_LEN);
    strncpy(record->value, value, MAX_VALUE_LEN);

    db->num_records++;

    return 0;
}

int search_record(Database *db, const char *key) {
    for (int i = 0; i < db->num_records; i++) {
        Record *record = &db->records[i];
        if (strcmp(record->key, key) == 0) {
            printf("Value: %s\n", record->value);
            return 0;
        }
    }

    printf("Record not found.\n");
    return -1;
}

int main() {
    Database db;
    init_database(&db, 10);

    add_record(&db, "apple", "red");
    add_record(&db, "banana", "yellow");
    add_record(&db, "cherry", "red");

    search_record(&db, "apple");
    search_record(&db, "orange");

    destroy_database(&db);

    return 0;
}