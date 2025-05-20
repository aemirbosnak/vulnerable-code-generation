//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
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

CSVReader* csv_reader_init(int rows, int cols) {
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->data = malloc(sizeof(char *) * rows);
    for (int r = 0; r < rows; r++) {
        reader->data[r] = malloc(sizeof(char) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csv_reader_free(CSVReader* reader) {
    for (int r = 0; r < reader->rows; r++) {
        free(reader->data[r]);
    }
    free(reader->data);
    free(reader);
}

int csv_reader_read(CSVReader* reader, char** data, int row, int col) {
    if (row < 0 || row >= reader->rows || col < 0 || col >= reader->cols) {
        return -1;
    }
    data[row][col] = reader->data[row][col];
    return 0;
}

int main() {
    CSVReader* reader = csv_reader_init(5, 3);
    reader->data[0][0] = 'a';
    reader->data[0][1] = 'b';
    reader->data[0][2] = 'c';
    reader->data[1][0] = 'd';
    reader->data[1][1] = 'e';
    reader->data[1][2] = 'f';

    char** data = malloc(sizeof(char *) * reader->rows);
    for (int r = 0; r < reader->rows; r++) {
        data[r] = malloc(sizeof(char) * reader->cols);
    }

    csv_reader_read(reader, data, 0, 1);
    printf("%s\n", data[0][1]);

    csv_reader_free(reader);
    free(data);

    return 0;
}