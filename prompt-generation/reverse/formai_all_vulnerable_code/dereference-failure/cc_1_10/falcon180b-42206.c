//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: detailed
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
    db->records = (Record *)malloc(max_records * sizeof(Record));
    db->num_records = 0;
    db->max_records = max_records;
}

void destroy_database(Database *db) {
    free(db->records);
}

int add_record(Database *db, char *key, char *value) {
    if (db->num_records >= db->max_records) {
        return -1;
    }

    Record *record = &db->records[db->num_records];
    strcpy(record->key, key);
    strcpy(record->value, value);

    db->num_records++;

    return 0;
}

int search_record(Database *db, char *key, char *value) {
    for (int i = 0; i < db->num_records; i++) {
        Record *record = &db->records[i];
        if (strcmp(record->key, key) == 0) {
            strcpy(value, record->value);
            return 0;
        }
    }

    return -1;
}

int main() {
    Database db;
    init_database(&db, 10);

    add_record(&db, "John", "25");
    add_record(&db, "Jane", "30");
    add_record(&db, "Bob", "40");

    char value[MAX_VALUE_LENGTH];
    search_record(&db, "John", value);
    printf("John's age: %s\n", value);

    search_record(&db, "Alice", value);
    printf("Alice's age: %s\n", value);

    destroy_database(&db);

    return 0;
}