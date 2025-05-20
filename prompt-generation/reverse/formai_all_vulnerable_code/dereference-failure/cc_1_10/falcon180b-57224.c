//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Ada Lovelace
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
    db->data = malloc(MAX_ROWS * MAX_COLS * MAX_DATA_SIZE);
    db->rows = 0;
    db->cols = 0;
}

void add_row(Database *db, int num_cols, char *row_data) {
    db->rows++;
    db->cols = num_cols;
    int offset = db->rows - 1;
    for (int i = 0; i < num_cols; i++) {
        int col_offset = i * MAX_DATA_SIZE;
        strcpy(db->data + offset * MAX_ROWS + col_offset, row_data + i * MAX_DATA_SIZE);
    }
}

void print_database(Database *db) {
    int num_rows = db->rows;
    int num_cols = db->cols;
    int row_offset = 0;
    for (int i = 0; i < num_rows; i++) {
        int col_offset = 0;
        for (int j = 0; j < num_cols; j++) {
            printf("%s ", db->data + row_offset * MAX_ROWS + col_offset);
            col_offset += MAX_DATA_SIZE;
        }
        printf("\n");
        row_offset += MAX_ROWS;
    }
}

int main() {
    Database db;
    init_database(&db);
    add_row(&db, 3, "Alice Bob Charlie");
    add_row(&db, 2, "Eve Frank");
    print_database(&db);
    return 0;
}