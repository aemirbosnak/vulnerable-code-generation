//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 50
#define MAX_DATA_LENGTH 500

typedef struct {
    char key[MAX_KEY_LENGTH];
    char data[MAX_DATA_LENGTH];
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

void create_database(Database *db) {
    db->records = (Record *) malloc(sizeof(Record) * 100);
    db->num_records = 0;
}

int add_record(Database *db, char *key, char *data) {
    Record *record = &db->records[db->num_records];
    strcpy(record->key, key);
    strcpy(record->data, data);
    db->num_records++;
    return 0;
}

int search_record_by_key(Database *db, char *key) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            printf("%s\n", db->records[i].data);
            return 0;
        }
    }
    printf("Record not found.\n");
    return -1;
}

int main() {
    Database db;
    create_database(&db);

    add_record(&db, "John", "123 Main St.");
    add_record(&db, "Jane", "456 Elm St.");

    search_record_by_key(&db, "Jane");

    return 0;
}