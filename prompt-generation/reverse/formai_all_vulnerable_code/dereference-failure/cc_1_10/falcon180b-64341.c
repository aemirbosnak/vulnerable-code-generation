//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_read(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->rows = 0;
    csv->cols = 0;
    csv->data = NULL;

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        csv->rows++;
        int cols = 0;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }
        csv->cols = cols;
        break;
    }

    csv->data = malloc(csv->rows * sizeof(char *));
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = malloc(csv->cols * sizeof(char));
    }

    rewind(fp);
    int row = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int col = 0;
        while (token!= NULL) {
            strncpy(csv->data[row][col], token, strlen(token));
            col++;
            token = strtok(NULL, ",");
        }
        row++;
    }

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

void csv_free(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    CSV *csv = csv_read(fp);
    if (csv == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    csv_print(csv);

    csv_free(csv);
    fclose(fp);

    return 0;
}