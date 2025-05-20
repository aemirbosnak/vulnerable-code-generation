//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_DATA_LEN 1000

typedef struct {
    char key[MAX_KEY_LEN];
    char data[MAX_DATA_LEN];
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

void init_database(Database *db) {
    db->records = (Record *)malloc(sizeof(Record) * 100);
    db->num_records = 0;
}

void destroy_database(Database *db) {
    free(db->records);
}

int add_record(Database *db, const char *key, const char *data) {
    if (db->num_records >= 100) {
        return -1;
    }

    strcpy(db->records[db->num_records].key, key);
    strcpy(db->records[db->num_records].data, data);

    db->num_records++;

    return 0;
}

int search_record(Database *db, const char *key) {
    int i;

    for (i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    Database db;

    init_database(&db);

    add_record(&db, "John", "Smith");
    add_record(&db, "Jane", "Doe");
    add_record(&db, "Bob", "Johnson");

    int record_index = search_record(&db, "John");

    if (record_index >= 0) {
        printf("Found record for key '%s': '%s'\n", db.records[record_index].key, db.records[record_index].data);
    } else {
        printf("Record not found.\n");
    }

    destroy_database(&db);

    return 0;
}