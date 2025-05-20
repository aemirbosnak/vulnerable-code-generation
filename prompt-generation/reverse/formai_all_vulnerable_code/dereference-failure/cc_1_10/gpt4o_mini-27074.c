//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
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

void freeCSVData(CSVData *csv) {
    for (int i = 0; i < csv->rowCount; i++) {
        for (int j = 0; j < csv->rows[i].columnCount; j++) {
            free(csv->rows[i].data[j]);
        }
        free(csv->rows[i].data);
    }
    free(csv->rows);
}

CSVData* readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    CSVData *csv = malloc(sizeof(CSVData));
    csv->rowCount = 0;
    csv->rows = NULL;
    
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        csv->rows = realloc(csv->rows, sizeof(CSVRow) * (csv->rowCount + 1));
        CSVRow *row = &csv->rows[csv->rowCount];

        row->data = malloc(sizeof(char*) * MAX_COLUMNS);
        row->columnCount = 0;

        char *token = strtok(line, ",");
        while (token) {
            row->data[row->columnCount] = malloc(strlen(token) + 1);
            strcpy(row->data[row->columnCount], token);
            row->columnCount++;
            token = strtok(NULL, ",");
        }

        csv->rowCount++;
    }

    fclose(file);
    return csv;
}

void printCSVData(const CSVData *csv) {
    for (int i = 0; i < csv->rowCount; i++) {
        for (int j = 0; j < csv->rows[i].columnCount; j++) {
            printf("%s", csv->rows[i].data[j]);
            if (j < csv->rows[i].columnCount - 1)
                printf(", ");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CSVData *csv = readCSV(argv[1]);
    if (!csv) {
        return EXIT_FAILURE;
    }

    printCSVData(csv);
    freeCSVData(csv);
    free(csv);

    return EXIT_SUCCESS;
}