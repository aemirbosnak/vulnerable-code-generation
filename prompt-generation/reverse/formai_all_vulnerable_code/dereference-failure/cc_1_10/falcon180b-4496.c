//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char **data;
    int row_count;
    int col_count;
} CSV;

CSV *csv_open(char *filename) {
    FILE *fp;
    char line[1024];
    CSV *csv;

    csv = (CSV *)malloc(sizeof(CSV));
    csv->data = NULL;
    csv->row_count = 0;
    csv->col_count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int col_count = 0;

        while (token!= NULL) {
            col_count++;
            token = strtok(NULL, ",");
        }

        if (col_count > csv->col_count) {
            csv->col_count = col_count;
        }

        csv->row_count++;
    }

    fclose(fp);

    csv->data = (char **)malloc(csv->row_count * sizeof(char *));
    for (int i = 0; i < csv->row_count; i++) {
        csv->data[i] = (char *)malloc(csv->col_count * sizeof(char));
    }

    fp = fopen(filename, "r");
    int row = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int col = 0;

        while (token!= NULL) {
            strcpy(csv->data[row], token);
            token = strtok(NULL, ",");
            col++;
        }

        row++;
    }

    fclose(fp);

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->row_count; i++) {
        for (int j = 0; j < csv->col_count; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->row_count; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}