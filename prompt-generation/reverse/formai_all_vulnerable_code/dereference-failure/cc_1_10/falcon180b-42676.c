//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *data;
    int size;
} Data;

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = malloc(sizeof(char) * MAX_DATA_SIZE);
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void set_cell(Table *table, int row, int col, char *data) {
    strcpy(table->data[row], data);
}

char *get_cell(Table *table, int row, int col) {
    return table->data[row];
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table(3, 3);
    set_cell(table, 0, 0, "Name");
    set_cell(table, 0, 1, "Age");
    set_cell(table, 0, 2, "Gender");
    set_cell(table, 1, 0, "John");
    set_cell(table, 1, 1, "25");
    set_cell(table, 1, 2, "Male");
    set_cell(table, 2, 0, "Jane");
    set_cell(table, 2, 1, "30");
    set_cell(table, 2, 2, "Female");
    print_table(table);
    destroy_table(table);
    return 0;
}