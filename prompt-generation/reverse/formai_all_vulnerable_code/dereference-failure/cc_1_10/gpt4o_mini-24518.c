//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 100
#define MAX_ROWS 1000
#define MAX_LINE_LENGTH 1024

typedef struct {
    char **columns;
    int columnCount;
} CSVRow;

typedef struct {
    CSVRow *rows;
    int rowCount;
} CSVFile;

void freeCSV(CSVFile *csv) {
    for (int i = 0; i < csv->rowCount; i++) {
        free(csv->rows[i].columns);
    }
    free(csv->rows);
}

int countColumns(const char *line) {
    int count = 0;
    char *temp = strdup(line);
    char *token = strtok(temp, ",");
    while (token != NULL) {
        count++;
        token = strtok(NULL, ",");
    }
    free(temp);
    return count;
}

char **parseCSVLine(const char *line, int *columnCount) {
    char **columns = malloc(MAX_COLUMNS * sizeof(char *));
    char *temp = strdup(line);
    char *token = strtok(temp, ",");
    *columnCount = 0;

    while (token != NULL) {
        columns[*columnCount] = strdup(token);
        (*columnCount)++;
        token = strtok(NULL, ",");
    }
    free(temp);
    return columns;
}

CSVFile *readCSV(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filePath);
        return NULL;
    }

    CSVFile *csv = malloc(sizeof(CSVFile));
    csv->rows = malloc(MAX_ROWS * sizeof(CSVRow));
    csv->rowCount = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) && csv->rowCount < MAX_ROWS) {
        int columnCount = countColumns(line);
        csv->rows[csv->rowCount].columns = parseCSVLine(line, &columnCount);
        csv->rows[csv->rowCount].columnCount = columnCount;
        csv->rowCount++;
    }
    fclose(file);
    return csv;
}

void printCSV(const CSVFile *csv) {
    for (int i = 0; i < csv->rowCount; i++) {
        for (int j = 0; j < csv->rows[i].columnCount; j++) {
            printf("%s", csv->rows[i].columns[j]);
            if (j < csv->rows[i].columnCount - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CSVFile *csv = readCSV(argv[1]);
    if (!csv) {
        return EXIT_FAILURE;
    }
    
    printCSV(csv);
    freeCSV(csv);
    free(csv);

    return EXIT_SUCCESS;
}