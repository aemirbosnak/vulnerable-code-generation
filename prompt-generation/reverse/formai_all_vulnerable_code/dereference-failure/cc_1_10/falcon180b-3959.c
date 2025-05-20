//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000
#define MAX_LINE 10000

typedef struct {
    char **row;
    int num_row;
    int num_col;
} CSV;

CSV* csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    CSV *csv = (CSV*) malloc(sizeof(CSV));
    csv->row = (char**) malloc(MAX_ROW * sizeof(char*));
    csv->num_row = 0;
    csv->num_col = 0;

    char line[MAX_LINE];
    char *token;
    int row = 0;
    while ((fgets(line, MAX_LINE, fp))!= NULL) {
        row++;
        token = strtok(line, ",");
        while (token!= NULL) {
            csv->num_col = (csv->num_col > row)? csv->num_col : row;
            csv->row[row] = (char*) malloc((strlen(token) + 1) * sizeof(char));
            strcpy(csv->row[row], token);
            row++;
            token = strtok(NULL, ",");
        }
    }

    csv->num_row = row;

    fclose(fp);

    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_row; i++) {
        free(csv->row[i]);
    }
    free(csv->row);
    free(csv);
}

int csv_get_num_row(CSV *csv) {
    return csv->num_row;
}

int csv_get_num_col(CSV *csv) {
    return csv->num_col;
}

char* csv_get_value(CSV *csv, int row, int col) {
    return csv->row[row - 1][col - 1];
}

int main() {
    CSV *csv = csv_open("example.csv");
    if (csv == NULL) {
        return 1;
    }

    int num_row = csv_get_num_row(csv);
    int num_col = csv_get_num_col(csv);

    for (int i = 0; i < num_row; i++) {
        for (int j = 0; j < num_col; j++) {
            printf("%s ", csv_get_value(csv, i + 1, j + 1));
        }
        printf("\n");
    }

    csv_close(csv);

    return 0;
}