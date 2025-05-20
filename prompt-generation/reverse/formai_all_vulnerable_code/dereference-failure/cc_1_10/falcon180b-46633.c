//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_LEN 1000

typedef struct {
    char data[MAX_DATA_LEN];
    int row;
    int col;
} cell_t;

typedef struct {
    int num_rows;
    int num_cols;
    cell_t **data;
} table_t;

table_t *create_table(int num_rows, int num_cols) {
    table_t *table = (table_t *)malloc(sizeof(table_t));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (cell_t **)malloc(num_rows * sizeof(cell_t *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (cell_t *)malloc(num_cols * sizeof(cell_t));
        for (int j = 0; j < num_cols; j++) {
            table->data[i][j].row = i;
            table->data[i][j].col = j;
        }
    }
    return table;
}

void destroy_table(table_t *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void set_cell_value(table_t *table, int row, int col, char *value) {
    if (row >= 0 && row < table->num_rows && col >= 0 && col < table->num_cols) {
        strcpy(table->data[row][col].data, value);
    }
}

char *get_cell_value(table_t *table, int row, int col) {
    if (row >= 0 && row < table->num_rows && col >= 0 && col < table->num_cols) {
        return table->data[row][col].data;
    }
    return NULL;
}

int main() {
    table_t *table = create_table(10, 10);

    set_cell_value(table, 0, 0, "Hello");
    set_cell_value(table, 0, 1, "World");

    char *value1 = get_cell_value(table, 0, 0);
    char *value2 = get_cell_value(table, 0, 1);

    printf("Cell (0, 0): %s\n", value1);
    printf("Cell (0, 1): %s\n", value2);

    destroy_table(table);

    return 0;
}