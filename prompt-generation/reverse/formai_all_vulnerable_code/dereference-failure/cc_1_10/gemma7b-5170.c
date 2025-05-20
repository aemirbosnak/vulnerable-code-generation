//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Reader {
    char **data;
    int rows;
    int cols;
} CSV_Reader;

CSV_Reader *csv_reader_init() {
    CSV_Reader *reader = malloc(sizeof(CSV_Reader));
    reader->data = NULL;
    reader->rows = 0;
    reader->cols = 0;
    return reader;
}

void csv_reader_add_row(CSV_Reader *reader, char **row) {
    reader->data = realloc(reader->data, (reader->rows + 1) * sizeof(char **));
    reader->data[reader->rows] = row;
    reader->rows++;
}

void csv_reader_free(CSV_Reader *reader) {
    for (int r = 0; r < reader->rows; r++) {
        free(reader->data[r]);
    }
    free(reader->data);
    free(reader);
}

int main() {
    CSV_Reader *reader = csv_reader_init();

    char **row1 = malloc(MAX_COLS * sizeof(char *));
    row1[0] = "John Doe";
    row1[1] = "jane.doe@example.com";

    csv_reader_add_row(reader, row1);

    char **row2 = malloc(MAX_COLS * sizeof(char *));
    row2[0] = "Jane Doe";
    row2[1] = "janedoe@example.com";

    csv_reader_add_row(reader, row2);

    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            printf("%s ", reader->data[r][c]);
        }
        printf("\n");
    }

    csv_reader_free(reader);

    return 0;
}