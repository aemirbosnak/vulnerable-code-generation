//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: intelligent
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

CSVReader *csvReader_init(int rows, int cols) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++) {
        reader->data[i] = malloc(sizeof(char) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csvReader_free(CSVReader *reader) {
    for (int i = 0; i < reader->rows; i++) {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

void csvReader_read(CSVReader *reader, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return;
    }

    int i = 0;
    char line[MAX_ROWS];
    while (fgets(line, MAX_ROWS, fp) != NULL) {
        char **columns = malloc(sizeof(char *) * reader->cols);
        int j = 0;
        for (char *column = strtok(line, ","); column; column = strtok(NULL, ",")) {
            columns[j++] = strdup(column);
        }

        for (int k = 0; k < reader->cols; k++) {
            reader->data[i][k] = columns[k];
        }

        free(columns);
        i++;
    }

    fclose(fp);
}

int main() {
    CSVReader *reader = csvReader_init(10, 2);
    csvReader_read(reader, "data.csv");

    for (int i = 0; i < reader->rows; i++) {
        for (int j = 0; j < reader->cols; j++) {
            printf("%s ", reader->data[i][j]);
        }
        printf("\n");
    }

    csvReader_free(reader);

    return 0;
}