//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
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

void csv_reader_add_row(CSVReader *reader, char **row) {
    reader->data[reader->rows++] = row;
}

void csv_reader_print(CSVReader *reader) {
    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            printf("%s, ", reader->data[r][c]);
        }
        printf("\n");
    }
}

int main() {
    CSVReader *reader = csv_reader_init(5, 3);
    char **row1 = malloc(sizeof(char *) * 3);
    row1[0] = "John Doe";
    row1[1] = "New York";
    row1[2] = "USA";
    csv_reader_add_row(reader, row1);

    char **row2 = malloc(sizeof(char *) * 3);
    row2[0] = "Jane Doe";
    row2[1] = "Los Angeles";
    row2[2] = "USA";
    csv_reader_add_row(reader, row2);

    csv_reader_print(reader);

    free(reader->data);
    free(reader);
    return 0;
}