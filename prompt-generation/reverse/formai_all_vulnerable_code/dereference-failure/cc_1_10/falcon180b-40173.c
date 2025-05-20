//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_FIELD_LENGTH 100
#define MAX_NUM_FIELDS 10

typedef struct {
    char *field[MAX_NUM_FIELDS];
    int num_fields;
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

void init_database(Database *db) {
    db->records = (Record *)malloc(MAX_RECORDS * sizeof(Record));
    db->num_records = 0;
}

void add_record(Database *db, char **fields, int num_fields) {
    Record *record = (Record *)malloc(sizeof(Record));
    record->num_fields = num_fields;
    for(int i = 0; i < num_fields; i++) {
        record->field[i] = (char *)malloc(MAX_FIELD_LENGTH * sizeof(char));
        strcpy(record->field[i], fields[i]);
    }
    db->records[db->num_records++] = *record;
}

void print_records(Database db) {
    for(int i = 0; i < db.num_records; i++) {
        for(int j = 0; j < db.records[i].num_fields; j++) {
            printf("%s ", db.records[i].field[j]);
        }
        printf("\n");
    }
}

int main() {
    Database db;
    init_database(&db);

    add_record(&db, (char *[]){"John", "Doe", "25"}, 3);
    add_record(&db, (char *[]){"Jane", "Doe", "30"}, 3);
    add_record(&db, (char *[]){"Bob", "Smith", "40"}, 3);

    print_records(db);

    return 0;
}