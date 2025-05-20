//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_COLUMNS 10
#define MAX_COLUMN_NAME_LENGTH 20
#define MAX_COLUMN_DATA_LENGTH 50

typedef struct {
    char column_name[MAX_COLUMN_NAME_LENGTH];
    char column_data[MAX_COLUMN_DATA_LENGTH];
} record_t;

typedef struct {
    record_t *records;
    int num_records;
    int num_columns;
} database_t;

void create_database(database_t *db) {
    db->records = (record_t *)malloc(MAX_RECORDS * sizeof(record_t));
    db->num_records = 0;
    db->num_columns = 0;
}

void add_column(database_t *db, char *column_name) {
    if (db->num_columns >= MAX_COLUMNS) {
        printf("Error: maximum number of columns reached.\n");
        return;
    }
    strcpy(db->records[0].column_name, column_name);
    db->num_columns++;
}

void add_record(database_t *db, char *column_data) {
    if (db->num_records >= MAX_RECORDS) {
        printf("Error: maximum number of records reached.\n");
        return;
    }
    strcpy(db->records[db->num_records].column_data, column_data);
    db->num_records++;
}

void print_database(database_t *db) {
    printf("Database:\n");
    printf("---------------------\n");
    for (int i = 0; i < db->num_columns; i++) {
        printf("%-20s", db->records[0].column_name);
    }
    printf("\n");
    for (int i = 0; i < db->num_records; i++) {
        for (int j = 0; j < db->num_columns; j++) {
            printf("%-20s", db->records[i].column_data);
        }
        printf("\n");
    }
}

int main() {
    database_t db;
    create_database(&db);
    add_column(&db, "ID");
    add_column(&db, "Name");
    add_column(&db, "Age");
    add_record(&db, "1");
    add_record(&db, "John");
    add_record(&db, "25");
    print_database(&db);
    return 0;
}