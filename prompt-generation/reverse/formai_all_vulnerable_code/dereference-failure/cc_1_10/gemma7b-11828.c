//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
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

CSVReader *createCSVReader(int rows, int cols) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++) {
        reader->data[i] = malloc(sizeof(char *) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void readCSV(CSVReader *reader, char **line) {
    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            reader->data[r][c] = line[c];
        }
    }
}

void freeCSVReader(CSVReader *reader) {
    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            free(reader->data[r][c]);
        }
        free(reader->data[r]);
    }
    free(reader->data);
    free(reader);
}

int main() {
    CSVReader *reader = createCSVReader(5, 3);
    char **line = malloc(sizeof(char *) * 10);
    line[0] = 'a';
    line[1] = 'b';
    line[2] = 'c';
    line[3] = '\n';
    readCSV(reader, line);
    freeCSVReader(reader);
    free(line);
    return 0;
}