//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char **data;
    int rows;
    int columns;
} CSV;

CSV *csv_read(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->columns = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;
        while (token!= NULL) {
            if (i >= csv->columns) {
                csv->columns++;
            }
            csv->data = realloc(csv->data, sizeof(char *) * csv->rows * csv->columns);
            csv->data[i * csv->rows + csv->rows - 1] = strdup(token);
            token = strtok(NULL, ",");
            i++;
        }
        csv->rows++;
    }

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->columns; j++) {
            printf("%s ", csv->data[i * csv->columns + j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    CSV *csv = csv_read(fp);
    csv_print(csv);

    fclose(fp);
    return 0;
}