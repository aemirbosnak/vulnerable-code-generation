//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *fields[MAX_FIELD_SIZE];
    int num_fields;
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

void init_database(Database *db) {
    db->records = NULL;
    db->num_records = 0;
}

void add_record(Database *db, Record *record) {
    db->records = realloc(db->records, sizeof(Record) * (db->num_records + 1));
    db->records[db->num_records] = *record;
    db->num_records++;
}

void print_record(Record *record) {
    for (int i = 0; i < record->num_fields; i++) {
        printf("%s ", record->fields[i]);
    }
    printf("\n");
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        print_record(db->records + i);
    }
}

int main() {
    Database db;
    init_database(&db);

    Record record1;
    record1.fields[0] = "John";
    record1.fields[1] = "Doe";
    record1.num_fields = 2;
    add_record(&db, &record1);

    Record record2;
    record2.fields[0] = "Jane";
    record2.fields[1] = "Doe";
    record2.num_fields = 2;
    add_record(&db, &record2);

    Record record3;
    record3.fields[0] = "Bob";
    record3.fields[1] = "Smith";
    record3.num_fields = 2;
    add_record(&db, &record3);

    print_database(&db);

    return 0;
}