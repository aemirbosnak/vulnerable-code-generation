//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_FIELD_SIZE 100

typedef struct {
    char *name;
    int num_rows;
    int num_columns;
    char **data;
} Table;

void create_table(Table *table, char *name, int num_rows, int num_columns) {
    table->name = name;
    table->num_rows = num_rows;
    table->num_columns = num_columns;
    table->data = (char **)malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *)malloc(num_columns * MAX_FIELD_SIZE);
        memset(table->data[i], 0, num_columns * MAX_FIELD_SIZE);
    }
}

void insert_row(Table *table, int row, char *row_data) {
    int num_columns = strlen(row_data) / MAX_FIELD_SIZE;
    for (int i = 0; i < num_columns; i++) {
        strncpy(table->data[row][i * MAX_FIELD_SIZE], row_data + i * MAX_FIELD_SIZE, MAX_FIELD_SIZE);
    }
}

void print_table(Table *table) {
    printf("Table: %s\n", table->name);
    printf("Rows: %d\n", table->num_rows);
    printf("Columns: %d\n", table->num_columns);
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_columns; j++) {
            printf("%s ", table->data[i][j]);
        }
        printf("\n");
    }
}

void delete_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table->name);
    free(table);
}

int main() {
    Table my_table;
    create_table(&my_table, "My Table", 2, 3);
    insert_row(&my_table, 0, "John Doe");
    insert_row(&my_table, 1, "Jane Smith");
    print_table(&my_table);
    delete_table(&my_table);
    return 0;
}