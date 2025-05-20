//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_COUNT 256
#define DELIMITER ','

typedef struct {
    int fieldCount;
    char **fields;
} CsvRow;

typedef struct {
    int rowCount;
    CsvRow **rows;
} CsvFile;

CsvFile* readCsvFile(const char *filename) {
    CsvFile *csvFile = (CsvFile*) malloc(sizeof(CsvFile));
    csvFile->rowCount = 0;
    csvFile->rows = NULL;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file %s\n", filename);
        return csvFile;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (csvFile->rowCount == 0) {
            csvFile->rows = (CsvRow**) malloc(sizeof(CsvRow*) * 1);
        } else {
            csvFile->rows = (CsvRow**) realloc(csvFile->rows, sizeof(CsvRow*) * (csvFile->rowCount + 1));
        }

        CsvRow *row = (CsvRow*) malloc(sizeof(CsvRow));
        row->fieldCount = 0;
        row->fields = (char**) malloc(sizeof(char*) * MAX_FIELD_COUNT);

        char *token = strtok(line, ",");
        while (token) {
            char *field = (char*) malloc(sizeof(char) * strlen(token) + 1);
            strcpy(field, token);
            row->fields[row->fieldCount++] = field;
            token = strtok(NULL, ",");
        }

        csvFile->rows[csvFile->rowCount++] = row;
    }

    fclose(file);

    return csvFile;
}

void printCsvFile(CsvFile *csvFile) {
    printf("CsvFile:\n");
    for (int i = 0; i < csvFile->rowCount; i++) {
        CsvRow *row = csvFile->rows[i];
        printf("  CsvRow[%d]:\n", i);
        for (int j = 0; j < row->fieldCount; j++) {
            printf("    CsvField[%d]: %s\n", j, row->fields[j]);
        }
    }
}

void freeCsvFile(CsvFile *csvFile) {
    for (int i = 0; i < csvFile->rowCount; i++) {
        CsvRow *row = csvFile->rows[i];
        for (int j = 0; j < row->fieldCount; j++) {
            free(row->fields[j]);
        }
        free(row->fields);
        free(row);
    }
    free(csvFile->rows);
    free(csvFile);
}

int main() {
    CsvFile *csvFile = readCsvFile("example.csv");
    printCsvFile(csvFile);
    freeCsvFile(csvFile);
    return 0;
}