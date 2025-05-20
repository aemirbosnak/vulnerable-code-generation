//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_KEY_LEN 100
#define MAX_VAL_LEN 1000

typedef struct {
    char key[MAX_KEY_LEN];
    char val[MAX_VAL_LEN];
    int len;
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

void init_database(Database *db) {
    db->records = NULL;
    db->num_records = 0;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        free(db->records[i].key);
        free(db->records[i].val);
    }
    free(db->records);
}

void add_record(Database *db, char *key, char *val) {
    Record record;
    strcpy(record.key, key);
    strcpy(record.val, val);
    record.len = strlen(record.key);
    db->records = realloc(db->records, sizeof(Record) * (db->num_records + 1));
    db->records[db->num_records++] = record;
}

bool search_record(Database *db, char *key) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            printf("%s\n", db->records[i].val);
            return true;
        }
    }
    return false;
}

int main() {
    Database db;
    init_database(&db);

    add_record(&db, "apple", "red");
    add_record(&db, "banana", "yellow");
    add_record(&db, "cherry", "red");

    search_record(&db, "apple");
    search_record(&db, "orange");

    destroy_database(&db);
    return 0;
}