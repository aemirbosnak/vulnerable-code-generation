//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *data;
    int rows;
    int cols;
} Database;

void init_database(Database *db) {
    db->data = (char *)malloc(MAX_DATA_SIZE * sizeof(char));
    db->rows = 0;
    db->cols = 0;
}

void add_row(Database *db, char *row) {
    strcat(db->data, row);
    db->rows++;
}

void add_col(Database *db, char *col) {
    strcat(db->data, col);
    db->cols++;
}

void print_database(Database *db) {
    printf("Database:\n");
    printf("Rows: %d\n", db->rows);
    printf("Cols: %d\n", db->cols);
    printf("Data:\n%s\n", db->data);
}

int main() {
    Database db;
    init_database(&db);

    add_row(&db, "Name\tAge\tGender");
    add_col(&db, "John");
    add_col(&db, "25");
    add_col(&db, "Male");
    add_row(&db, "\tDoe");
    add_col(&db, "Jane");
    add_col(&db, "30");
    add_col(&db, "Female");

    print_database(&db);

    return 0;
}