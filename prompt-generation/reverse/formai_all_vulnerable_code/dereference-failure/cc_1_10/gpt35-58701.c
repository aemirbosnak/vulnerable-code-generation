//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLUMNS 10
#define MAX_CHARS_PER_COLUMN 50

typedef struct CSVData {
    char data[MAX_COLUMNS][MAX_CHARS_PER_COLUMN];
    int columnCount;
} CSVData;

CSVData* readCSVFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file: %s", filename);
        return NULL;
    }

    char line[MAX_COLUMNS * MAX_CHARS_PER_COLUMN];
    CSVData* csvData = (CSVData*) malloc(sizeof(CSVData));
    csvData->columnCount = 0;

    while (fgets(line, sizeof(line), file)) {
        char* column = strtok(line, ",");
        int i = 0;

        while (column != NULL) {
            if (csvData->columnCount == MAX_COLUMNS) {
                printf("Could not read file: more than %d columns are not supported", MAX_COLUMNS);
                return NULL;
            }

            strcpy(csvData->data[i++], column);
            csvData->columnCount++;
            column = strtok(NULL, ",");
        }
    }

    fclose(file);
    return csvData;
}

int main() {
    CSVData* csvData = readCSVFile("example.csv");

    if (csvData != NULL) {
        for (int i = 0; i < csvData->columnCount; i++) {
            printf("%s ", csvData->data[i]);
        }

        free(csvData);
    }

    return 0;
}