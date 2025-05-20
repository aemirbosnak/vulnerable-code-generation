//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 100
#define MAX_ROWS 1000
#define MAX_LINE_LENGTH 1024

typedef struct {
    char **data;
    int rows;
    int columns;
} CSVData;

CSVData* createCSVData(int rows, int columns) {
    CSVData* csvData = (CSVData*)malloc(sizeof(CSVData));
    csvData->data = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        csvData->data[i] = (char*)malloc(MAX_COLUMNS * sizeof(char));
    }
    csvData->rows = rows;
    csvData->columns = columns;
    return csvData;
}

void freeCSVData(CSVData* csvData) {
    for (int i = 0; i < csvData->rows; i++) {
        free(csvData->data[i]);
    }
    free(csvData->data);
    free(csvData);
}

int splitLine(char* line, char* delimiter, char* result[]) {
    int count = 0;
    char* token = strtok(line, delimiter);
    
    while (token != NULL) {
        result[count++] = token;
        token = strtok(NULL, delimiter);
    }
    return count;
}

int readCSV(const char* filename, CSVData* csvData) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int rowIndex = 0;
    while (fgets(line, sizeof(line), file) && rowIndex < csvData->rows) {
        char* columns[MAX_COLUMNS];
        int columnCount = splitLine(line, ",", columns);
        for (int i = 0; i < columnCount && i < csvData->columns; i++) {
            csvData->data[rowIndex][i] = strdup(columns[i]);
        }
        rowIndex++;
    }

    fclose(file);
    csvData->rows = rowIndex;
    return 0;
}

void printCSV(CSVData* csvData) {
    for (int i = 0; i < csvData->rows; i++) {
        for (int j = 0; j < csvData->columns; j++) {
            if (csvData->data[i][j] != NULL) {
                printf("%s", csvData->data[i][j]);
                if (j < csvData->columns - 1) {
                    printf(", ");
                }
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename.csv>\n", argv[0]);
        return 1;
    }

    CSVData* csvData = createCSVData(MAX_ROWS, MAX_COLUMNS);

    if (readCSV(argv[1], csvData) == -1) {
        freeCSVData(csvData);
        return 1;
    }

    printCSV(csvData);
    
    freeCSVData(csvData);
    return 0;
}