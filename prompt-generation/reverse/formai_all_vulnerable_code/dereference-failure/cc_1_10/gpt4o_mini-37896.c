//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int numFields;
} CSVRow;

typedef struct {
    CSVRow *rows;
    int numRows;
} CSVData;

CSVData* readCSV(const char *filename);
void freeCSVData(CSVData *data);
void printCSVData(const CSVData *data);

int main() {
    const char *filename = "data.csv"; // Change as necessary
    CSVData *data = readCSV(filename);
    
    if (data != NULL) {
        printCSVData(data);
        freeCSVData(data);
    } else {
        fprintf(stderr, "Error: Could not read CSV data.\n");
    }
    
    return 0;
}

CSVData* readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return NULL;
    }

    CSVData *data = (CSVData *)malloc(sizeof(CSVData));
    if (data == NULL) {
        perror("Unable to allocate memory for CSVData");
        fclose(file);
        return NULL;
    }

    data->numRows = 0;
    data->rows = NULL;
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        CSVRow row;
        row.fields = (char **)malloc(MAX_FIELDS * sizeof(char *));
        row.numFields = 0;

        char *token = strtok(line, ",");
        while (token != NULL && row.numFields < MAX_FIELDS) {
            row.fields[row.numFields] = strdup(token);
            row.numFields++;
            token = strtok(NULL, ",");
        }

        data->rows = (CSVRow *)realloc(data->rows, (data->numRows + 1) * sizeof(CSVRow));
        data->rows[data->numRows] = row;
        data->numRows++;
    }

    fclose(file);
    return data;
}

void freeCSVData(CSVData *data) {
    for (int i = 0; i < data->numRows; i++) {
        for (int j = 0; j < data->rows[i].numFields; j++) {
            free(data->rows[i].fields[j]);
        }
        free(data->rows[i].fields);
    }
    free(data->rows);
    free(data);
}

void printCSVData(const CSVData *data) {
    for (int i = 0; i < data->numRows; i++) {
        for (int j = 0; j < data->rows[i].numFields; j++) {
            printf("%s", data->rows[i].fields[j]);
            if (j < data->rows[i].numFields - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}