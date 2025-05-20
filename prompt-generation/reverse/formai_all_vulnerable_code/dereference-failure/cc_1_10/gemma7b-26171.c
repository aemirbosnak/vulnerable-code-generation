//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSVReader {
    char **data;
    int rows;
    int cols;
} CSVReader;

CSVReader *csvReader_init(int rows, int cols) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = malloc(sizeof(char *) * rows);
    for (int r = 0; r < rows; r++) {
        reader->data[r] = malloc(sizeof(char *) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csvReader_free(CSVReader *reader) {
    for (int r = 0; r < reader->rows; r++) {
        free(reader->data[r]);
    }
    free(reader->data);
    free(reader);
}

int csvReader_get_value(CSVReader *reader, int row, int col) {
    return atoi(reader->data[row][col]);
}

int main() {
    CSVReader *reader = csvReader_init(5, 3);

    reader->data[0][0] = "John Doe";
    reader->data[0][1] = 25;
    reader->data[0][2] = "New York";

    reader->data[1][0] = "Jane Doe";
    reader->data[1][1] = 30;
    reader->data[1][2] = "Los Angeles";

    reader->data[2][0] = "Peter Pan";
    reader->data[2][1] = 20;
    reader->data[2][2] = "Neverland";

    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            printf("%s, %d, %s\n", reader->data[r][c], csvReader_get_value(reader, r, c), reader->data[r][c]);
        }
    }

    csvReader_free(reader);

    return 0;
}