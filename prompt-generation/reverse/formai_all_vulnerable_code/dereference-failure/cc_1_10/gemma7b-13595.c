//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: careful
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

CSVReader *csv_reader_init(int rows, int cols) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = malloc(sizeof(char *) * rows);
    for (int r = 0; r < rows; r++) {
        reader->data[r] = malloc(sizeof(char) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csv_reader_free(CSVReader *reader) {
    for (int r = 0; r < reader->rows; r++) {
        free(reader->data[r]);
    }
    free(reader->data);
    free(reader);
}

int csv_reader_read(CSVReader *reader, char **line) {
    int cols = reader->cols;
    *line = malloc(sizeof(char) * (cols + 1));
    for (int c = 0; c < cols; c++) {
        (*line)[c] = reader->data[reader->rows - 1][c];
    }
    ((*line)[cols] = '\0');
    return reader->rows++;
}

int main() {
    CSVReader *reader = csv_reader_init(MAX_ROWS, MAX_COLS);

    // Fill the CSV reader with data
    reader->data[0][0] = 'a';
    reader->data[0][1] = 'b';
    reader->data[1][0] = 'c';
    reader->data[1][1] = 'd';

    // Read lines from the CSV reader
    char *line;
    int line_num = csv_reader_read(reader, &line);
    printf("%s\n", line);

    line_num = csv_reader_read(reader, &line);
    printf("%s\n", line);

    csv_reader_free(reader);

    return 0;
}