//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    int num_rows;
    int num_cols;
    char **data;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (char **)malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *)malloc(sizeof(char) * num_cols);
        memset(table->data[i], '\0', num_cols);
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

int get_num_rows(Table *table) {
    return table->num_rows;
}

int get_num_cols(Table *table) {
    return table->num_cols;
}

char *get_data(Table *table, int row, int col) {
    return table->data[row][col];
}

void set_data(Table *table, int row, int col, char *data) {
    strcpy(table->data[row][col], data);
}

int main() {
    Table *table = create_table(3, 3);
    set_data(table, 0, 0, "Name");
    set_data(table, 0, 1, "Age");
    set_data(table, 0, 2, "Gender");
    set_data(table, 1, 0, "John");
    set_data(table, 1, 1, "25");
    set_data(table, 1, 2, "Male");
    set_data(table, 2, 0, "Jane");
    set_data(table, 2, 1, "30");
    set_data(table, 2, 2, "Female");

    int num_rows = get_num_rows(table);
    int num_cols = get_num_cols(table);

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%s ", get_data(table, i, j));
        }
        printf("\n");
    }

    destroy_table(table);
    return 0;
}