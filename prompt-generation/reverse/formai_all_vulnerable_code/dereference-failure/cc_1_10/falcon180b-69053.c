//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 100

typedef struct {
    char *data;
    int size;
} Data;

typedef struct {
    char *name;
    int num_rows;
    int num_cols;
    Data **data;
} Table;

void init_table(Table *table, char *name) {
    table->name = name;
    table->num_rows = 0;
    table->num_cols = 0;
    table->data = NULL;
}

void add_row(Table *table) {
    table->num_rows++;
    table->data = realloc(table->data, sizeof(Data *) * table->num_rows);
    table->data[table->num_rows - 1] = NULL;
}

void add_col(Table *table) {
    table->num_cols++;
    for (int i = 0; i < table->num_rows; i++) {
        table->data[i] = realloc(table->data[i], sizeof(Data) * table->num_cols);
    }
}

void set_cell(Table *table, int row, int col, char *data, int size) {
    if (row >= table->num_rows || col >= table->num_cols) {
        printf("Error: Cell out of bounds\n");
        return;
    }
    table->data[row][col].data = malloc(size + 1);
    strncpy(table->data[row][col].data, data, size);
    table->data[row][col].size = size;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i][j].data);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    init_table(&table, "my_table");
    add_row(&table);
    add_col(&table);
    set_cell(&table, 0, 0, "Hello", 6);
    set_cell(&table, 0, 1, "World", 6);
    print_table(&table);
    return 0;
}