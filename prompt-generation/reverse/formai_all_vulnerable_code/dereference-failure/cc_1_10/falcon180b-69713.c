//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100
#define MAX_ROWS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_columns = 0;

    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int num_tokens = 0;

        while (token!= NULL) {
            num_tokens++;
            token = strtok(NULL, ",");
        }

        if (csv->num_columns == 0) {
            csv->num_columns = num_tokens;
        } else if (num_tokens!= csv->num_columns) {
            fprintf(stderr, "Error: invalid number of columns in line '%s'\n", line);
            exit(1);
        }

        csv->data = realloc(csv->data, sizeof(char *) * csv->num_columns);
        csv->data[csv->num_rows] = malloc(sizeof(char) * strlen(line) + 1);
        strcpy(csv->data[csv->num_rows], line);
        csv->num_rows++;
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_open("data.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}