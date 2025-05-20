//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char **fields;
    int num_fields;
} CsvLine;

typedef struct {
    CsvLine *lines;
    int num_lines;
} CsvFile;

CsvLine *parseCsvLine(char *line) {
    CsvLine *csvLine = (CsvLine *) malloc(sizeof(CsvLine));
    csvLine->num_fields = 0;
    csvLine->fields = NULL;
    char *token = strtok(line, ",");
    while (token != NULL) { // Split line by commas
        csvLine->num_fields++;
        csvLine->fields = (char **) realloc(csvLine->fields, csvLine->num_fields * sizeof(char *));
        csvLine->fields[csvLine->num_fields - 1] = token;
        token = strtok(NULL, ",");
    }
    return csvLine;
}

CsvFile *parseCsvFile(char *filename) {
    CsvFile *csvFile = (CsvFile *) malloc(sizeof(CsvFile));
    csvFile->num_lines = 0;
    csvFile->lines = NULL;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp)) { // Read file line by line
        char *newline = strchr(line, '\n');
        if (newline != NULL) {
            *newline = '\0'; // Remove newline character
        }
        csvFile->num_lines++;
        csvFile->lines = (CsvLine *) realloc(csvFile->lines, csvFile->num_lines * sizeof(CsvLine));
        csvFile->lines[csvFile->num_lines - 1] = *parseCsvLine(line); // Parse line and add to lines array
    }
    fclose(fp);
    return csvFile;
}

void freeCsvFile(CsvFile *csvFile) {
    for (int i = 0; i < csvFile->num_lines; i++) {
        CsvLine csvLine = csvFile->lines[i];
        for (int j = 0; j < csvLine.num_fields; j++) {
            free(csvLine.fields[j]);
        }
        free(csvLine.fields);
    }
    free(csvFile->lines);
    free(csvFile);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    CsvFile *csvFile = parseCsvFile(argv[1]);
    for (int i = 0; i < csvFile->num_lines; i++) {
        CsvLine csvLine = csvFile->lines[i];
        for (int j = 0; j < csvLine.num_fields; j++) {
            printf("%s ", csvLine.fields[j]);
        }
        printf("\n");
    }
    freeCsvFile(csvFile);
    return 0;
}