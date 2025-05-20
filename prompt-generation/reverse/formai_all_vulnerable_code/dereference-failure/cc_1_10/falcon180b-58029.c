//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *data;
    int size;
} Data;

typedef struct {
    char **data;
    int rows;
    int cols;
} Table;

void init_table(Table *table) {
    table->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    table->rows = 0;
    table->cols = 0;
}

void add_row(Table *table, char *data) {
    table->data[table->rows] = strdup(data);
    table->rows++;
}

void add_col(Table *table, char *data) {
    int i;
    table->cols++;
    for (i = 0; i < table->rows; i++) {
        table->data[i] = (char *)realloc(table->data[i], strlen(data) + 1);
        strcat(table->data[i], data);
    }
}

void print_table(Table *table) {
    int i, j;
    for (i = 0; i < table->rows; i++) {
        for (j = 0; j < table->cols; j++) {
            printf("%s ", table->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    init_table(&table);

    add_row(&table, "Name");
    add_row(&table, "Age");
    add_row(&table, "Occupation");

    add_col(&table, "Alice");
    add_col(&table, "25");
    add_col(&table, "Hacker");

    add_col(&table, "Bob");
    add_col(&table, "30");
    add_col(&table, "Cyberpunk");

    add_col(&table, "Charlie");
    add_col(&table, "35");
    add_col(&table, "Corpo");

    print_table(&table);

    return 0;
}