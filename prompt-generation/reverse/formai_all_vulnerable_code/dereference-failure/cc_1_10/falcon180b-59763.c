//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create(void) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->rows; i++) {
        for (j = 0; j < csv->cols; j++) {
            free(csv->data[i]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_read(CSV *csv, FILE *fp) {
    char line[1024];
    char delimiter = ',';
    char *token;
    int i, j;

    csv->data = malloc(sizeof(char *) * 100);
    csv->rows = 0;
    csv->cols = 0;

    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, &delimiter);
        if (csv->cols == 0) {
            while (token!= NULL) {
                csv->cols++;
                token = strtok(NULL, &delimiter);
            }
        } else {
            while (token!= NULL) {
                csv->data[csv->rows] = malloc(sizeof(char) * (strlen(token) + 1));
                strcpy(csv->data[csv->rows], token);
                csv->rows++;
                token = strtok(NULL, &delimiter);
            }
        }
    }
}

void csv_print(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->rows; i++) {
        for (j = 0; j < csv->cols; j++) {
            printf("%s\t", csv->data[i]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    CSV *csv;

    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    csv = csv_create();
    csv_read(csv, fp);
    csv_print(csv);

    csv_destroy(csv);
    fclose(fp);

    return 0;
}