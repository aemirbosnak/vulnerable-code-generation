//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: happy
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

void csv_reader_set_value(CSVReader* reader, int row, int col, char* value) {
    reader->data[row][col] = strdup(value);
}

char** csv_reader_get_data(CSVReader* reader) {
    return reader->data;
}

int main() {
    CSVReader* reader = csv_reader_init(5, 3);
    csv_reader_set_value(reader, 0, 0, "John Doe");
    csv_reader_set_value(reader, 1, 1, "Jane Doe");
    csv_reader_set_value(reader, 2, 2, "Peter Pan");

    char** data = csv_reader_get_data(reader);
    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            printf("%s ", data[r][c]);
        }
        printf("\n");
    }

    free(reader->data);
    free(reader);

    return 0;
}