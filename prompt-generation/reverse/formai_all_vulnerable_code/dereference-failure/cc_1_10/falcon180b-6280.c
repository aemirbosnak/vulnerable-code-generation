//Falcon-180B DATASET v1.0 Category: Database querying ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_VAL_LEN 100

typedef struct {
    int num_rows;
    int num_cols;
    char **values;
} table_t;

table_t *create_table() {
    table_t *table = (table_t *)malloc(sizeof(table_t));
    table->num_rows = 0;
    table->num_cols = 0;
    table->values = NULL;
    return table;
}

void add_row(table_t *table, char *row) {
    int i = 0;
    char *token = strtok(row, ",");
    while (token!= NULL && i < MAX_COLS) {
        if (table->num_cols == 0) {
            table->num_cols = i;
        }
        table->values[table->num_rows][i] = strdup(token);
        i++;
        token = strtok(NULL, ",");
    }
    table->num_rows++;
}

void print_table(table_t *table) {
    int i, j;
    for (i = 0; i < table->num_rows; i++) {
        for (j = 0; j < table->num_cols; j++) {
            printf("%s ", table->values[i][j]);
        }
        printf("\n");
    }
}

void free_table(table_t *table) {
    int i, j;
    for (i = 0; i < table->num_rows; i++) {
        for (j = 0; j < table->num_cols; j++) {
            free(table->values[i][j]);
        }
        free(table->values[i]);
    }
    free(table->values);
    free(table);
}

int main() {
    table_t *table = create_table();
    char *row = "Name,Age,Gender";
    add_row(table, row);
    row = "John,25,Male";
    add_row(table, row);
    row = "Jane,30,Female";
    add_row(table, row);
    print_table(table);
    free_table(table);
    return 0;
}