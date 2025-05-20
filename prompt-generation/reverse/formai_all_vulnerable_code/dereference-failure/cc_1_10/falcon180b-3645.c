//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 100
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int rows;
    int columns;
} CSV;

CSV *csv_create(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->data = (char **) malloc(MAX_ROWS * sizeof(char *));
    csv->rows = 0;
    csv->columns = 0;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, file)!= NULL) {
        int i = 0;
        while (line[i]!= '\n' && line[i]!= '\r') {
            if (line[i] == ',') {
                csv->columns++;
            }
            i++;
        }

        if (csv->columns == 0) {
            csv->columns = 1;
        }

        csv->data[csv->rows] = (char *) malloc((csv->columns + 1) * sizeof(char));
        strcpy(csv->data[csv->rows], line);
        csv->rows++;
    }

    csv->columns = csv->columns > MAX_COLUMNS? MAX_COLUMNS : csv->columns;

    fclose(file);
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        printf("%s\n", csv->data[i]);
    }
}

int main() {
    CSV *csv = csv_create("example.csv");
    csv_print(csv);
    csv_destroy(csv);

    return 0;
}