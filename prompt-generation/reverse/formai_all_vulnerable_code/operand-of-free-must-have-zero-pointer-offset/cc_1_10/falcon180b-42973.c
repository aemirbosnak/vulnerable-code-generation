//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUM_FIELDS 10
#define MAX_FIELD_NAME_LENGTH 20
#define MAX_DATA_LENGTH 100

typedef struct {
    char *name;
    char *data;
} Field;

typedef struct {
    int num_fields;
    Field fields[MAX_NUM_FIELDS];
} Record;

typedef struct {
    int num_records;
    Record records[MAX_NUM_FIELDS];
} Database;

Database *create_database() {
    Database *db = (Database *)malloc(sizeof(Database));
    if (db == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }
    db->num_records = 0;
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        for (int j = 0; j < db->records[i].num_fields; j++) {
            free(db->records[i].fields[j].data);
        }
        free(db->records[i].fields);
    }
    free(db->records);
    free(db);
}

void add_field(Field *field, char *name, char *data) {
    field->name = strdup(name);
    field->data = strdup(data);
}

void add_record(Database *db, Record *record) {
    db->records[db->num_records++] = *record;
}

void print_record(Record *record) {
    printf("Record:\n");
    for (int i = 0; i < record->num_fields; i++) {
        printf("  %s: %s\n", record->fields[i].name, record->fields[i].data);
    }
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        print_record(&db->records[i]);
        printf("\n");
    }
}

int main() {
    Database *db = create_database();

    Record record1 = {2, {{strdup("Name"), strdup("John")}, {strdup("Age"), strdup("30")}}};
    add_record(db, &record1);

    Record record2 = {3, {{strdup("Name"), strdup("Jane")}, {strdup("Age"), strdup("25")}, {strdup("Gender"), strdup("Female")}}};
    add_record(db, &record2);

    print_database(db);

    destroy_database(db);

    return 0;
}