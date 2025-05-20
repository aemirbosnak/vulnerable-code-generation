//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: grateful
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

void csv_reader_read(CSVReader *reader, char **line) {
    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            reader->data[r][c] = line[c];
        }
    }
}

void csv_reader_free(CSVReader *reader) {
    for (int r = 0; r < reader->rows; r++) {
        free(reader->data[r]);
    }
    free(reader->data);
    free(reader);
}

int main() {
    CSVReader *reader = csv_reader_init(5, 3);
    char **line = malloc(sizeof(char *) * 10);
    line[0] = 'a';
    line[1] = 'b';
    line[2] = 'c';
    line[3] = '\n';
    line[4] = '\0';
    csv_reader_read(reader, line);
    csv_reader_free(reader);
    return 0;
}