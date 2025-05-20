//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Database;

void create_database(Database *db) {
    db->num_rows = 0;
    db->num_cols = 0;
    db->data = NULL;
}

void destroy_database(Database *db) {
    int i;
    for (i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
    db->num_rows = 0;
    db->num_cols = 0;
}

void add_row(Database *db, char *row_data) {
    db->num_rows++;
    db->data = realloc(db->data, sizeof(char *) * db->num_rows);
    db->data[db->num_rows - 1] = row_data;
}

void add_column(Database *db, char *col_data) {
    int i;
    for (i = 0; i < db->num_rows; i++) {
        db->data[i] = realloc(db->data[i], sizeof(char) * (db->num_cols + 1));
        strcat(db->data[i], col_data);
        db->num_cols++;
    }
}

void print_database(Database *db) {
    int i, j;
    for (i = 0; i < db->num_rows; i++) {
        for (j = 0; j < db->num_cols; j++) {
            printf("%c", db->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Database db;
    create_database(&db);

    add_row(&db, "Name");
    add_column(&db, "John");
    add_column(&db, "Doe");

    add_row(&db, "Age");
    add_column(&db, "25");

    add_row(&db, "Gender");
    add_column(&db, "Male");

    print_database(&db);

    destroy_database(&db);

    return 0;
}