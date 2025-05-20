//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_DATA {
    char ***data;
    int rows;
    int cols;
} CSV_DATA;

CSV_DATA *readCSVFile(char *filename) {
    CSV_DATA *csvData = malloc(sizeof(CSV_DATA));
    csvData->data = NULL;
    csvData->rows = 0;
    csvData->cols = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Read the number of rows and columns from the file
    fscanf(file, "%d, %d", &csvData->rows, &csvData->cols);

    // Allocate memory for the data
    csvData->data = malloc(csvData->rows * sizeof(char **));
    for (int r = 0; r < csvData->rows; r++) {
        csvData->data[r] = malloc(csvData->cols * sizeof(char *));
    }

    // Read the data from the file
    char line[MAX_ROWS];
    int i = 0;
    while (fgets(line, MAX_ROWS, file) != NULL) {
        char **data = csvData->data[i];
        char *p = line;
        int j = 0;
        while (*p) {
            data[j++] = strdup(*p);
            p++;
        }
        i++;
    }

    fclose(file);
    return csvData;
}

int main() {
    char *filename = "data.csv";
    CSV_DATA *csvData = readCSVFile(filename);

    // Print the data
    for (int r = 0; r < csvData->rows; r++) {
        for (int c = 0; c < csvData->cols; c++) {
            printf("%s ", csvData->data[r][c]);
        }
        printf("\n");
    }

    free(csvData->data);
    free(csvData);

    return 0;
}