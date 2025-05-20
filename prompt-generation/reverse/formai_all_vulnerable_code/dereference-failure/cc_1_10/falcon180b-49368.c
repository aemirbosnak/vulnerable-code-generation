//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create(FILE *file) {
    CSV *csv = malloc(sizeof(CSV));
    csv->rows = 0;
    csv->cols = 0;
    csv->data = NULL;

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (csv->rows >= MAX_ROWS) {
            fprintf(stderr, "Error: Maximum number of rows exceeded.\n");
            exit(1);
        }

        char *token = strtok(line, ",");
        int cols = 0;

        while (token!= NULL) {
            if (cols >= MAX_COLS) {
                fprintf(stderr, "Error: Maximum number of columns exceeded.\n");
                exit(1);
            }

            csv->data[csv->rows] = realloc(csv->data[csv->rows], (cols + 1) * sizeof(char *));
            csv->data[csv->rows][cols] = strdup(token);

            token = strtok(NULL, ",");
            cols++;
        }

        csv->rows++;
    }

    csv->data[csv->rows] = NULL;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i <= csv->rows; i++) {
        for (int j = 0; j <= csv->cols; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i <= csv->rows; i++) {
        for (int j = 0; j <= csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("example.csv", "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        exit(1);
    }

    CSV *csv = csv_create(file);
    csv_print(csv);
    csv_destroy(csv);

    return 0;
}