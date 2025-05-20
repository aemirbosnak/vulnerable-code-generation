//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 20
#define MAX_ROW_LENGTH 100

typedef struct {
    char *row_data[MAX_COLS];
    int row_length;
} Row;

typedef struct {
    Row *rows;
    int num_rows;
    int num_cols;
} Database;

Database *create_database() {
    Database *db = (Database *)malloc(sizeof(Database));
    db->num_rows = 0;
    db->num_cols = 0;
    db->rows = (Row *)malloc(MAX_ROWS * sizeof(Row));
    return db;
}

void add_row(Database *db, char *col1, char *col2, char *col3) {
    Row *row = &db->rows[db->num_rows];
    row->row_data[0] = strdup(col1);
    row->row_data[1] = strdup(col2);
    row->row_data[2] = strdup(col3);
    row->row_length = 3;
    db->num_rows++;
    db->num_cols = 3;
}

void print_row(Row *row) {
    for (int i = 0; i < row->row_length; i++) {
        printf("%s\t", row->row_data[i]);
    }
    printf("\n");
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        print_row(&db->rows[i]);
    }
}

int main() {
    Database *db = create_database();
    add_row(db, "John", "Doe", "25");
    add_row(db, "Jane", "Doe", "30");
    add_row(db, "Bob", "Smith", "40");
    print_database(db);
    return 0;
}