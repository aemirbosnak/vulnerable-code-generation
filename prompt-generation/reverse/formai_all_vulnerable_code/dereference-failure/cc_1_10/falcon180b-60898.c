//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_DATA_LEN 100

typedef struct {
    char data[MAX_DATA_LEN];
    int len;
} Data;

typedef struct {
    Data *data;
    int num_cols;
} Row;

typedef struct {
    Row **rows;
    int num_rows;
    int num_cols;
} Table;

Table *table_create(int num_cols) {
    Table *table = malloc(sizeof(Table));
    table->num_cols = num_cols;
    table->num_rows = 0;
    table->rows = malloc(MAX_ROWS * sizeof(Row*));
    return table;
}

void table_destroy(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            free(table->rows[i]->data[j].data);
        }
        free(table->rows[i]->data);
        free(table->rows[i]);
    }
    free(table->rows);
    free(table);
}

void table_add_row(Table *table) {
    table->rows[table->num_rows] = malloc(sizeof(Row));
    table->rows[table->num_rows]->data = malloc(table->num_cols * sizeof(Data));
    for (int i = 0; i < table->num_cols; i++) {
        table->rows[table->num_rows]->data[i].len = 0;
        table->rows[table->num_rows]->data[i].data[0] = '\0';
    }
    table->num_rows++;
}

void table_add_data(Table *table, int row, int col, char *data) {
    if (col >= table->num_cols) {
        printf("Error: Column out of range\n");
        return;
    }
    Data *cell = &table->rows[row]->data[col];
    if (cell->len >= MAX_DATA_LEN - 1) {
        printf("Error: Data too long\n");
        return;
    }
    strncat(cell->data, data, MAX_DATA_LEN - cell->len - 1);
    cell->len += strlen(data);
}

void table_print(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->rows[i]->data[j].data);
        }
        printf("\n");
    }
}

int main() {
    Table *table = table_create(3);
    table_add_row(table);
    table_add_data(table, 0, 0, "Name");
    table_add_data(table, 0, 1, "Age");
    table_add_data(table, 0, 2, "Gender");
    table_add_row(table);
    table_add_data(table, 1, 0, "John");
    table_add_data(table, 1, 1, "25");
    table_add_data(table, 1, 2, "Male");
    table_print(table);
    table_destroy(table);
    return 0;
}