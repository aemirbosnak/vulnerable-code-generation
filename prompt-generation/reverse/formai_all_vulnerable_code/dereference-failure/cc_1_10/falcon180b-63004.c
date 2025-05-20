//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 10
#define MAX_FIELD_LEN 50

typedef struct {
    char *fields[MAX_FIELDS];
    int num_fields;
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

void init_record(Record *record) {
    for (int i = 0; i < MAX_FIELDS; i++) {
        record->fields[i] = NULL;
    }
    record->num_fields = 0;
}

void add_field(Record *record, char *field) {
    if (record->num_fields >= MAX_FIELDS) {
        printf("Error: Maximum number of fields reached.\n");
        return;
    }
    record->fields[record->num_fields] = strdup(field);
    record->num_fields++;
}

void print_record(Record *record) {
    for (int i = 0; i < record->num_fields; i++) {
        printf("%s ", record->fields[i]);
    }
    printf("\n");
}

void init_database(Database *database) {
    for (int i = 0; i < MAX_RECORDS; i++) {
        init_record(&database->records[i]);
    }
    database->num_records = 0;
}

void add_record(Database *database, Record *record) {
    if (database->num_records >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached.\n");
        return;
    }
    for (int i = 0; i < record->num_fields; i++) {
        add_field(&database->records[database->num_records], record->fields[i]);
    }
    database->num_records++;
}

void search_database(Database *database, char *query) {
    int num_matches = 0;
    for (int i = 0; i < database->num_records; i++) {
        int j;
        for (j = 0; j < database->records[i].num_fields; j++) {
            if (strstr(database->records[i].fields[j], query)) {
                print_record(&database->records[i]);
                num_matches++;
                break;
            }
        }
    }
    if (num_matches == 0) {
        printf("No results found.\n");
    }
}

int main() {
    Database db;
    init_database(&db);

    Record r1;
    init_record(&r1);
    add_field(&r1, "John Doe");
    add_field(&r1, "123 Main St");
    add_field(&r1, "Anytown, USA");
    add_record(&db, &r1);

    Record r2;
    init_record(&r2);
    add_field(&r2, "Jane Doe");
    add_field(&r2, "456 Elm St");
    add_field(&r2, "Anytown, USA");
    add_record(&db, &r2);

    search_database(&db, "Doe");

    return 0;
}