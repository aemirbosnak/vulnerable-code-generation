//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000

typedef struct CSVReader {
    char **data;
    int rows;
    int cols;
} CSVReader;

CSVReader *csv_reader_init(int rows, int cols) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++) {
        reader->data[i] = malloc(sizeof(char) * cols);
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
    reader->data[0][0] = 'a';
    reader->data[0][1] = 'b';
    reader->data[0][2] = 'c';
    reader->data[0][3] = 'd';
    reader->data[0][4] = 'e';

    printf("%c, %c, %c, %c, %c\n", csv_reader_get_data(reader)[0][0], csv_reader_get_data(reader)[0][1], csv_reader_get_data(reader)[0][2], csv_reader_get_data(reader)[0][3], csv_reader_get_data(reader)[0][4]);

    csv_reader_free(reader);

    return 0;
}