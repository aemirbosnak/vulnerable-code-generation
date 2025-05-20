//Falcon-180B DATASET v1.0 Category: Database querying ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_SIZE 1000

typedef struct {
    char *data;
    int size;
} String;

typedef struct {
    String **data;
    int rows, cols;
} Table;

void init_table(Table *table, int rows, int cols) {
    table->rows = rows;
    table->cols = cols;
    table->data = (String **)malloc(rows * sizeof(String *));
    for (int i = 0; i < rows; i++) {
        table->data[i] = (String *)malloc(cols * sizeof(String));
        for (int j = 0; j < cols; j++) {
            table->data[i][j].data = NULL;
            table->data[i][j].size = 0;
        }
    }
}

void free_table(Table *table) {
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            if (table->data[i][j].data) {
                free(table->data[i][j].data);
            }
        }
        free(table->data[i]);
    }
    free(table->data);
}

void print_table(Table *table) {
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            printf("%s ", table->data[i][j].data);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    init_table(&table, 2, 3);

    table.data[0][0].data = "Name";
    table.data[0][0].size = strlen("Name");
    table.data[0][1].data = "Age";
    table.data[0][1].size = strlen("Age");
    table.data[0][2].data = "Gender";
    table.data[0][2].size = strlen("Gender");

    table.data[1][0].data = "John";
    table.data[1][0].size = strlen("John");
    table.data[1][1].data = "25";
    table.data[1][1].size = strlen("25");
    table.data[1][2].data = "Male";
    table.data[1][2].size = strlen("Male");

    print_table(&table);

    free_table(&table);

    return 0;
}