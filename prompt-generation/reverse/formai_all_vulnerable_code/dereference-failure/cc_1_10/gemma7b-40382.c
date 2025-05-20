//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CSVReader {
    char **data;
    int rows;
    int cols;
} CSVReader;

CSVReader* csv_reader_init(int rows, int cols) {
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->data = malloc(rows * sizeof(char*));
    for (int r = 0; r < rows; r++) {
        reader->data[r] = malloc(cols * sizeof(char));
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csv_reader_append(CSVReader* reader, char** values) {
    reader->data[reader->rows++] = values;
}

void csv_reader_free(CSVReader* reader) {
    for (int r = 0; r < reader->rows; r++) {
        free(reader->data[r]);
    }
    free(reader->data);
    free(reader);
}

int main() {
    CSVReader* reader = csv_reader_init(5, 3);
    char** values = malloc(5 * sizeof(char*));
    values[0] = "John Doe";
    values[1] = "New York";
    values[2] = "USA";
    values[3] = "20";
    values[4] = "Software Engineer";
    csv_reader_append(reader, values);

    values = malloc(5 * sizeof(char*));
    values[0] = "Jane Doe";
    values[1] = "Los Angeles";
    values[2] = "USA";
    values[3] = "25";
    values[4] = "Doctor";
    csv_reader_append(reader, values);

    csv_reader_free(reader);
    return 0;
}