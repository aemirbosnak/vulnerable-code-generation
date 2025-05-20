//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: futuristic
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
    db->records = malloc(max_records * sizeof(Record));
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
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            strcpy(value, db->records[i].value);
            return 0;
        }
    }

    return -1;
}

int main() {
    Database db;
    init_database(&db, 10);

    add_record(&db, "name", "John");
    add_record(&db, "age", "30");
    add_record(&db, "city", "New York");

    char value[MAX_VALUE_LEN];
    search_record(&db, "name", value);
    printf("Name: %s\n", value);

    search_record(&db, "address", value);
    printf("Address: %s\n", value);

    destroy_database(&db);

    return 0;
}