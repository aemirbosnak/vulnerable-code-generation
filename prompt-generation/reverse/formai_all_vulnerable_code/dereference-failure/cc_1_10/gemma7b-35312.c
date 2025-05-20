//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 20

typedef struct CSVReader {
    char **data;
    int rows;
    int cols;
} CSVReader;

CSVReader *csv_reader_init(int rows, int cols) {
    CSVReader *reader = (CSVReader *)malloc(sizeof(CSVReader));
    reader->data = (char **)malloc(rows * sizeof(char *));
    reader->rows = rows;
    reader->cols = cols;

    for (int r = 0; r < rows; r++) {
        reader->data[r] = (char *)malloc(cols * sizeof(char));
    }

    return reader;
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

    // Read data from CSV file
    reader->data[0][0] = 'a';
    reader->data[0][1] = 'b';
    reader->data[0][2] = 'c';
    reader->data[1][0] = 'd';
    reader->data[1][1] = 'e';
    reader->data[1][2] = 'f';

    // Print data
    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            printf("%c ", reader->data[r][c]);
        }
        printf("\n");
    }

    csv_reader_free(reader);

    return 0;
}