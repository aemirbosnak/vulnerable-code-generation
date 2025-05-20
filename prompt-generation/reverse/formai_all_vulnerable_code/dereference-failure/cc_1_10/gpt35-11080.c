//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} CsvData;

CsvData *readCsv(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Oopsie Daisy! There was a problem opening the file.\n");
        exit(1);
    }

    CsvData *csv = malloc(sizeof(CsvData));
    csv->rows = 0;
    csv->cols = 0;
    csv->data = NULL;

    char line[1024];

    while (fgets(line, 1024, file)) {
        csv->rows++;
        csv->data = realloc(csv->data, sizeof(char*) * csv->rows);
        csv->data[csv->rows - 1] = strdup(line);

        char *token = strtok(line, ",");
        int cols = 0;

        while (token != NULL) {
            cols++;
            token = strtok(NULL, ",");
        }

        if (cols > csv->cols) {
            csv->cols = cols;
        }
    }

    fclose(file);
    return csv;
}

int main() {
    CsvData *csv = readCsv("data.csv");

    printf("Whee! We have %d rows and %d columns.\n", csv->rows, csv->cols);

    for (int i = 0; i < csv->rows; i++) {
        char *line = csv->data[i];
        printf("Row %d: ", i+1);

        char *token = strtok(line, ",");
        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, ",");
        }

        printf("\n");
    }

    return 0;
}