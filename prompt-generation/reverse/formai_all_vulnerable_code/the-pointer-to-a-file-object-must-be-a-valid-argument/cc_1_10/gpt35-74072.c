//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_LINE_LENGTH 1024
#define MAX_CSV_SEPARATOR_LENGTH 2

// Data structure to hold CSV row
typedef struct CsvRowDef {
    char **data;
    int numColumns;
} CsvRow;

// Data structure to hold CSV file
typedef struct CsvFileDef {
    CsvRow *rows;
    int numRows;
    char *separator;
} CsvFile;

// Function to allocate memory for CSV row
CsvRow* createCsvRow(int numColumns) {
    CsvRow *row = (CsvRow*) malloc(sizeof(CsvRow));
    row->data = (char**) malloc(numColumns * sizeof(char*));
    row->numColumns = numColumns;
    return row;
}

// Function to free memory of CSV row
void freeCsvRow(CsvRow *row) {
    int i;
    for (i = 0; i < row->numColumns; i++) {
        free(row->data[i]);
    }
    free(row->data);
    free(row);
}

// Function to allocate memory for CSV file
CsvFile* createCsvFile(char *separator) {
    CsvFile *file = (CsvFile*) malloc(sizeof(CsvFile));
    file->rows = NULL;
    file->numRows = 0;
    file->separator = (char*) malloc(MAX_CSV_SEPARATOR_LENGTH * sizeof(char));
    strcpy(file->separator, separator);
    return file;
}

// Function to free memory of CSV file
void freeCsvFile(CsvFile *file) {
    int i;
    for (i = 0; i < file->numRows; i++) {
        freeCsvRow(file->rows + i);
    }
    free(file->rows);
    free(file->separator);
    free(file);
}

// Function to parse a CSV row from file buffer
CsvRow* parseCsvRow(char *buffer, char *separator) {
    char *token;
    int numColumns = 0, i;
    CsvRow *row = createCsvRow(0);
    token = strtok(buffer, separator);
    while (token != NULL) {
        row->data = (char**) realloc(row->data, (numColumns+1) * sizeof(char*));
        row->data[numColumns] = (char*) malloc(strlen(token) * sizeof(char));
        strcpy(row->data[numColumns], token);
        numColumns++;
        token = strtok(NULL, separator);
    }
    row->numColumns = numColumns;
    return row;
}

// Function to read CSV file from file system
CsvFile* readCsvFile(const char *filename, char *separator) {
    FILE *fp = fopen(filename, "r");
    char buffer[MAX_CSV_LINE_LENGTH];
    CsvFile *file = createCsvFile(separator);
    while (fgets(buffer, MAX_CSV_LINE_LENGTH, fp)) {
        file->rows = (CsvRow*) realloc(file->rows, (file->numRows+1) * sizeof(CsvRow));
        file->rows[file->numRows++] = *parseCsvRow(buffer, separator);
    }
    fclose(fp);
    return file;
}

// Function to print CSV row to console
void printCsvRow(CsvRow *row) {
    int i;
    for (i = 0; i < row->numColumns; i++) {
        printf("%s,", row->data[i]);
    }
    printf("\n");
}

// Function to print CSV file to console
void printCsvFile(CsvFile *file) {
    int i;
    for (i = 0; i < file->numRows; i++) {
        printCsvRow(file->rows + i);
    }
}

int main() {
    CsvFile *file = readCsvFile("data.csv", ",");
    printCsvFile(file);
    freeCsvFile(file);
    return 0;
}