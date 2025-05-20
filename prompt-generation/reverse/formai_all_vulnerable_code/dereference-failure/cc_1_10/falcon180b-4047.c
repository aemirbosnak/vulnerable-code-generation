//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_ROWS_PER_BLOCK 10
#define MAX_COLS_PER_BLOCK 10

typedef struct {
    int rows;
    int cols;
    char data[MAX_ROWS][MAX_COLS];
} Table;

typedef struct {
    int rows;
    int cols;
    Table *table;
} Block;

Table *createTable(int rows, int cols) {
    Table *table = malloc(sizeof(Table));
    table->rows = rows;
    table->cols = cols;
    return table;
}

Block *createBlock(int rows, int cols) {
    Block *block = malloc(sizeof(Block));
    block->rows = rows;
    block->cols = cols;
    block->table = createTable(rows, cols);
    return block;
}

void insertRow(Table *table, int row, char *data) {
    int i;
    for (i = 0; i < table->cols; i++) {
        strcpy(table->data[row][i], data + i * MAX_COLS_PER_BLOCK);
    }
}

void insertBlock(Block *block, int row, int col, char *data) {
    int i, j;
    for (i = 0; i < block->rows; i++) {
        for (j = 0; j < block->cols; j++) {
            insertRow(block->table, i * MAX_ROWS_PER_BLOCK + row, data + j * MAX_COLS_PER_BLOCK);
        }
    }
}

void printTable(Table *table) {
    int i, j;
    for (i = 0; i < table->rows; i++) {
        for (j = 0; j < table->cols; j++) {
            printf("%s ", table->data[i][j]);
        }
        printf("\n");
    }
}

void printBlock(Block *block, int row, int col) {
    int i, j;
    for (i = 0; i < block->rows; i++) {
        for (j = 0; j < block->cols; j++) {
            printf("%s ", block->table->data[i * MAX_ROWS_PER_BLOCK + row][j * MAX_COLS_PER_BLOCK]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = createTable(MAX_ROWS, MAX_COLS);
    Block *block = createBlock(MAX_ROWS_PER_BLOCK, MAX_COLS_PER_BLOCK);

    char data[MAX_ROWS_PER_BLOCK][MAX_COLS_PER_BLOCK] = {
        "Name", "Age", "Gender", "City",
        "John", "25", "Male", "New York",
        "Jane", "30", "Female", "Los Angeles",
        "Bob", "20", "Male", "Chicago"
    };

    insertBlock(block, 0, 0, data);

    printTable(table);
    printBlock(block, 0, 0);

    return 0;
}