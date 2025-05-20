//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 10
#define MAX_FIELD_LEN 100

typedef struct {
    char *field[MAX_FIELDS];
    int num_fields;
} Record;

typedef struct {
    Record *data;
    int num_records;
} Database;

void init_database(Database *db) {
    db->data = (Record *)malloc(MAX_RECORDS * sizeof(Record));
    db->num_records = 0;
}

void free_database(Database *db) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        free(db->data[i].field);
    }
    free(db->data);
}

void add_record(Database *db, char *fields[], int num_fields) {
    Record *rec = (Record *)malloc(sizeof(Record));
    rec->num_fields = num_fields;
    int i;
    for (i = 0; i < num_fields; i++) {
        rec->field[i] = (char *)malloc(MAX_FIELD_LEN);
        strcpy(rec->field[i], fields[i]);
    }
    db->data[db->num_records++] = *rec;
}

void print_database(Database *db) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        Record *rec = &db->data[i];
        printf("Record %d:\n", i+1);
        int j;
        for (j = 0; j < rec->num_fields; j++) {
            printf("Field %d: %s\n", j+1, rec->field[j]);
        }
    }
}

int main() {
    Database db;
    init_database(&db);
    char *fields1[] = {"John", "Doe", "25"};
    char *fields2[] = {"Jane", "Doe", "30"};
    char *fields3[] = {"Bob", "Smith", "40"};
    add_record(&db, fields1, 3);
    add_record(&db, fields2, 3);
    add_record(&db, fields3, 3);
    print_database(&db);
    free_database(&db);
    return 0;
}