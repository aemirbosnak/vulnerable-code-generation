//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct Cell {
    char data[MAX_COLS];
    struct Cell* next;
} Cell;

typedef struct CSVReader {
    Cell** rows;
    int numRows;
    int numCols;
} CSVReader;

CSVReader* csvReader_init(int numRows, int numCols) {
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->rows = malloc(sizeof(Cell*) * numRows);
    reader->numRows = numRows;
    reader->numCols = numCols;

    for (int r = 0; r < numRows; r++) {
        reader->rows[r] = NULL;
    }

    return reader;
}

void csvReader_add_row(CSVReader* reader, char** data) {
    Cell* newCell = malloc(sizeof(Cell));
    newCell->next = reader->rows[reader->numRows - 1];
    reader->rows[reader->numRows - 1] = newCell;

    for (int c = 0; c < reader->numCols; c++) {
        newCell->data[c] = data[c];
    }

    reader->numRows++;
}

void csvReader_free(CSVReader* reader) {
    for (int r = 0; r < reader->numRows; r++) {
        Cell* cell = reader->rows[r];
        while (cell) {
            Cell* nextCell = cell->next;
            free(cell);
            cell = nextCell;
        }
    }

    free(reader->rows);
    free(reader);
}

int main() {
    CSVReader* reader = csvReader_init(5, 3);

    char** data = malloc(sizeof(char*) * 5);
    data[0] = "Alice";
    data[1] = "Bob";
    data[2] = "Charlie";
    data[3] = "Dave";
    data[4] = "Eve";

    csvReader_add_row(reader, data);

    data = malloc(sizeof(char*) * 3);
    data[0] = "Fred";
    data[1] = "George";
    data[2] = "Harry";

    csvReader_add_row(reader, data);

    for (int r = 0; r < reader->numRows; r++) {
        for (int c = 0; c < reader->numCols; c++) {
            printf("%s ", reader->rows[r]->data[c]);
        }

        printf("\n");
    }

    csvReader_free(reader);

    return 0;
}