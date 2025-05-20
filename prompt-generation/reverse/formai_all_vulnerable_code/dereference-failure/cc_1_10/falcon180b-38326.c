//Falcon-180B DATASET v1.0 Category: Database querying ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

Table *create_table() {
    Table *table = (Table *)malloc(sizeof(Table));
    table->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    table->num_rows = 0;
    table->num_cols = 0;
    return table;
}

void add_row(Table *table, char *row) {
    table->data[table->num_rows] = row;
    table->num_rows++;
}

void add_col(Table *table, char *col) {
    int i;
    for (i = 0; i < table->num_rows; i++) {
        table->data[i] = (char *)realloc(table->data[i], strlen(table->data[i]) + strlen(col) + 1);
        strcat(table->data[i], col);
    }
    table->num_cols++;
}

void print_table(Table *table) {
    int i, j;
    for (i = 0; i < table->num_rows; i++) {
        for (j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table();
    char *row1 = "Name Age Gender";
    char *row2 = "John 25 Male";
    char *row3 = "Jane 30 Female";
    add_row(table, row1);
    add_row(table, row2);
    add_row(table, row3);
    char *col1 = "Name";
    char *col2 = "Age";
    char *col3 = "Gender";
    add_col(table, col1);
    add_col(table, col2);
    add_col(table, col3);
    print_table(table);
    return 0;
}