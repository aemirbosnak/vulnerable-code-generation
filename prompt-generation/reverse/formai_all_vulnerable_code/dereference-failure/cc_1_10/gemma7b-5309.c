//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct {
    char **data;
    int rows;
    int cols;
} CSVReader;

CSVReader *createCSVReader(int rows, int cols) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->rows = rows;
    reader->cols = cols;
    reader->data = malloc(rows * cols * sizeof(char *));
    for (int r = 0; r < reader->rows; r++) {
        reader->data[r] = malloc(cols * sizeof(char *));
        for (int c = 0; c < reader->cols; c++) {
            reader->data[r][c] = NULL;
        }
    }
    return reader;
}

void freeCSVReader(CSVReader *reader) {
    for (int r = 0; r < reader->rows; r++) {
        free(reader->data[r]);
    }
    free(reader->data);
    free(reader);
}

int main() {
    CSVReader *reader = createCSVReader(5, 3);
    reader->data[0][0] = "King";
    reader->data[0][1] = "Arthur";
    reader->data[0][2] = "The Great";
    reader->data[1][0] = "Queen";
    reader->data[1][1] = "Morgana";
    reader->data[1][2] = "The Wicked";
    reader->data[2][0] = "Prince";
    reader->data[2][1] = "David";
    reader->data[2][2] = "The Brave";
    reader->data[3][0] = "Wizard";
    reader->data[3][1] = "Merlin";
    reader->data[3][2] = "The Wise";
    reader->data[4][0] = "Dragon";
    reader->data[4][1] = "Blaze";
    reader->data[4][2] = "The Fierce";

    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            printf("%s ", reader->data[r][c]);
        }
        printf("\n");
    }

    freeCSVReader(reader);

    return 0;
}