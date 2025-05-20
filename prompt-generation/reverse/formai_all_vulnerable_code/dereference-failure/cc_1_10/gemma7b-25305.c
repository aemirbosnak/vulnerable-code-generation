//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: real-life
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
    for (int i = 0; i < rows; i++) {
        reader->data[i] = malloc(sizeof(char) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csv_reader_add_row(CSV_Reader *reader, char **row) {
    reader->data[reader->rows++] = row;
}

void csv_reader_free(CSV_Reader *reader) {
    for (int i = 0; i < reader->rows; i++) {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int main() {
    CSV_Reader *reader = csv_reader_init(5, 3);
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

    for (int i = 0; i < reader->rows; i++) {
        for (int j = 0; j < reader->cols; j++) {
            printf("%s ", reader->data[i][j]);
        }
        printf("\n");
    }

    csv_reader_free(reader);

    return 0;
}