//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(FILE *file) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, ",");
        if (csv->data == NULL) {
            csv->cols = 1;
            csv->data = malloc(sizeof(char *) * csv->cols);
            csv->data[0] = strdup(token);
        } else {
            if (csv->rows % csv->cols == 0) {
                csv->cols++;
                csv->data = realloc(csv->data, sizeof(char *) * csv->cols);
            }
            csv->data[csv->rows % csv->cols] = strdup(token);
        }
        csv->rows++;
    }

    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("example.csv", "r");
    CSV *csv = csv_open(file);
    csv_print(csv);
    csv_close(csv);

    return 0;
}