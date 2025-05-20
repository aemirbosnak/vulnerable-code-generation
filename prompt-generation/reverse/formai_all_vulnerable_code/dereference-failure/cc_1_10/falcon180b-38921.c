//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_SIZE 10000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

Table *create_table() {
    Table *table = malloc(sizeof(Table));
    table->data = malloc(MAX_ROWS * MAX_COLS * sizeof(char*));
    table->num_rows = 0;
    table->num_cols = 0;
    return table;
}

void add_row(Table *table, char **row) {
    table->data[table->num_rows++] = row;
}

void add_col(Table *table, char *col) {
    int i;
    for (i = 0; i < table->num_rows; i++) {
        table->data[i] = realloc(table->data[i], (table->num_cols + 1) * sizeof(char*));
        table->data[i][table->num_cols++] = col;
    }
}

void print_table(Table *table) {
    int i, j;
    for (i = 0; i < table->num_rows; i++) {
        for (j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table();
    char *row1[] = {"1", "2", "3"};
    char *row2[] = {"4", "5", "6"};
    char *row3[] = {"7", "8", "9"};
    add_row(table, row1);
    add_row(table, row2);
    add_row(table, row3);
    add_col(table, "A");
    add_col(table, "B");
    add_col(table, "C");
    print_table(table);
    return 0;
}