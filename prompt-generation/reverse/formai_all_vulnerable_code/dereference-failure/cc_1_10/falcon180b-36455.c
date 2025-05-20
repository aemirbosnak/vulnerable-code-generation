//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_LENGTH 100

typedef struct {
    char data[MAX_DATA_LENGTH];
    int row;
    int col;
} Cell;

typedef struct {
    Cell **data;
    int numRows;
    int numCols;
} Spreadsheet;

Spreadsheet *createSpreadsheet(int numRows, int numCols) {
    Spreadsheet *spreadsheet = (Spreadsheet *) malloc(sizeof(Spreadsheet));
    spreadsheet->numRows = numRows;
    spreadsheet->numCols = numCols;
    spreadsheet->data = (Cell **) malloc(numRows * sizeof(Cell *));
    for (int i = 0; i < numRows; i++) {
        spreadsheet->data[i] = (Cell *) malloc(numCols * sizeof(Cell));
        for (int j = 0; j < numCols; j++) {
            spreadsheet->data[i][j].row = i;
            spreadsheet->data[i][j].col = j;
        }
    }
    return spreadsheet;
}

void destroySpreadsheet(Spreadsheet *spreadsheet) {
    for (int i = 0; i < spreadsheet->numRows; i++) {
        free(spreadsheet->data[i]);
    }
    free(spreadsheet->data);
    free(spreadsheet);
}

void setCellValue(Spreadsheet *spreadsheet, int row, int col, char *value) {
    Cell *cell = &spreadsheet->data[row][col];
    strncpy(cell->data, value, MAX_DATA_LENGTH);
}

char *getCellValue(Spreadsheet *spreadsheet, int row, int col) {
    Cell *cell = &spreadsheet->data[row][col];
    return cell->data;
}

void printSpreadsheet(Spreadsheet *spreadsheet) {
    for (int i = 0; i < spreadsheet->numRows; i++) {
        for (int j = 0; j < spreadsheet->numCols; j++) {
            printf("%s ", getCellValue(spreadsheet, i, j));
        }
        printf("\n");
    }
}

int main() {
    Spreadsheet *spreadsheet = createSpreadsheet(10, 10);
    setCellValue(spreadsheet, 0, 0, "Hello");
    setCellValue(spreadsheet, 1, 1, "World");
    printSpreadsheet(spreadsheet);
    destroySpreadsheet(spreadsheet);
    return 0;
}