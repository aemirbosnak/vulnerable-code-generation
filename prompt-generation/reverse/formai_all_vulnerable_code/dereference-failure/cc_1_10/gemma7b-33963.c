//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: automated
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

CSVReader* csv_reader_init(int rows, int cols) {
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->data = malloc(sizeof(char ***) * rows);
    for (int r = 0; r < rows; r++) {
        reader->data[r] = malloc(sizeof(char**) * cols);
        for (int c = 0; c < cols; c++) {
            reader->data[r][c] = NULL;
        }
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csv_reader_set_data(CSVReader* reader, char* data, int row, int col) {
    reader->data[row][col] = strdup(data);
}

void csv_reader_print(CSVReader* reader) {
    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            printf("%s ", reader->data[r][c]);
        }
        printf("\n");
    }
}

int main() {
    CSVReader* reader = csv_reader_init(5, 3);
    csv_reader_set_data(reader, "John Doe", 0, 0);
    csv_reader_set_data(reader, "Jane Doe", 1, 0);
    csv_reader_set_data(reader, "Peter Pan", 2, 0);
    csv_reader_print(reader);

    free(reader->data);
    free(reader);

    return 0;
}