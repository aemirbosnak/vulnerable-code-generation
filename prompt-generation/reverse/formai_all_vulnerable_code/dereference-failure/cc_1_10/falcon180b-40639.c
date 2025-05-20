//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 100
#define MAX_COL 100
#define MAX_LINE 1000

typedef struct {
    char delimiter;
    int num_rows;
    int num_cols;
    char **data;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->delimiter = ',';
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->data = NULL;

    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, fp)!= NULL) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[--len] = '\0';
        }
        csv->num_rows++;

        char *token = strtok(line, ",");
        int num_cols = 0;
        while (token!= NULL) {
            num_cols++;
            token = strtok(NULL, ",");
        }
        csv->num_cols = num_cols;

        csv->data = realloc(csv->data, sizeof(char *) * csv->num_rows);
        csv->data[csv->num_rows - 1] = malloc(sizeof(char) * (num_cols + 1));
        strcpy(csv->data[csv->num_rows - 1], line);
    }

    fclose(fp);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}