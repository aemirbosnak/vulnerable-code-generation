//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
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
    for (int i = 0; i < rows; i++) {
        reader->data[i] = malloc(sizeof(char *) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csv_reader_free(CSVReader *reader) {
    for (int i = 0; i < reader->rows; i++) {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int csv_reader_get_num_rows(CSVReader *reader) {
    return reader->rows;
}

int csv_reader_get_num_cols(CSVReader *reader) {
    return reader->cols;
}

char **csv_reader_get_data(CSVReader *reader) {
    return reader->data;
}

int main() {
    CSVReader *reader = csv_reader_init(10, 5);
    reader->data[0][0] = "John Doe";
    reader->data[0][1] = "New York";
    reader->data[0][2] = "123 Main St";
    reader->data[0][3] = "12345";

    for (int i = 0; i < csv_reader_get_num_rows(reader); i++) {
        for (int j = 0; j < csv_reader_get_num_cols(reader); j++) {
            printf("%s ", csv_reader_get_data(reader)[i][j]);
        }
        printf("\n");
    }

    csv_reader_free(reader);

    return 0;
}