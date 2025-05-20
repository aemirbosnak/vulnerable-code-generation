//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 100

typedef struct {
    char *fields[MAX_FIELD_SIZE];
    int num_fields;
} Record;

typedef struct {
    Record *records;
    int num_records;
    char **field_names;
    int num_fields;
} Database;

void initialize_database(Database *db) {
    db->records = (Record *)malloc(MAX_RECORDS * sizeof(Record));
    db->num_records = 0;
    db->field_names = (char **)malloc(MAX_FIELD_SIZE * sizeof(char *));
    db->num_fields = 0;
}

void add_field(Database *db, char *field_name) {
    db->field_names[db->num_fields] = strdup(field_name);
    db->num_fields++;
}

void add_record(Database *db, Record *record) {
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
    printf("Database:\n");
    for (int i = 0; i < db->num_records; i++) {
        for (int j = 0; j < db->num_fields; j++) {
            printf("%s: %s\n", db->field_names[j], db->records[i].fields[j]);
        }
        printf("\n");
    }
}

int main() {
    Database db;
    initialize_database(&db);

    add_field(&db, "Name");
    add_field(&db, "Age");
    add_field(&db, "Gender");

    Record record1;
    record1.fields[0] = strdup("John");
    record1.fields[1] = strdup("25");
    record1.fields[2] = strdup("Male");
    record1.num_fields = 3;
    add_record(&db, &record1);

    Record record2;
    record2.fields[0] = strdup("Jane");
    record2.fields[1] = strdup("30");
    record2.fields[2] = strdup("Female");
    record2.num_fields = 3;
    add_record(&db, &record2);

    print_database(&db);

    return 0;
}