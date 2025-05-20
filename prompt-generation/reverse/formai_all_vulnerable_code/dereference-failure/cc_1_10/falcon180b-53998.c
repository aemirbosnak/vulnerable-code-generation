//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX 10
#define MAX_NAME 50
#define MAX_VALUE 100

typedef struct {
    char name[MAX_NAME];
    char value[MAX_VALUE];
    int index;
} Record;

typedef struct {
    Record *records;
    int size;
} Database;

int compare(const void *a, const void *b) {
    Record *record1 = (Record *)a;
    Record *record2 = (Record *)b;

    return strcmp(record1->name, record2->name);
}

void init_database(Database *db) {
    db->records = NULL;
    db->size = 0;
}

void add_record(Database *db, char *name, char *value) {
    Record *record = (Record *)malloc(sizeof(Record));

    strcpy(record->name, name);
    strcpy(record->value, value);
    record->index = -1;

    db->records = (Record *)realloc(db->records, sizeof(Record) * (db->size + 1));
    db->records[db->size] = *record;
    db->size++;
}

void create_index(Database *db) {
    qsort(db->records, db->size, sizeof(Record), compare);

    for (int i = 0; i < db->size; i++) {
        db->records[i].index = i;
    }
}

void search_record(Database *db, char *name) {
    Record *record = bsearch(name, db->records, db->size, sizeof(Record), compare);

    if (record!= NULL) {
        printf("Name: %s\nValue: %s\n", record->name, record->value);
    } else {
        printf("Record not found.\n");
    }
}

int main() {
    Database db;
    init_database(&db);

    add_record(&db, "John", "25");
    add_record(&db, "Jane", "30");
    add_record(&db, "Doe", "35");

    create_index(&db);

    search_record(&db, "Jane");

    return 0;
}