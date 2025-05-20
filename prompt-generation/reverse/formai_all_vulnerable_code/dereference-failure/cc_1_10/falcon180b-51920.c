//Falcon-180B DATASET v1.0 Category: Database querying ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

struct cell {
    int row;
    int col;
    char value[MAX_COLS];
};

struct table {
    int num_rows;
    int num_cols;
    struct cell *data;
};

void create_table(struct table *table, int num_rows, int num_cols) {
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (struct cell *)malloc(num_rows * sizeof(struct cell));
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            table->data[i].row = i;
            table->data[i].col = j;
            table->data[i].value[j] = '\0';
        }
    }
}

void insert_value(struct table *table, int row, int col, char *value) {
    struct cell *cell = &table->data[row];
    strcpy(cell->value[col], value);
}

void print_table(struct table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i].value[j]);
        }
        printf("\n");
    }
}

int main() {
    struct table table;
    create_table(&table, 3, 3);
    insert_value(&table, 0, 0, "Name");
    insert_value(&table, 0, 1, "Age");
    insert_value(&table, 0, 2, "Gender");
    insert_value(&table, 1, 0, "John");
    insert_value(&table, 1, 1, "25");
    insert_value(&table, 1, 2, "Male");
    insert_value(&table, 2, 0, "Jane");
    insert_value(&table, 2, 1, "30");
    insert_value(&table, 2, 2, "Female");
    print_table(&table);
    return 0;
}