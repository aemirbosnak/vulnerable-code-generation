//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLUMNS 1000
#define MAX_ROWS 1000
#define MAX_LINE_SIZE 10000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_create(void) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_columns = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_columns; j++) {
            free(csv->data[i]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_read_file(CSV *csv, const char *filename) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *token;
    int i, j, k;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    csv->data = malloc(sizeof(char *) * MAX_ROWS);
    csv->num_rows = 0;
    csv->num_columns = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            csv->num_columns++;
            csv->data[csv->num_rows] = malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(csv->data[csv->num_rows], token);
            csv->num_rows++;
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);

    return 0;
}

void csv_print(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_columns; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    CSV *csv;
    csv = csv_create();
    csv_read_file(csv, "example.csv");
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}