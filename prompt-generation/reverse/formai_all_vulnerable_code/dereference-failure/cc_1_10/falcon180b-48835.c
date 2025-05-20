//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 100
#define MAX_ROWS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV* csv_open(char *filename) {
    FILE *fp;
    char line[MAX_CELL_SIZE];
    char delimiter;
    CSV *csv;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    csv = (CSV*) malloc(sizeof(CSV));
    csv->data = (char**) malloc(MAX_ROWS * sizeof(char*));
    csv->num_rows = 0;
    csv->num_columns = 0;

    fgets(line, MAX_CELL_SIZE, fp);
    sscanf(line, "%c", &delimiter);

    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, delimiter);
        while (token!= NULL) {
            csv->num_columns++;
            csv->data[csv->num_rows] = (char*) malloc(MAX_CELL_SIZE);
            strcpy(csv->data[csv->num_rows], token);
            csv->num_rows++;
            token = strtok(NULL, delimiter);
        }
    }

    fclose(fp);

    return csv;
}

void csv_print(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_columns; j++) {
            printf("%s\t", csv->data[i]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    int i;

    for (i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv;

    csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}