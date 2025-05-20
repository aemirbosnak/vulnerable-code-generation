//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ROWS 1000
#define MAX_COLS 20

typedef struct CSV_Reader {
    char **data;
    int numRows;
    int numCols;
} CSV_Reader;

CSV_Reader *csv_reader_init() {
    CSV_Reader *reader = malloc(sizeof(CSV_Reader));
    reader->data = NULL;
    reader->numRows = 0;
    reader->numCols = 0;
    return reader;
}

void csv_reader_free(CSV_Reader *reader) {
    free(reader->data);
    free(reader);
}

void csv_reader_read(CSV_Reader *reader, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Calculate number of rows and columns
    int numRows = 0;
    char line[MAX_COLS];
    while (fgets(line, MAX_COLS, file) != NULL) {
        numRows++;
    }
    reader->numRows = numRows;

    // Allocate memory for data
    reader->data = malloc(sizeof(char *) * numRows);
    for (int i = 0; i < numRows; i++) {
        reader->data[i] = malloc(sizeof(char) * MAX_COLS);
    }

    // Read data from file
    rewind(file);
    int numCols = 0;
    while (fgets(line, MAX_COLS, file) != NULL) {
        char *columns = strtok(line, ",");
        while (columns) {
            strcpy(reader->data[numRows - 1][numCols], columns);
            numCols++;
            columns = strtok(NULL, ",");
        }
        numCols = 0;
    }

    fclose(file);
}

int main() {
    CSV_Reader *reader = csv_reader_init();
    csv_reader_read(reader, "data.csv");

    // Print data
    for (int i = 0; i < reader->numRows; i++) {
        for (int j = 0; j < reader->numCols; j++) {
            printf("%s ", reader->data[i][j]);
        }
        printf("\n");
    }

    csv_reader_free(reader);
    return 0;
}