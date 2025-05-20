//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define MAX_COLS 256

typedef struct CSVReader {
    char **data;
    int lines;
    int cols;
    FILE *fp;
} CSVReader;

CSVReader *csv_reader_init(char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = NULL;
    reader->lines = 0;
    reader->cols = 0;
    reader->fp = fopen(filename, "r");
    return reader;
}

void csv_reader_free(CSVReader *reader) {
    fclose(reader->fp);
    free(reader->data);
    free(reader);
}

int csv_reader_get_lines(CSVReader *reader) {
    return reader->lines;
}

int csv_reader_get_cols(CSVReader *reader) {
    return reader->cols;
}

char **csv_reader_get_data(CSVReader *reader) {
    return reader->data;
}

char *csv_reader_get_value(CSVReader *reader, int line, int col) {
    return reader->data[line][col];
}

int main() {
    CSVReader *reader = csv_reader_init("example.csv");

    int lines = csv_reader_get_lines(reader);
    int cols = csv_reader_get_cols(reader);

    char **data = csv_reader_get_data(reader);

    for (int l = 0; l < lines; l++) {
        for (int c = 0; c < cols; c++) {
            printf("%s,", csv_reader_get_value(reader, l, c));
        }
        printf("\n");
    }

    csv_reader_free(reader);

    return 0;
}