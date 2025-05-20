//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_SIZE 500

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Database;

Database *create_database() {
    Database *db = (Database *)malloc(sizeof(Database));
    db->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    db->num_rows = 0;
    db->num_cols = 0;
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

void add_row(Database *db, char *row_data) {
    db->data[db->num_rows] = (char *)malloc(strlen(row_data) + 1);
    strcpy(db->data[db->num_rows], row_data);
    db->num_rows++;
}

void add_col(Database *db, char *col_data) {
    db->num_cols++;
}

int get_num_rows(Database *db) {
    return db->num_rows;
}

int get_num_cols(Database *db) {
    return db->num_cols;
}

char **get_data(Database *db) {
    return db->data;
}

int main() {
    Database *db = create_database();
    add_row(db, "John Smith");
    add_row(db, "Jane Doe");
    add_col(db, "Age");
    add_col(db, "Gender");
    int num_rows = get_num_rows(db);
    int num_cols = get_num_cols(db);
    char **data = get_data(db);
    for (int i = 0; i < num_rows; i++) {
        printf("Row %d: %s\n", i, data[i]);
    }
    destroy_database(db);
    return 0;
}