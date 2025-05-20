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

CSVReader *csvReader_create() {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = NULL;
    reader->rows = 0;
    reader->cols = 0;
    return reader;
}

void csvReader_destroy(CSVReader *reader) {
    free(reader->data);
    free(reader);
}

void csvReader_readCSV(CSVReader *reader, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return;
    }

    // Calculate number of rows and columns
    reader->rows = 0;
    char line[MAX_COLS];
    while (fgets(line, MAX_COLS, fp) != NULL) {
        reader->rows++;
    }

    // Allocate memory for data
    reader->data = malloc(sizeof(char *) * reader->rows);
    for (int i = 0; i < reader->rows; i++) {
        reader->data[i] = malloc(sizeof(char) * MAX_COLS);
    }

    // Read data from file
    rewind(fp);
    int col = 0;
    while (fgets(line, MAX_COLS, fp) != NULL) {
        char *token = strtok(line, ",");
        while (token) {
            strcpy(reader->data[reader->rows - 1][col++], token);
            token = strtok(NULL, ",");
        }
        col = 0;
        reader->rows++;
    }

    fclose(fp);
}

int main() {
    CSVReader *reader = csvReader_create();
    csvReader_readCSV(reader, "data.csv");

    // Print data
    for (int i = 0; i < reader->rows; i++) {
        for (int j = 0; j < reader->cols; j++) {
            printf("%s ", reader->data[i][j]);
        }
        printf("\n");
    }

    csvReader_destroy(reader);

    return 0;
}