//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_FIELDS 100

typedef struct {
    char **data;
    int rows;
    int cols;
} csv_file;

csv_file *csv_open(char *filename) {
    csv_file *csv = (csv_file *)malloc(sizeof(csv_file));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;
        while (token!= NULL) {
            i++;
            if (csv->cols <= i) {
                csv->cols++;
            }
            if (csv->data == NULL) {
                csv->data = (char **)malloc(csv->cols * sizeof(char *));
            } else {
                csv->data = (char **)realloc(csv->data, csv->cols * sizeof(char *));
            }
            csv->data[i-1] = strdup(token);
            token = strtok(NULL, ",");
        }
        csv->rows++;
    }
    fclose(fp);
    return csv;
}

void csv_print(csv_file *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s\t", csv->data[i*csv->cols+j]);
        }
        printf("\n");
    }
}

void csv_close(csv_file *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i*csv->cols+j]);
        }
    }
    free(csv->data);
    free(csv);
}

int main() {
    csv_file *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);
    return 0;
}