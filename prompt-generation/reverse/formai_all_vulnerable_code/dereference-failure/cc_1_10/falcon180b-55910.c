//Falcon-180B DATASET v1.0 Category: Database querying ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_LEN 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->data = (char **)malloc(num_rows * sizeof(char *));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *)malloc(num_cols * MAX_LEN);
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

int add_row(Table *table, int row_num, char *row_data) {
    if (row_num >= table->num_rows) {
        return -1;
    }
    for (int i = 0; i < table->num_cols; i++) {
        if (row_data[i] == '\0') {
            break;
        }
        table->data[row_num][i] = row_data[i];
    }
    return 0;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%c", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table(2, 3);
    add_row(table, 0, "John");
    add_row(table, 1, "Doe");
    add_row(table, 2, "Jane");
    add_row(table, 3, "Doe");
    print_table(table);
    destroy_table(table);
    return 0;
}