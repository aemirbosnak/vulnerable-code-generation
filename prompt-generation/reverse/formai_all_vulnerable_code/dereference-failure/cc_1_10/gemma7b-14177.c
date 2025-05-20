//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
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

void csv_reader_read(CSV_Reader *reader, char **buffer) {
    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            buffer[r][c] = reader->data[r][c];
        }
    }
}

int main() {
    CSV_Reader *reader = csv_reader_init(5, 3);

    reader->data[0][0] = 'a';
    reader->data[0][1] = 'b';
    reader->data[0][2] = 'c';
    reader->data[1][0] = 'd';
    reader->data[1][1] = 'e';
    reader->data[1][2] = 'f';

    char **buffer = malloc(sizeof(char *) * reader->rows);
    for (int r = 0; r < reader->rows; r++) {
        buffer[r] = malloc(sizeof(char) * reader->cols);
    }

    csv_reader_read(reader, buffer);

    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            printf("%c ", buffer[r][c]);
        }
        printf("\n");
    }

    csv_reader_free(reader);

    return 0;
}