//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: retro
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

void init_record(Record *record) {
    int i;
    for (i = 0; i < MAX_FIELD_SIZE; i++) {
        record->fields[i] = NULL;
    }
    record->num_fields = 0;
}

void add_field(Record *record, char *field) {
    int i;
    for (i = 0; i < MAX_FIELD_SIZE; i++) {
        if (record->fields[i] == NULL) {
            record->fields[i] = strdup(field);
            record->num_fields++;
            return;
        }
    }
    // If we reach here, we have too many fields
    printf("Error: Too many fields!\n");
}

void print_record(Record *record) {
    int i;
    for (i = 0; i < record->num_fields; i++) {
        printf("%s ", record->fields[i]);
    }
    printf("\n");
}

void init_database(Database *database) {
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        init_record(&database->records[i]);
    }
    database->num_records = 0;
}

void add_record(Database *database, Record *record) {
    if (database->num_records >= MAX_RECORDS) {
        printf("Error: Too many records!\n");
        return;
    }
    memcpy(&database->records[database->num_records], record, sizeof(Record));
    database->num_records++;
}

void print_database(Database *database) {
    int i;
    for (i = 0; i < database->num_records; i++) {
        print_record(&database->records[i]);
    }
}

int main() {
    Database db;
    init_database(&db);

    Record r1;
    init_record(&r1);
    add_field(&r1, "John");
    add_field(&r1, "Doe");
    add_record(&db, &r1);

    Record r2;
    init_record(&r2);
    add_field(&r2, "Jane");
    add_field(&r2, "Doe");
    add_record(&db, &r2);

    print_database(&db);

    return 0;
}