//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 100
#define MAX_COL 100

typedef struct {
    char delimiter;
    char **data;
    int rows;
    int cols;
} CSV;

CSV* csv_create(char delimiter) {
    CSV *csv = (CSV*)malloc(sizeof(CSV));
    csv->delimiter = delimiter;
    csv->data = (char**)malloc(MAX_ROW * sizeof(char*));
    csv->rows = 0;
    csv->cols = 0;
    for (int i = 0; i < MAX_ROW; i++) {
        csv->data[i] = (char*)malloc(MAX_COL * sizeof(char));
    }
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_add_row(CSV *csv, char *row) {
    char *token = strtok(row, csv->delimiter);
    int cols = 0;
    while (token!= NULL) {
        csv->data[csv->rows][cols] = token;
        cols++;
        token = strtok(NULL, csv->delimiter);
    }
    csv->cols = cols;
    csv->rows++;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    char ch;
    CSV *csv = csv_create(',');
    int in_quotes = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\"') {
            in_quotes =!in_quotes;
        } else if (ch == '\n' &&!in_quotes) {
            csv_add_row(csv, "");
        } else if (ch == ',' &&!in_quotes) {
            char *token = strtok(NULL, ",");
            if (token!= NULL) {
                csv_add_row(csv, token);
            }
        }
    }
    fclose(fp);
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}