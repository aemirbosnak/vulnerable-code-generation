//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VAL_LEN 1000

typedef struct {
    char key[MAX_KEY_LEN];
    char val[MAX_VAL_LEN];
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

int add_record(Database *db, char *key, char *val) {
    if (db->num_records >= db->max_records) {
        return -1;
    }

    Record *record = &db->records[db->num_records];
    strcpy(record->key, key);
    strcpy(record->val, val);

    db->num_records++;
    return 0;
}

int search_record(Database *db, char *key, char *val) {
    for (int i = 0; i < db->num_records; i++) {
        Record *record = &db->records[i];
        if (strcmp(record->key, key) == 0) {
            strcpy(val, record->val);
            return 0;
        }
    }

    return -1;
}

int main() {
    Database db;
    init_database(&db, 10);

    add_record(&db, "apple", "red");
    add_record(&db, "banana", "yellow");
    add_record(&db, "orange", "orange");

    char key[MAX_KEY_LEN];
    char val[MAX_VAL_LEN];

    scanf("%s", key);
    int result = search_record(&db, key, val);

    if (result == 0) {
        printf("%s = %s\n", key, val);
    } else {
        printf("Not found\n");
    }

    return 0;
}