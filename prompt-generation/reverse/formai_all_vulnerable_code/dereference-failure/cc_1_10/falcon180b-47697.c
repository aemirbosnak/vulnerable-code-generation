//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
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

int add_record(Database *db, char *name, char *value) {
    if (db->num_records >= db->max_records) {
        printf("Database is full.\n");
        return -1;
    }

    Record *record = &db->records[db->num_records];
    strcpy(record->name, name);
    strcpy(record->value, value);

    db->num_records++;

    return 0;
}

int search_record(Database *db, char *name) {
    for (int i = 0; i < db->num_records; i++) {
        Record *record = &db->records[i];
        if (strcmp(record->name, name) == 0) {
            printf("Name: %s\nValue: %s\n", record->name, record->value);
            return 0;
        }
    }

    printf("Record not found.\n");
    return -1;
}

int main() {
    Database db;
    init_database(&db, 10);

    add_record(&db, "John", "Doe");
    add_record(&db, "Jane", "Doe");
    add_record(&db, "Bob", "Smith");

    search_record(&db, "John");
    search_record(&db, "Alice");

    destroy_database(&db);

    return 0;
}