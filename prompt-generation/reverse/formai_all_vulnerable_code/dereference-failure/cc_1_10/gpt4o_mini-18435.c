//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

typedef struct {
    char **data;
    int columnCount;
} CSVRow;

typedef struct {
    CSVRow *rows;
    int rowCount;
} CSVData;

// Function declarations
CSVData* readCSV(const char *filename);
void freeCSVData(CSVData *csvData);
void printCSVData(CSVData *csvData);
void parseLine(char *line, CSVRow *row);
void freeCSVRow(CSVRow *row);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CSVData *csvData = readCSV(argv[1]);
    if (csvData == NULL) {
        fprintf(stderr, "Error reading CSV file.\n");
        return EXIT_FAILURE;
    }

    printCSVData(csvData);
    freeCSVData(csvData);

    return EXIT_SUCCESS;
}

// Function to read CSV from a file
CSVData* readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    CSVData *csvData = malloc(sizeof(CSVData));
    if (!csvData) {
        fclose(file);
        perror("Memory allocation failed");
        return NULL;
    }
    
    csvData->rows = NULL;
    csvData->rowCount = 0;
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        CSVRow *newRow = realloc(csvData->rows, sizeof(CSVRow) * (csvData->rowCount + 1));
        if (!newRow) {
            freeCSVData(csvData);
            fclose(file);
            perror("Memory allocation for rows failed");
            return NULL;
        }
        
        csvData->rows = newRow;
        csvData->rows[csvData->rowCount].data = calloc(MAX_COLUMNS, sizeof(char*));
        if (!csvData->rows[csvData->rowCount].data) {
            freeCSVData(csvData);
            fclose(file);
            perror("Memory allocation for columns failed");
            return NULL;
        }
        
        parseLine(line, &csvData->rows[csvData->rowCount]);
        csvData->rowCount++;
    }
    
    fclose(file);
    return csvData;
}

// Function to parse a line into a CSVRow
void parseLine(char *line, CSVRow *row) {
    char *token;
    int index = 0;
    
    token = strtok(line, ",");
    while (token != NULL) {
        row->data[index] = malloc(strlen(token) + 1);
        if (row->data[index] == NULL) {
            fprintf(stderr, "Memory allocation for token failed\n");
            return;
        }
        strcpy(row->data[index], token);
        index++;
        token = strtok(NULL, ",");
    }
    
    row->data[index] = NULL; // NULL-terminate the list of data
    row->columnCount = index;
}

// Function to print the CSV data
void printCSVData(CSVData *csvData) {
    for (int i = 0; i < csvData->rowCount; i++) {
        for (int j = 0; j < csvData->rows[i].columnCount; j++) {
            printf("%s", csvData->rows[i].data[j]);
            if (j < csvData->rows[i].columnCount - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

// Function to free memory allocated for CSVData
void freeCSVData(CSVData *csvData) {
    for (int i = 0; i < csvData->rowCount; i++) {
        freeCSVRow(&csvData->rows[i]);
    }
    free(csvData->rows);
    free(csvData);
}

void freeCSVRow(CSVRow *row) {
    for (int i = 0; i < row->columnCount; i++) {
        free(row->data[i]);
    }
    free(row->data);
}