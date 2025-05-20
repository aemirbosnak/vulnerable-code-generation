//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int fieldCount;
} CSVRow;

CSVRow* createRow(int fieldCount) {
    CSVRow *row = (CSVRow *)malloc(sizeof(CSVRow));
    if (!row) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    row->fields = (char **)malloc(sizeof(char *) * fieldCount);
    for (int i = 0; i < fieldCount; i++) {
        row->fields[i] = (char *)malloc(sizeof(char) * MAX_BUFFER);
    }
    row->fieldCount = fieldCount;
    return row;
}

void freeRow(CSVRow *row) {
    for (int i = 0; i < row->fieldCount; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int splitLine(char *line, CSVRow *row) {
    int fieldCount = 0;
    char *token = strtok(line, ",");
    while (token != NULL && fieldCount < MAX_FIELDS) {
        strcpy(row->fields[fieldCount], token);
        fieldCount++;
        token = strtok(NULL, ",");
    }
    return fieldCount;
}

void printRow(CSVRow *row) {
    for (int i = 0; i < row->fieldCount; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

void readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER];
    int rowCount = 0;
    while (fgets(buffer, MAX_BUFFER, file)) {
        CSVRow *row = createRow(MAX_FIELDS);
        int fieldsFilled = splitLine(buffer, row);
        printf("Row %d: ", ++rowCount);
        printRow(row);
        freeRow(row);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    readCSV(filename);

    return EXIT_SUCCESS;
}