//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** data;
    int rows;
    int cols;
} CSVFile;

CSVFile* readCSV(const char* filename) {
    FILE* file = fopen(filename, "r");
    CSVFile* csvFile = (CSVFile*)malloc(sizeof(CSVFile));
    csvFile->data = NULL;
    csvFile->rows = 0;
    csvFile->cols = 0;

    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char* token = strtok(line, ",");
        int i = 0;
        while (token!= NULL) {
            if (i >= csvFile->cols) {
                csvFile->cols++;
            }
            if (csvFile->data == NULL) {
                csvFile->data = (char**)malloc(csvFile->cols * sizeof(char*));
            } else {
                csvFile->data = (char**)realloc(csvFile->data, csvFile->cols * sizeof(char*));
            }
            csvFile->data[i] = (char*)malloc((strlen(token) + 1) * sizeof(char));
            strcpy(csvFile->data[i], token);
            i++;
            token = strtok(NULL, ",");
        }
        csvFile->rows++;
    }

    csvFile->data = (char**)realloc(csvFile->data, csvFile->rows * csvFile->cols * sizeof(char*));

    fclose(file);

    return csvFile;
}

void printCSV(CSVFile* csvFile) {
    for (int i = 0; i < csvFile->rows; i++) {
        for (int j = 0; j < csvFile->cols; j++) {
            printf("%s ", csvFile->data[i * csvFile->cols + j]);
        }
        printf("\n");
    }
}

void freeCSV(CSVFile* csvFile) {
    for (int i = 0; i < csvFile->rows; i++) {
        for (int j = 0; j < csvFile->cols; j++) {
            free(csvFile->data[i * csvFile->cols + j]);
        }
    }
    free(csvFile->data);
    free(csvFile);
}

int main() {
    CSVFile* csvFile = readCSV("example.csv");
    printCSV(csvFile);
    freeCSV(csvFile);

    return 0;
}