//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSVReader {
    char ***data;
    int rows;
    int cols;
} CSVReader;

CSVReader *readCSVFile(char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));

    reader->data = NULL;
    reader->rows = 0;
    reader->cols = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char line[MAX_ROWS];
    char **row = NULL;
    int i = 0;

    while (fgets(line, MAX_ROWS, file) != NULL) {
        row = realloc(row, (reader->rows + 1) * sizeof(char *));
        reader->data = realloc(reader->data, (reader->rows + 1) * sizeof(char ***));
        reader->data[reader->rows] = row;
        reader->rows++;

        char *cell = strtok(line, ",");
        while (cell) {
            row[i++] = cell;
            cell = strtok(NULL, ",");
        }
        row[i] = NULL;
    }

    fclose(file);

    return reader;
}

int main() {
    CSVReader *reader = readCSVFile("data.csv");

    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            printf("%s ", reader->data[r][c]);
        }
        printf("\n");
    }

    free(reader);

    return 0;
}