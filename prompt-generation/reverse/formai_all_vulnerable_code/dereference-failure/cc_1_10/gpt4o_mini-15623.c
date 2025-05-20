//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

typedef struct {
    char **data;
    int numRows;
    int numCols;
} CSVData;

CSVData* createCSVData(int rows, int cols) {
    CSVData *csv = (CSVData *)malloc(sizeof(CSVData));
    csv->data = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        csv->data[i] = (char *)malloc(cols * sizeof(char) * 100); // Assume max column length of 100
    }
    csv->numRows = rows;
    csv->numCols = cols;
    return csv;
}

void freeCSVData(CSVData *csv) {
    if (csv) {
        for (int i = 0; i < csv->numRows; i++) {
            free(csv->data[i]);
        }
        free(csv->data);
        free(csv);
    }
}

void parseCSVLine(char *line, char **columns, int *numCols) {
    char *token;
    *numCols = 0;
    
    token = strtok(line, ",");
    while (token != NULL) {
        columns[(*numCols)++] = strdup(token);
        token = strtok(NULL, ",");
    }
}

void readCSV(const char *filename, CSVData *csv) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int row = 0;

    while (fgets(line, sizeof(line), file) && row < csv->numRows) {
        parseCSVLine(line, csv->data[row], &csv->numCols);
        row++;
    }
    
    fclose(file);
}

void printCSV(CSVData *csv) {
    for (int i = 0; i < csv->numRows; i++) {
        for (int j = 0; j < csv->numCols; j++) {
            if (j > 0) printf(", ");
            printf("%s", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    const char *filename = "data.csv";
    int maxRows = 100;
    int maxCols = MAX_COLUMNS;

    CSVData *csv = createCSVData(maxRows, maxCols);
    readCSV(filename, csv);
    
    printf("Data from '%s':\n", filename);
    printCSV(csv);
    
    freeCSVData(csv);
    return 0;
}