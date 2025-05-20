//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
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

void csv_reader_read(CSV_Reader *reader, char *csv_data) {
    char *line = strtok(csv_data, "\n");
    int row = 0;
    while (line) {
        char *column = strtok(line, ",");
        int col = 0;
        while (column) {
            reader->data[row][col++] = column;
            column = strtok(NULL, ",");
        }
        reader->data[row++] = NULL;
        line = strtok(NULL, "\n");
    }
}

void csv_reader_free(CSV_Reader *reader) {
    for (int i = 0; i < reader->rows; i++) {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int main() {
    CSV_Reader *reader = csv_reader_init(MAX_ROWS, MAX_COLS);
    csv_reader_read(reader, "a,b,c\nd,e,f\ng,h,i");
    for (int i = 0; i < reader->rows; i++) {
        for (int j = 0; j < reader->cols; j++) {
            printf("%s ", reader->data[i][j]);
        }
        printf("\n");
    }
    csv_reader_free(reader);
    return 0;
}