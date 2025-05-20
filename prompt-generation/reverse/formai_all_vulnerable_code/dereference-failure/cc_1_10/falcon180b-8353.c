//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    int data_size;
    char *data;
} row_t;

typedef struct {
    row_t *rows;
    int num_rows;
    int num_cols;
} table_t;

void init_table(table_t *table) {
    table->rows = (row_t *)malloc(MAX_ROWS * sizeof(row_t));
    table->num_rows = 0;
    table->num_cols = 0;
}

void add_row(table_t *table, char *name, int data_size, char *data) {
    row_t *row = &table->rows[table->num_rows];
    row->name = strdup(name);
    row->data_size = data_size;
    row->data = (char *)malloc(data_size * sizeof(char));
    memcpy(row->data, data, data_size);
    table->num_rows++;
}

void print_table(table_t *table) {
    for (int i = 0; i < table->num_rows; i++) {
        printf("%s:\t%s\n", table->rows[i].name, table->rows[i].data);
    }
}

void free_table(table_t *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->rows[i].name);
        free(table->rows[i].data);
    }
    free(table->rows);
}

int main() {
    table_t table;
    init_table(&table);

    add_row(&table, "Name", 10, "John Doe");
    add_row(&table, "Age", 3, "25");
    add_row(&table, "City", 7, "New York");

    print_table(&table);

    free_table(&table);

    return 0;
}