//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

typedef struct {
    char **data;
    int rowCount;
    int columnCount;
} CSVData;

CSVData *parseCSV(const char *filename);
void freeCSVData(CSVData *csvData);
void printCSVData(CSVData *csvData);
void getCSVValue(CSVData *csvData, int row, int column);
void replaceCSVValue(CSVData *csvData, int row, int column, const char *newValue);
void saveCSV(const char *filename, CSVData *csvData);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CSVData *csvData = parseCSV(argv[1]);
    if (!csvData) {
        fprintf(stderr, "Error reading CSV file.\n");
        return EXIT_FAILURE;
    }

    printCSVData(csvData);

    // Example usage of get and replace functions
    getCSVValue(csvData, 1, 2);
    replaceCSVValue(csvData, 1, 2, "NewValue");
    printf("After replacing value:\n");
    printCSVData(csvData);

    saveCSV("output.csv", csvData);
    
    freeCSVData(csvData);
    return EXIT_SUCCESS;
}

CSVData *parseCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    CSVData *csvData = malloc(sizeof(CSVData));
    csvData->data = malloc(MAX_LINE_LENGTH * sizeof(char *));
    for (int i = 0; i < MAX_LINE_LENGTH; i++) {
        csvData->data[i] = malloc(MAX_COLUMNS * sizeof(char));
    }
    
    csvData->rowCount = 0;
    csvData->columnCount = 0;
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        csvData->columnCount = 0;

        while (token) {
            strcpy(csvData->data[csvData->rowCount * MAX_COLUMNS + csvData->columnCount], token);
            token = strtok(NULL, ",");
            csvData->columnCount++;
        }
        csvData->rowCount++;
    }
    
    fclose(file);
    return csvData;
}

void freeCSVData(CSVData *csvData) {
    for (int i = 0; i < csvData->rowCount; i++) {
        free(csvData->data[i]);
    }
    free(csvData->data);
    free(csvData);
}

void printCSVData(CSVData *csvData) {
    for (int i = 0; i < csvData->rowCount; i++) {
        for (int j = 0; j < csvData->columnCount; j++) {
            printf("%s", csvData->data[i * MAX_COLUMNS + j]);
            if (j < csvData->columnCount - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

void getCSVValue(CSVData *csvData, int row, int column) {
    if (row < csvData->rowCount && column < csvData->columnCount) {
        printf("Value at row %d, column %d: %s\n", row, column, csvData->data[row * MAX_COLUMNS + column]);
    } else {
        printf("Invalid row or column index.\n");
    }
}

void replaceCSVValue(CSVData *csvData, int row, int column, const char *newValue) {
    if (row < csvData->rowCount && column < csvData->columnCount) {
        strcpy(csvData->data[row * MAX_COLUMNS + column], newValue);
        printf("Value at row %d, column %d replaced with: %s\n", row, column, newValue);
    } else {
        printf("Invalid row or column index.\n");
    }
}

void saveCSV(const char *filename, CSVData *csvData) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    for (int i = 0; i < csvData->rowCount; i++) {
        for (int j = 0; j < csvData->columnCount; j++) {
            fprintf(file, "%s", csvData->data[i * MAX_COLUMNS + j]);
            if (j < csvData->columnCount - 1) {
                fprintf(file, ",");
            }
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
    printf("Data saved to %s successfully.\n", filename);
}