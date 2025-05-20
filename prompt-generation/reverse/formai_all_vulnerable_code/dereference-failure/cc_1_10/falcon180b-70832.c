//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10
#define MAX_FIELD_SIZE 50

typedef struct {
    char *fields[MAX_FIELD_SIZE];
    int num_fields;
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

Database *create_database() {
    Database *db = (Database *)malloc(sizeof(Database));
    db->records = (Record *)malloc(MAX_RECORDS * sizeof(Record));
    db->num_records = 0;
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        for (int j = 0; j < db->records[i].num_fields; j++) {
            free(db->records[i].fields[j]);
        }
        free(db->records[i].fields);
    }
    free(db->records);
    free(db);
}

void add_record(Database *db, const char *fields[], int num_fields) {
    if (db->num_records >= MAX_RECORDS) {
        printf("Error: database is full\n");
        return;
    }
    Record *record = &db->records[db->num_records];
    record->num_fields = num_fields;
    for (int i = 0; i < num_fields; i++) {
        record->fields[i] = (char *)malloc(sizeof(char) * (strlen(fields[i]) + 1));
        strcpy(record->fields[i], fields[i]);
    }
    db->num_records++;
}

void print_record(const Record *record) {
    for (int i = 0; i < record->num_fields; i++) {
        printf("%s ", record->fields[i]);
    }
    printf("\n");
}

void print_database(const Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        print_record(&db->records[i]);
    }
}

int main() {
    Database *db = create_database();
    add_record(db, (const char *[]){"Name", "Age", "Gender"}, 3);
    add_record(db, (const char *[]){"John", "25", "Male"}, 3);
    add_record(db, (const char *[]){"Jane", "30", "Female"}, 3);
    print_database(db);
    destroy_database(db);
    return 0;
}