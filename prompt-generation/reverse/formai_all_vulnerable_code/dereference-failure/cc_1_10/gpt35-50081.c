//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 512
#define MAX_ROW_SIZE 100

typedef struct CSV {
    int numRows;
    int numCols;
    char **data;
} CSV;

CSV* readCSV(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return NULL;
    }

    CSV *csv = (CSV*)malloc(sizeof(CSV));
    char line[MAX_LINE_SIZE];
    char *tok;
    int row = 0, col = 0;

    fgets(line, MAX_LINE_SIZE, file);
    csv->numCols = 1;
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == ',') csv->numCols++;
    }

    csv->data = (char**)malloc(sizeof(char*) * MAX_ROW_SIZE);
    while (fgets(line, MAX_LINE_SIZE, file)) {
        csv->data[row] = (char*)malloc(sizeof(char) * MAX_LINE_SIZE);

        tok = strtok(line, ",");
        col = 0;
        while (tok != NULL) {
            strcpy(csv->data[row] + (col * MAX_LINE_SIZE), tok);
            col++;
            tok = strtok(NULL, ",");
        }

        row++;
        csv->numRows = row;
    }

    fclose(file);
    return csv;
}

void printCSV(CSV *csv) {
    for (int row = 0; row < csv->numRows; row++) {
        for (int col = 0; col < csv->numCols; col++) {
            printf("%s ", csv->data[row] + (col * MAX_LINE_SIZE));
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = readCSV("example.csv");
    if (!csv) return 1;
    printCSV(csv);

    for (int i = 0; i < csv->numRows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);

    return 0;
}