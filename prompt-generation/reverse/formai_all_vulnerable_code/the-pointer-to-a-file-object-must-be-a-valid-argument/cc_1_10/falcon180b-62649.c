//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int rows;
    int cols;
    char **data;
} CSV;

CSV *csv_read(FILE *file) {
    CSV *csv = malloc(sizeof(CSV));
    csv->rows = 0;
    csv->cols = 0;
    csv->data = NULL;

    char line[1024];
    char *token = strtok(line, ",");

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (csv->data == NULL) {
            csv->cols = 1;
            csv->data = malloc(sizeof(char *));
        } else {
            if (csv->cols!= 0) {
                csv->cols++;
            }
            csv->data = realloc(csv->data, sizeof(char *) * csv->cols);
        }

        char *value = strdup(token);
        csv->data[csv->rows] = value;
        csv->rows++;

        token = strtok(NULL, ",");
    }

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s\t", csv->data[i]);
        }
        printf("\n");
    }
}

void csv_free(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    CSV *csv = csv_read(file);
    csv_print(csv);
    csv_free(csv);

    return 0;
}