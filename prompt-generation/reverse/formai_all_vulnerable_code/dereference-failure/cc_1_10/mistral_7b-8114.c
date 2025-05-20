//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CsvRow_tag {
    size_t numCols;
    size_t* colSizes;
    char** cols;
} CsvRow;

void destroyRow(CsvRow* row) {
    for (size_t i = 0; i < row->numCols; ++i)
        free(row->cols[i]);
    free(row->cols);
    free(row->colSizes);
    free(row);
}

CsvRow* parseCsvLine(FILE* file) {
    char* line = NULL;
    size_t len = 0;
    size_t size = 0;
    CsvRow* row = NULL;
    int numCols = 0;

    if (getline(&line, &len, file) == -1)
        return NULL;

    row = calloc(1, sizeof(CsvRow));
    row->cols = NULL;
    row->colSizes = NULL;

    char* token = strtok(line, ",");
    while (token != NULL) {
        if (row->cols == NULL) {
            size += strlen(token) + 1;
            row->colSizes = calloc(1, sizeof(size_t));
            row->cols = malloc(size);
            row->numCols = 1;
            strcpy(row->cols[0], token);
            row->colSizes[0] = strlen(token) + 1;
        } else {
            size += strlen(token) + 1;

            CsvRow* newRow = realloc(row, sizeof(CsvRow) + size);
            if (newRow == NULL) {
                destroyRow(row);
                free(line);
                return NULL;
            }

            row = newRow;
            row->cols[numCols] = malloc(strlen(token) + 1);
            strcpy(row->cols[numCols], token);
            row->colSizes[numCols] = strlen(token) + 1;
            ++numCols;
        }

        token = strtok(NULL, ",");
    }

    row->numCols = numCols;

    free(line);

    return row;
}

void printRow(CsvRow* row) {
    for (size_t i = 0; i < row->numCols; ++i)
        printf("%s", row->cols[i]);
    printf("\n");
}

int main() {
    FILE* file = fopen("example.csv", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    CsvRow* row = NULL;

    while ((row = parseCsvLine(file)) != NULL) {
        printRow(row);
        destroyRow(row);
    }

    fclose(file);

    return 0;
}