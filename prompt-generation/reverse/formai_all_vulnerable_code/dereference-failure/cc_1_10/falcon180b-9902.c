//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_RECORD_SIZE 200
#define MAX_INDEX_SIZE 100

typedef struct {
    char *key;
    int record_size;
    int index;
} Record;

typedef struct {
    Record *records;
    int num_records;
    int max_records;
} Database;

void create_database(Database *db, int max_records) {
    db->records = (Record *)malloc(max_records * sizeof(Record));
    db->num_records = 0;
    db->max_records = max_records;
}

void destroy_database(Database *db) {
    free(db->records);
}

int add_record(Database *db, char *key, int record_size) {
    if (db->num_records >= db->max_records) {
        return -1;
    }

    Record *record = &db->records[db->num_records];
    record->key = malloc(strlen(key) + 1);
    strcpy(record->key, key);
    record->record_size = record_size;
    record->index = db->num_records;

    db->num_records++;

    return record->index;
}

int search_record(Database *db, char *key) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        Record *record = &db->records[i];
        if (strcmp(record->key, key) == 0) {
            return record->index;
        }
    }

    return -1;
}

void print_record(Record *record) {
    printf("Key: %s\n", record->key);
    printf("Record size: %d\n", record->record_size);
    printf("Index: %d\n", record->index);
}

int main() {
    Database db;
    create_database(&db, 100);

    add_record(&db, "John", 50);
    add_record(&db, "Jane", 70);
    add_record(&db, "Alice", 30);

    int index = search_record(&db, "Jane");
    if (index!= -1) {
        print_record(&db.records[index]);
    }

    destroy_database(&db);

    return 0;
}