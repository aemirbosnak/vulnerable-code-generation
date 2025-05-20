//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 20

typedef struct CSV_Reader {
    char **data;
    int rows;
    int cols;
} CSV_Reader;

CSV_Reader *csv_reader_init(int rows, int cols) {
    CSV_Reader *reader = malloc(sizeof(CSV_Reader));
    reader->data = malloc(sizeof(char *) * rows);
    for (int r = 0; r < rows; r++) {
        reader->data[r] = malloc(sizeof(char *) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csv_reader_free(CSV_Reader *reader) {
    for (int r = 0; r < reader->rows; r++) {
        free(reader->data[r]);
    }
    free(reader->data);
    free(reader);
}

int csv_reader_get_num_rows(CSV_Reader *reader) {
    return reader->rows;
}

int csv_reader_get_num_cols(CSV_Reader *reader) {
    return reader->cols;
}

char **csv_reader_get_data(CSV_Reader *reader) {
    return reader->data;
}

int main() {
    CSV_Reader *reader = csv_reader_init(5, 3);

    reader->data[0][0] = "John Doe";
    reader->data[0][1] = "New York";
    reader->data[0][2] = 30;

    reader->data[1][0] = "Jane Doe";
    reader->data[1][1] = "Los Angeles";
    reader->data[1][2] = 25;

    reader->data[2][0] = "Peter Pan";
    reader->data[2][1] = "Neverland";
    reader->data[2][2] = 12;

    for (int r = 0; r < csv_reader_get_num_rows(reader); r++) {
        for (int c = 0; c < csv_reader_get_num_cols(reader); c++) {
            printf("%s, ", csv_reader_get_data(reader)[r][c]);
        }
        printf("\n");
    }

    csv_reader_free(reader);

    return 0;
}