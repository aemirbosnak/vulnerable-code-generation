//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 100
#define MAX_ROWS 1000
#define DELIMITER ","

typedef struct {
    char **data;
    int rows;
    int columns;
} CSV;

CSV *csv_create(FILE *file) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->columns = 0;

    if (file == NULL) {
        fprintf(stderr, "Error: File is NULL\n");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    char *token;
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (csv->rows >= MAX_ROWS) {
            fprintf(stderr, "Error: Maximum number of rows exceeded\n");
            exit(EXIT_FAILURE);
        }

        int count = 0;
        token = strtok(line, DELIMITER);
        while (token!= NULL) {
            if (csv->columns >= MAX_COLUMNS) {
                fprintf(stderr, "Error: Maximum number of columns exceeded\n");
                exit(EXIT_FAILURE);
            }

            csv->data[csv->rows][count] = strdup(token);
            count++;

            token = strtok(NULL, DELIMITER);
        }

        csv->rows++;
        csv->columns = count;
    }

    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->columns; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->columns; j++) {
            printf("%s\t", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file\n");
        exit(EXIT_FAILURE);
    }

    CSV *csv = csv_create(file);
    csv_print(csv);

    csv_destroy(csv);

    return 0;
}