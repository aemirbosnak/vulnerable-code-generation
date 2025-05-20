//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: invasive
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
    CSV_Reader *reader = (CSV_Reader *)malloc(sizeof(CSV_Reader));
    reader->data = (char **)malloc(sizeof(char *) * rows);
    for (int r = 0; r < rows; r++) {
        reader->data[r] = (char *)malloc(sizeof(char) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csv_reader_read(CSV_Reader *reader, char *line) {
    int i = 0;
    char *token = strtok(line, ",");
    while (token) {
        reader->data[reader->rows][i++] = token;
        token = strtok(NULL, ",");
    }
    reader->rows++;
}

void csv_reader_print(CSV_Reader *reader) {
    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            printf("%s,", reader->data[r][c]);
        }
        printf("\n");
    }
}

int main() {
    CSV_Reader *reader = csv_reader_init(MAX_ROWS, MAX_COLS);
    csv_reader_read(reader, "John,Doe,123 Main St,New York,NY 10001");
    csv_reader_read(reader, "Jane,Doe,456 Oak Ave,Los Angeles,CA 90012");
    csv_reader_print(reader);

    free(reader->data);
    free(reader);

    return 0;
}