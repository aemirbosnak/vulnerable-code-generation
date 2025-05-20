//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000
#define MAX_LINE_SIZE 1024

typedef struct {
    char **data;
    int row;
    int col;
} CSV;

void init_csv(CSV *csv) {
    csv->row = 0;
    csv->col = 0;
    csv->data = malloc(MAX_ROW * sizeof(char *));
    for (int i = 0; i < MAX_ROW; i++) {
        csv->data[i] = malloc(MAX_COL * sizeof(char));
    }
}

void free_csv(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
}

void read_csv_file(FILE *fp, CSV *csv) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        char *token = strtok(line, ",");
        int row = 0;
        int col = 0;
        while (token!= NULL) {
            if (row >= MAX_ROW || col >= MAX_COL) {
                printf("Exceeded maximum row or column limit.\n");
                exit(1);
            }
            csv->data[row][col] = token;
            col++;
            token = strtok(NULL, ",");
            row++;
        }
        csv->row++;
    }
}

void print_csv(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSV csv;
    init_csv(&csv);
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    read_csv_file(fp, &csv);
    fclose(fp);
    print_csv(&csv);
    free_csv(&csv);
    return 0;
}