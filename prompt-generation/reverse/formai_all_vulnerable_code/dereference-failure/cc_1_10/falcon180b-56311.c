//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_LEN 100

typedef struct {
    char **data;
    int rows;
    int cols;
} Table;

void create_table(Table *table) {
    table->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    table->rows = 0;
    table->cols = 0;
}

void destroy_table(Table *table) {
    int i;
    for (i = 0; i < table->rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
}

void add_row(Table *table, char *data) {
    int len = strlen(data);
    if (len > MAX_LEN) {
        printf("Error: Row length exceeds maximum limit.\n");
        return;
    }
    if (table->rows >= MAX_ROWS) {
        printf("Error: Maximum number of rows reached.\n");
        return;
    }
    table->data[table->rows] = (char *)malloc(len + 1);
    strcpy(table->data[table->rows], data);
    table->rows++;
    if (table->cols == 0) {
        table->cols = strlen(table->data[0]);
    } else if (len!= table->cols) {
        printf("Error: Columns do not match.\n");
    }
}

void print_table(Table *table) {
    int i, j;
    for (i = 0; i < table->rows; i++) {
        for (j = 0; j < table->cols; j++) {
            printf("%c", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    create_table(&table);
    add_row(&table, "Name");
    add_row(&table, "Age");
    add_row(&table, "Gender");
    add_row(&table, "John");
    add_row(&table, "25");
    add_row(&table, "Male");
    print_table(&table);
    destroy_table(&table);
    return 0;
}