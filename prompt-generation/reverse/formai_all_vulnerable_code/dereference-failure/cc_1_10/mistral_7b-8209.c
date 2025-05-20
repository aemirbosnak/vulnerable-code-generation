//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    size_t rows;
    size_t cols;
    char **data;
} CSVData;

void destroyCSVData(CSVData *csvData) {
    for (size_t i = 0; i < csvData->rows; i++) {
        free(csvData->data[i]);
    }
    free(csvData->data);
    free(csvData);
}

CSVData *readCSVFile(const char *filename, size_t rows, size_t cols) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    CSVData *csvData = malloc(sizeof(CSVData));
    csvData->rows = rows;
    csvData->cols = cols;
    csvData->data = malloc(sizeof(char *) * rows);

    size_t rowIndex = 0;
    while (rowIndex < rows && getline(&(csvData->data[rowIndex]), cols * sizeof(char), file) != -1) {
        char *token = strtok(csvData->data[rowIndex], ",");
        size_t colIndex = 0;
        csvData->data[rowIndex] = realloc(csvData->data[rowIndex], (cols + 1) * sizeof(char));

        while (token != NULL && colIndex < cols) {
            csvData->data[rowIndex][colIndex] = *token;
            csvData->data[rowIndex][colIndex++] = ',';
            token = strtok(NULL, ",");
        }
        csvData->data[rowIndex][cols] = '\0'; // null terminate the row
        rowIndex++;
    }

    if (ferror(file)) {
        perror("Error reading file");
        destroyCSVData(csvData);
        return NULL;
    }

    fclose(file);

    return csvData;
}

int main() {
    const char *filename = "example.csv";
    size_t rows = 3;
    size_t cols = 4;

    CSVData *csvData = readCSVFile(filename, rows, cols);

    if (csvData == NULL) {
        printf("Error reading CSV file\n");
        return 1;
    }

    for (size_t i = 0; i < csvData->rows; i++) {
        for (size_t j = 0; j < csvData->cols; j++) {
            printf("%c ", csvData->data[i][j]);
        }
        printf("\n");
    }

    destroyCSVData(csvData);

    return 0;
}