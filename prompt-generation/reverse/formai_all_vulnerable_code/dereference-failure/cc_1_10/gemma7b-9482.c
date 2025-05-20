//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Reader {
    char **data;
    int rows;
    int cols;
} CSV_Reader;

CSV_Reader *csv_reader_init(int rows, int cols) {
    CSV_Reader *reader = malloc(sizeof(CSV_Reader));
    reader->data = malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++) {
        reader->data[i] = malloc(sizeof(char) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csv_reader_free(CSV_Reader *reader) {
    for (int i = 0; i < reader->rows; i++) {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int csv_reader_get_value(CSV_Reader *reader, int row, int col) {
    return reader->data[row][col];
}

void csv_reader_set_value(CSV_Reader *reader, int row, int col, int value) {
    reader->data[row][col] = value;
}

int main() {
    CSV_Reader *reader = csv_reader_init(5, 3);
    csv_reader_set_value(reader, 2, 1, 10);
    csv_reader_set_value(reader, 3, 2, 20);

    printf("Value at (2, 1): %d\n", csv_reader_get_value(reader, 2, 1));
    printf("Value at (3, 2): %d\n", csv_reader_get_value(reader, 3, 2));

    csv_reader_free(reader);

    return 0;
}