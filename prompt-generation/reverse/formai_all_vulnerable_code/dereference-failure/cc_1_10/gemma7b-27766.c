//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSVReader {
    char ***data;
    int rows;
    int cols;
} CSVReader;

CSVReader *csv_reader_init(int rows, int cols) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->rows = rows;
    reader->cols = cols;
    reader->data = malloc(sizeof(char ***) * rows);
    for (int r = 0; r < rows; r++) {
        reader->data[r] = malloc(sizeof(char **) * cols);
        for (int c = 0; c < cols; c++) {
            reader->data[r][c] = NULL;
        }
    }
    return reader;
}

void csv_reader_add_data(CSVReader *reader, char **data, int row, int col) {
    reader->data[row][col] = strdup(data[0]);
}

void csv_reader_print(CSVReader *reader) {
    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            printf("%s ", reader->data[r][c]);
        }
        printf("\n");
    }
}

int main() {
    CSVReader *reader = csv_reader_init(5, 3);
    char **data = malloc(sizeof(char *) * 5);
    data[0] = "John Doe";
    data[1] = "Jane Doe";
    data[2] = "Peter Pan";
    data[3] = "Mary Poppins";
    data[4] = "The Wizard of Oz";

    csv_reader_add_data(reader, data, 0, 1);
    csv_reader_add_data(reader, data, 1, 1);
    csv_reader_add_data(reader, data, 2, 1);
    csv_reader_add_data(reader, data, 3, 1);
    csv_reader_add_data(reader, data, 4, 1);

    csv_reader_print(reader);

    free(reader);
    free(data);

    return 0;
}