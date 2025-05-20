//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ROWS 1000
#define MAX_COLUMNS 1000

typedef struct {
    char **data;
    int rows;
    int columns;
} CSV;

CSV *csv_create(FILE *fp) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    csv->rows = 0;
    csv->columns = 0;

    char line[MAX_LINE_LENGTH];
    char *token = NULL;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int i = 0;
        while ((token = strtok(line, ","))!= NULL) {
            csv->data[csv->rows] = (char *)malloc(strlen(token) + 1);
            strcpy(csv->data[csv->rows], token);
            csv->columns++;
            csv->rows++;
            i++;
        }
    }

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->columns; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main(int argc, char **argv) {
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    CSV *csv = csv_create(fp);
    csv_print(csv);
    csv_destroy(csv);

    fclose(fp);
    return 0;
}