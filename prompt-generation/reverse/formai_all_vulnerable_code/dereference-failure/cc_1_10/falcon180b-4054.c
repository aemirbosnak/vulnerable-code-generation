//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_SIZE 1000

// Define the structure for each cell
typedef struct {
    char data[MAX_DATA_SIZE];
    int row;
    int col;
} Cell;

// Define the structure for the table
typedef struct {
    int numRows;
    int numCols;
    Cell **data;
} Table;

// Function to initialize a new table
Table *newTable(int numRows, int numCols) {
    Table *table = (Table *) malloc(sizeof(Table));
    table->numRows = numRows;
    table->numCols = numCols;
    table->data = (Cell **) malloc(sizeof(Cell *) * numRows);
    for (int i = 0; i < numRows; i++) {
        table->data[i] = (Cell *) malloc(sizeof(Cell) * numCols);
    }
    return table;
}

// Function to insert data into a cell
void insertData(Table *table, int row, int col, char *data) {
    strcpy(table->data[row][col].data, data);
}

// Function to print the table
void printTable(Table *table) {
    for (int i = 0; i < table->numRows; i++) {
        for (int j = 0; j < table->numCols; j++) {
            printf("%s\t", table->data[i][j].data);
        }
        printf("\n");
    }
}

// Function to search for a value in the table
int searchTable(Table *table, char *value) {
    int found = 0;
    for (int i = 0; i < table->numRows; i++) {
        for (int j = 0; j < table->numCols; j++) {
            if (strcmp(table->data[i][j].data, value) == 0) {
                found = 1;
                printf("Value found in cell (%d, %d)\n", i, j);
            }
        }
    }
    return found;
}

int main() {
    Table *table = newTable(5, 5);
    insertData(table, 0, 0, "John");
    insertData(table, 0, 1, "Doe");
    insertData(table, 1, 0, "Jane");
    insertData(table, 1, 1, "Doe");
    insertData(table, 2, 0, "Bob");
    insertData(table, 2, 1, "Smith");
    insertData(table, 3, 0, "Alice");
    insertData(table, 3, 1, "Johnson");
    insertData(table, 4, 0, "Charlie");
    insertData(table, 4, 1, "Brown");
    printTable(table);
    int found = searchTable(table, "Doe");
    printf("Value found: %d\n", found);
    return 0;
}