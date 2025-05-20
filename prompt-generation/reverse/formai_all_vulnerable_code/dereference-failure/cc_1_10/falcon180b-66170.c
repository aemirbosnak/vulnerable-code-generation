//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_LEN 1000

typedef struct {
    char *data;
    int rows;
    int cols;
} Table;

void createTable(Table *table, int rows, int cols) {
    table->data = (char *)malloc(rows * cols * MAX_DATA_LEN);
    table->rows = rows;
    table->cols = cols;
}

void destroyTable(Table *table) {
    free(table->data);
}

void setData(Table *table, int row, int col, char *data) {
    int offset = row * table->cols + col;
    strcpy(table->data + offset * MAX_DATA_LEN, data);
}

char *getData(Table *table, int row, int col) {
    int offset = row * table->cols + col;
    return table->data + offset * MAX_DATA_LEN;
}

int main() {
    Table table;
    createTable(&table, 5, 3);

    setData(&table, 0, 0, "Name");
    setData(&table, 0, 1, "Age");
    setData(&table, 0, 2, "Gender");

    setData(&table, 1, 0, "John");
    setData(&table, 1, 1, "25");
    setData(&table, 1, 2, "Male");

    setData(&table, 2, 0, "Jane");
    setData(&table, 2, 1, "30");
    setData(&table, 2, 2, "Female");

    setData(&table, 3, 0, "Bob");
    setData(&table, 3, 1, "20");
    setData(&table, 3, 2, "Male");

    setData(&table, 4, 0, "Alice");
    setData(&table, 4, 1, "28");
    setData(&table, 4, 2, "Female");

    printf("Table data:\n");
    for (int i = 0; i < table.rows; i++) {
        for (int j = 0; j < table.cols; j++) {
            printf("%s ", getData(&table, i, j));
        }
        printf("\n");
    }

    destroyTable(&table);
    return 0;
}