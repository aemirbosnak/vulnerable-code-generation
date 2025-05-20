//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_DATA_SIZE 100

typedef struct {
    char name[MAX_DATA_SIZE];
    int age;
    float salary;
} Record;

typedef struct {
    int num_rows;
    int num_columns;
    Record **data;
} Database;

void create_database(Database *db) {
    db->num_rows = 0;
    db->num_columns = 0;
    db->data = NULL;
}

void destroy_database(Database *db) {
    if (db->data!= NULL) {
        for (int i = 0; i < db->num_rows; i++) {
            free(db->data[i]);
        }
        free(db->data);
    }
}

void add_column(Database *db, char *name) {
    db->num_columns++;
    db->data = (Record **)realloc(db->data, sizeof(Record *) * db->num_columns);
    db->data[db->num_columns - 1] = NULL;
}

void add_row(Database *db) {
    db->num_rows++;
    db->data = (Record **)realloc(db->data, sizeof(Record *) * db->num_rows);
    db->data[db->num_rows - 1] = NULL;
}

void set_cell(Database *db, int row, int column, char *value) {
    if (row >= 0 && row < db->num_rows && column >= 0 && column < db->num_columns) {
        db->data[row][column] = (Record){.name = strdup(value),.age = 0,.salary = 0};
    }
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_columns; j++) {
            printf("%s\t", db->data[i][j].name);
        }
        printf("\n");
    }
}

int main() {
    Database db;
    create_database(&db);
    add_column(&db, "Name");
    add_column(&db, "Age");
    add_column(&db, "Salary");
    add_row(&db);
    set_cell(&db, 0, 0, "Alice");
    set_cell(&db, 0, 1, "30");
    set_cell(&db, 0, 2, "50000");
    print_database(&db);
    destroy_database(&db);
    return 0;
}