//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 20

typedef struct {
    char *data;
    int rows;
    int cols;
} Table;

void createTable(Table *table, int rows, int cols) {
    table->data = malloc(rows * cols * sizeof(char));
    table->rows = rows;
    table->cols = cols;
    memset(table->data, '\0', rows * cols * sizeof(char));
}

void insertData(Table *table, int row, int col, char *data) {
    strncat(table->data + (row * table->cols + col), data, table->cols - col);
}

void printTable(Table *table) {
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            printf("%c", table->data[i * table->cols + j]);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    createTable(&table, 5, 10);
    insertData(&table, 0, 0, "Name");
    insertData(&table, 0, 1, "Age");
    insertData(&table, 0, 2, "Gender");
    insertData(&table, 1, 0, "John");
    insertData(&table, 1, 1, "25");
    insertData(&table, 1, 2, "Male");
    insertData(&table, 2, 0, "Jane");
    insertData(&table, 2, 1, "30");
    insertData(&table, 2, 2, "Female");
    insertData(&table, 3, 0, "Bob");
    insertData(&table, 3, 1, "20");
    insertData(&table, 3, 2, "Male");
    insertData(&table, 4, 0, "Alice");
    insertData(&table, 4, 1, "28");
    insertData(&table, 4, 2, "Female");
    printTable(&table);
    return 0;
}