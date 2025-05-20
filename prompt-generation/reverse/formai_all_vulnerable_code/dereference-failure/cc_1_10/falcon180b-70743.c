//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 100
#define MAX_RECORDS 1000

typedef struct {
    char *data;
    int size;
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

void init_database(Database *db) {
    db->records = malloc(MAX_RECORDS * sizeof(Record));
    db->num_records = 0;
}

void add_record(Database *db, char *data, int size) {
    if (db->num_records >= MAX_RECORDS) {
        printf("Error: Database is full.\n");
        return;
    }

    Record *record = malloc(sizeof(Record));
    record->data = data;
    record->size = size;

    db->records[db->num_records] = *record;
    db->num_records++;
}

void search_record(Database *db, char *key, int keylen) {
    for (int i = 0; i < db->num_records; i++) {
        Record *record = &db->records[i];

        if (strncmp(record->data, key, keylen) == 0) {
            printf("Record found: %s\n", record->data);
            return;
        }
    }

    printf("Record not found.\n");
}

void delete_record(Database *db, char *key, int keylen) {
    for (int i = 0; i < db->num_records; i++) {
        Record *record = &db->records[i];

        if (strncmp(record->data, key, keylen) == 0) {
            free(record->data);
            db->num_records--;
            return;
        }
    }

    printf("Record not found.\n");
}

int main() {
    Database db;
    init_database(&db);

    add_record(&db, "John Doe", 9);
    add_record(&db, "Jane Smith", 10);
    add_record(&db, "Bob Johnson", 11);

    search_record(&db, "John", 4);
    search_record(&db, "Jane", 4);
    search_record(&db, "Bob", 3);

    delete_record(&db, "John", 4);

    return 0;
}