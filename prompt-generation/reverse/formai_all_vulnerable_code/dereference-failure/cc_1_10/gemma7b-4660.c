//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1024
#define MAX_COLS 256

typedef struct Cell {
    char value[MAX_COLS];
    struct Cell* next;
} Cell;

typedef struct Sheet {
    Cell** data;
    int rows;
    int cols;
} Sheet;

Sheet* createSheet(int rows, int cols) {
    Sheet* sheet = malloc(sizeof(Sheet));
    sheet->data = malloc(sizeof(Cell*) * rows);
    for (int r = 0; r < rows; r++) {
        sheet->data[r] = malloc(sizeof(Cell) * cols);
    }
    sheet->rows = rows;
    sheet->cols = cols;
    return sheet;
}

void readCSV(Sheet* sheet, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return;
    }

    char line[MAX_ROWS][MAX_COLS];
    int row = 0;
    while (fgets(line[row], MAX_COLS, file) != NULL) {
        row++;
        int col = 0;
        for (char* p = line[row - 1]; *p != '\0'; p++) {
            if (*p != ',') {
                sheet->data[row - 1][col++].value[*p - 'a'] = 1;
            } else {
                col++;
            }
        }
    }

    fclose(file);
}

int main() {
    Sheet* sheet = createSheet(10, 5);
    readCSV(sheet, "data.csv");

    for (int r = 0; r < sheet->rows; r++) {
        for (int c = 0; c < sheet->cols; c++) {
            printf("%c ", sheet->data[r][c].value[0] + 'a');
        }
        printf("\n");
    }

    return 0;
}