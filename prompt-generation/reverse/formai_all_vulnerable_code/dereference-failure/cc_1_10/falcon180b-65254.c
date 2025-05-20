//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

typedef struct {
    Record *records;
    int num_records;
    int max_records;
} Database;

void init_database(Database *db, int max_records) {
    db->records = malloc(max_records * sizeof(Record));
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
    strcpy(record->key, key);
    strcpy(record->value, value);

    db->num_records++;

    return 0;
}

int search_record(Database *db, const char *key, char *value) {
    int i;

    for (i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            strcpy(value, db->records[i].value);
            return 0;
        }
    }

    return -1;
}

void print_record(const Record *record) {
    printf("Key: %s, Value: %s\n", record->key, record->value);
}

int main() {
    Database db;
    init_database(&db, 10);

    add_record(&db, "John", "25");
    add_record(&db, "Jane", "30");
    add_record(&db, "Bob", "40");

    char value[MAX_VALUE_LENGTH];
    search_record(&db, "Bob", value);
    printf("Found record for Bob: %s\n", value);

    print_record(&db.records[0]);
    print_record(&db.records[1]);
    print_record(&db.records[2]);

    destroy_database(&db);

    return 0;
}