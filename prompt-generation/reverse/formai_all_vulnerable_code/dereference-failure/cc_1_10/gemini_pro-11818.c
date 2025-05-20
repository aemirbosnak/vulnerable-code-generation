//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 10

typedef struct {
    char *name;
    char *value;
} field;

typedef struct {
    int num_fields;
    field fields[MAX_FIELDS];
} record;

typedef struct {
    int num_records;
    record records[MAX_RECORDS];
} database;

database *create_database() {
    database *db = malloc(sizeof(database));
    db->num_records = 0;
    return db;
}

void destroy_database(database *db) {
    for (int i = 0; i < db->num_records; i++) {
        for (int j = 0; j < db->records[i].num_fields; j++) {
            free(db->records[i].fields[j].name);
            free(db->records[i].fields[j].value);
        }
    }
    free(db);
}

record *create_record() {
    record *r = malloc(sizeof(record));
    r->num_fields = 0;
    return r;
}

void destroy_record(record *r) {
    for (int i = 0; i < r->num_fields; i++) {
        free(r->fields[i].name);
        free(r->fields[i].value);
    }
    free(r);
}

void add_field(record *r, char *name, char *value) {
    r->fields[r->num_fields].name = strdup(name);
    r->fields[r->num_fields].value = strdup(value);
    r->num_fields++;
}

void add_record(database *db, record *r) {
    db->records[db->num_records] = *r;
    db->num_records++;
}

int main() {
    database *db = create_database();

    record *r1 = create_record();
    add_field(r1, "name", "John Doe");
    add_field(r1, "age", "30");
    add_field(r1, "city", "New York");
    add_record(db, r1);

    record *r2 = create_record();
    add_field(r2, "name", "Jane Doe");
    add_field(r2, "age", "25");
    add_field(r2, "city", "London");
    add_record(db, r2);

    // Print the database
    for (int i = 0; i < db->num_records; i++) {
        printf("Record %d:\n", i + 1);
        for (int j = 0; j < db->records[i].num_fields; j++) {
            printf("  %s = %s\n", db->records[i].fields[j].name, db->records[i].fields[j].value);
        }
    }

    // Destroy the database
    destroy_database(db);

    return 0;
}