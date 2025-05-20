//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_VAL_LEN 100

typedef struct {
    char **values;
    int num_cols;
} Row;

typedef struct {
    Row **rows;
    int num_rows;
} Table;

void create_table(Table *table) {
    table->rows = malloc(MAX_ROWS * sizeof(Row *));
    table->num_rows = 0;
}

void add_row(Table *table, char **values, int num_cols) {
    Row *row = malloc(sizeof(Row));
    row->values = malloc(num_cols * sizeof(char *));
    row->num_cols = num_cols;

    for (int i = 0; i < num_cols; i++) {
        row->values[i] = malloc(MAX_VAL_LEN * sizeof(char));
        strcpy(row->values[i], values[i]);
    }

    table->rows[table->num_rows++] = row;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        Row *row = table->rows[i];
        for (int j = 0; j < row->num_cols; j++) {
            printf("%s ", row->values[j]);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    create_table(&table);

    add_row(&table, (char *[]) {"John", "Doe", "25"}, 3);
    add_row(&table, (char *[]) {"Jane", "Doe", "30"}, 3);
    add_row(&table, (char *[]) {"Bob", "Smith", "40"}, 3);

    print_table(&table);

    return 0;
}