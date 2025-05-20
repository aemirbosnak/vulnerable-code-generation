//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100
#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} data_t;

typedef struct {
    data_t **data;
    int rows;
    int cols;
} database_t;

void init_database(database_t *db) {
    db->data = (data_t **)malloc(MAX_ROWS * sizeof(data_t *));
    db->rows = 0;
    db->cols = 0;
}

void free_database(database_t *db) {
    int i, j;
    for (i = 0; i < db->rows; i++) {
        for (j = 0; j < db->cols; j++) {
            free(db->data[i][j].name);
            free(db->data[i][j].value);
        }
        free(db->data[i]);
    }
    free(db->data);
}

void add_column(database_t *db) {
    db->cols++;
    db->data[db->rows] = (data_t *)realloc(db->data[db->rows], db->cols * sizeof(data_t));
}

void add_row(database_t *db) {
    db->rows++;
    db->data = (data_t **)realloc(db->data, db->rows * sizeof(data_t *));
    db->data[db->rows - 1] = (data_t *)malloc(db->cols * sizeof(data_t));
}

void print_database(database_t *db) {
    int i, j;
    for (i = 0; i < db->rows; i++) {
        for (j = 0; j < db->cols; j++) {
            printf("%s\t%s\n", db->data[i][j].name, db->data[i][j].value);
        }
    }
}

int main() {
    database_t db;
    init_database(&db);
    add_column(&db);
    add_row(&db);
    strcpy(db.data[0][0].name, "Name");
    strcpy(db.data[0][0].value, "John");
    strcpy(db.data[0][1].name, "Age");
    strcpy(db.data[0][1].value, "25");
    print_database(&db);
    free_database(&db);
    return 0;
}