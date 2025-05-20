//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    int num_cols;
    int num_rows;
    char **data;
} table_t;

void init_table(table_t *table, char *name, int num_cols, int num_rows) {
    table->name = name;
    table->num_cols = num_cols;
    table->num_rows = num_rows;
    table->data = (char **)malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *)malloc(num_cols * MAX_DATA_SIZE);
    }
}

void free_table(table_t *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table->name);
}

void print_table(table_t *table) {
    printf("Table: %s\n", table->name);
    printf("Number of columns: %d\n", table->num_cols);
    printf("Number of rows: %d\n", table->num_rows);
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            if (table->data[i][j]!= NULL) {
                printf("%s ", table->data[i][j]);
            } else {
                printf("NULL ");
            }
        }
        printf("\n");
    }
}

void add_row(table_t *table, int row_num, char *data) {
    for (int i = 0; i < table->num_cols; i++) {
        table->data[row_num][i] = data;
    }
}

void add_col(table_t *table, int col_num, char *data) {
    for (int i = 0; i < table->num_rows; i++) {
        table->data[i][col_num] = data;
    }
}

int main() {
    table_t table;
    init_table(&table, "example_table", 3, 4);
    add_row(&table, 0, "1 2 3");
    add_row(&table, 1, "4 5 6");
    add_row(&table, 2, "7 8 9");
    add_col(&table, 2, "X");
    print_table(&table);
    free_table(&table);
    return 0;
}