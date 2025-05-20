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

void init_table(Table *table) {
    table->data = NULL;
    table->num_rows = 0;
    table->num_cols = 0;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            free(table->data[i]);
        }
        free(table->data[i]);
    }
    free(table->data);
    table->num_rows = 0;
    table->num_cols = 0;
}

void add_row(Table *table, char **row) {
    if (table->num_rows == MAX_ROWS || table->num_cols == MAX_COLS) {
        printf("Error: Table is full.\n");
        return;
    }
    table->data = realloc(table->data, sizeof(char *) * (table->num_rows + 1));
    table->data[table->num_rows] = row;
    table->num_rows++;
    for (int i = 0; i < table->num_cols; i++) {
        if (row[i]!= NULL && strlen(row[i]) > table->num_cols) {
            table->num_cols = strlen(row[i]);
        }
    }
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    init_table(&table);

    char **row1 = malloc(sizeof(char *) * table.num_cols);
    row1[0] = "Name";
    row1[1] = "Age";
    add_row(&table, row1);

    char **row2 = malloc(sizeof(char *) * table.num_cols);
    row2[0] = "Alice";
    row2[1] = "25";
    add_row(&table, row2);

    char **row3 = malloc(sizeof(char *) * table.num_cols);
    row3[0] = "Bob";
    row3[1] = "30";
    add_row(&table, row3);

    print_table(&table);

    destroy_table(&table);

    return 0;
}