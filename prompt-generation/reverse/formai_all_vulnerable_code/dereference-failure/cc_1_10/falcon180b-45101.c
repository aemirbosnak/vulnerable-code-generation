//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 100

typedef struct {
    char *data;
    int rows;
    int cols;
} Data;

void createTable(Data *table, char *name, int rows, int cols) {
    table->data = malloc(rows * cols * sizeof(char));
    strcpy(table->data, name);
    table->rows = rows;
    table->cols = cols;
}

void insertRow(Data *table, int row, char *data) {
    int i;
    for (i = 0; i < strlen(data); i++) {
        table->data[row * MAX_DATA_SIZE + i] = data[i];
    }
}

void insertCol(Data *table, int col, char *data) {
    int i;
    for (i = 0; i < strlen(data); i++) {
        table->data[i * MAX_ROWS + col] = data[i];
    }
}

void printTable(Data *table) {
    int i, j;
    for (i = 0; i < table->rows; i++) {
        for (j = 0; j < table->cols; j++) {
            printf("%c", table->data[i * MAX_DATA_SIZE + j]);
        }
        printf("\n");
    }
}

int main() {
    Data table;
    createTable(&table, "Example Table", 5, 5);
    insertRow(&table, 0, "Row 1");
    insertRow(&table, 1, "Row 2");
    insertRow(&table, 2, "Row 3");
    insertRow(&table, 3, "Row 4");
    insertRow(&table, 4, "Row 5");
    insertCol(&table, 0, "Col 1");
    insertCol(&table, 1, "Col 2");
    insertCol(&table, 2, "Col 3");
    insertCol(&table, 3, "Col 4");
    insertCol(&table, 4, "Col 5");
    printTable(&table);
    return 0;
}